/*
 * Copyright (C) 2010 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef AMEBA_COMPONENT_AUDIO_AUDIO_EFFECT_SW_ALGORITHM_WRAPPER_BUNDLE_H
#define AMEBA_COMPONENT_AUDIO_AUDIO_EFFECT_SW_ALGORITHM_WRAPPER_BUNDLE_H

#include "effect_equalizer.h"
#include <LVM.h>
#include <limits.h>

#if __cplusplus
extern "C" {
#endif

#define TENBAND_NUMBANDS           10
#define MAX_NUM_BANDS              10
#define MAX_CALL_SIZE              256
#define LVM_MAX_SESSIONS           32
#define LVM_UNUSED_SESSION         INT_MAX
#define BASS_BOOST_CUP_LOAD_ARM9E  150    // Expressed in 0.1 MIPS
#define VIRTUALIZER_CUP_LOAD_ARM9E 120    // Expressed in 0.1 MIPS
#define EQUALIZER_CUP_LOAD_ARM9E   220    // Expressed in 0.1 MIPS
#define VOLUME_CUP_LOAD_ARM9E      0      // Expressed in 0.1 MIPS
#define BUNDLE_MEM_USAGE           25     // Expressed in kB
//#define LVM_PCM

	typedef enum {
		LVM_EQUALIZER
	} lvm_effect_en;

// Preset configuration.
	struct PresetConfig {
		const char *name;
	};

	struct BundledEffectContext {
		LVM_Handle_t                    hInstance;                /* Instance handle */
		int                             SessionNo;                /* Current session number */
		int                             SessionId;                /* Current session id */
		bool                            bVolumeEnabled;           /* Flag for Volume */
		bool                            bEqualizerEnabled;        /* Flag for EQ */
		int                             NumberEffectsEnabled;     /* Effects in this session */
		int                             NumberEffectsCalled;      /* Effects called so far */
		bool                            firstVolume;              /* No smoothing on first Vol change */
		int                             CurPreset;                /* Current preset being used */
		int                             VirtStrengthSaved;        /* Conversion between Get/Set */
		int                             levelSaved;               /* for when mute is set, level must be saved */
		int                             positionSaved;
		bool                            bMuteEnabled;             /* Must store as mute = -96dB level */
		bool                            bStereoPositionEnabled;
		LVM_Fs_en                       SampleRate;
		int                             SamplesPerSecond;
		int                             SamplesToExitCountEq;
		int                             SamplesToExitCountBb;
		int                             SamplesToExitCountVirt;
		LVM_INT16                       *workBuffer;
		int                             frameCount;
		int32_t                         bandGaindB[TENBAND_NUMBANDS];
		int                             volume;
		int32_t                         bandFreq[TENBAND_NUMBANDS];
		int32_t                         bandQfactor[TENBAND_NUMBANDS];
#ifdef LVM_PCM
		FILE                            *PcmInPtr;
		FILE                            *PcmOutPtr;
#endif
	};

	struct SessionContext {
		bool                            bBundledEffectsEnabled;
		bool                            bVolumeInstantiated;
		bool                            bEqualizerInstantiated;
		bool                            bBassInstantiated;
		bool                            bVirtualizerInstantiated;
		BundledEffectContext            *pBundledContext;
	};

	struct EffectContext {
		const struct effect_interface_s *itfe;
		effect_config_t                 config;
		lvm_effect_en                   EffectType;
		BundledEffectContext            *pBundledContext;
	};

	typedef enum {
		VOLUME_PARAM_LEVEL,                       // type SLmillibel = typedef SLuint16 (set & get)
		VOLUME_PARAM_MAXLEVEL,                    // type SLmillibel = typedef SLuint16 (get)
		VOLUME_PARAM_MUTE,                        // type SLboolean  = typedef SLuint32 (set & get)
		VOLUME_PARAM_ENABLESTEREOPOSITION,        // type SLboolean  = typedef SLuint32 (set & get)
		VOLUME_PARAM_STEREOPOSITION,              // type SLpermille = typedef SLuint16 (set & get)
	} t_volume_params;

	static const int PRESET_CUSTOM = -1;

	//10 bands
	/*
	31-62Hz
	62-125Hz
	125-250Hz
	250-500Hz
	500-1000Hz
	1K-2KHz
	2K-4KHz
	4K-8KHz
	8KHz-16KHz
	16KHz-20KHz
	*/
	static const uint32_t bandFreqRange[TENBAND_NUMBANDS][2] = {
		/*{30000, 120000},
		{120001, 460000},
		{460001, 1800000},
		{1800001, 7000000},
		{7000001, 20000000}*/
		{31000, 62000},
		{62000, 125000},
		{125000, 250000},
		{250000, 500000},
		{500000, 1000000},
		{1000000, 2000000},
		{2000000, 4000000},
		{4000000, 8000000},
		{8000000, 16000000},
		{16000000, 20000000}
	};

//Note: If these frequencies change, please update LimitLevel values accordingly.
	static const LVM_UINT16  EQNB_10bandPresetsFrequencies[] = {
		47,           /* Frequencies in Hz */
		94,
		188,
		375,
		750,
		1500,
		3000,
		6000,
		12000,
		18000
	};

	static const LVM_UINT16 EQNB_10bandPresetsQFactors[] = {
		96,               /* Q factor multiplied by 100 */
		96,
		96,
		96,
		96,
		96,
		96,
		96,
		96,
		96
	};

	static const LVM_INT16 EQNB_10bandSoftPresets[] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      /* Normal Preset */
		5, 3, -2, 4, 4, 5, 3, -2, 4, 4,     /* Classical Preset */
		6, 0, 2, 4, 1, 6, 0, 2, 4, 1,     /* Dance Preset */
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      /* Flat Preset */
		3, 0, 0, 2, -1, 3, 0, 0, 2, -1,    /* Folk Preset */
		4, 1, 9, 3, 0, 4, 1, 9, 3, 0,    /* Heavy Metal Preset */
		5, 3, 0, 1, 3, 5, 3, 0, 1, 3,     /* Hip Hop Preset */
		4, 2, -2, 2, 5, 4, 2, -2, 2, 5,    /* Jazz Preset */
		-1, 2, 5, 1, -2, -1, 2, 5, 1, -2,    /* Pop Preset */
		5, 3, -1, 3, 5, 5, 3, -1, 3, 5
	};    /* Rock Preset */

	static const PresetConfig gEqualizerPresets[] = {
		{"Normal"},
		{"Classical"},
		{"Dance"},
		{"Flat"},
		{"Folk"},
		{"Heavy Metal"},
		{"Hip Hop"},
		{"Jazz"},
		{"Pop"},
		{"Rock"}
	};

	static const float LimitLevel_bandEnergyCoefficient[TENBAND_NUMBANDS] = {
		7.56, 9.69, 9.59, 7.37, 2.88, 5.0, 5.0, 5.0, 5.0, 5.0
	};

	static const float LimitLevel_bandEnergyCrossCoefficient[TENBAND_NUMBANDS - 1] = {
		126.0, 115.0, 125.0, 104.0, 100.0, 100.0, 100.0, 100.0, 100.0
	};
#if __cplusplus
}  // extern "C"
#endif


#endif
