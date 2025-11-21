/*
 * Copyright (c) 2021 Realtek, LLC.
 * All rights reserved.
 *
 * Licensed under the Realtek License, Version 1.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License from Realtek
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef AMEBA_FWK_MEDIA_PLAYBACK_RTCODEC_CODEC_SW_MEDIA_CODEC_UTILS_H
#define AMEBA_FWK_MEDIA_PLAYBACK_RTCODEC_CODEC_SW_MEDIA_CODEC_UTILS_H

#include <stdint.h>

#define CODEC_AUDIO_MAXCHANNELS 16
#define CODEC_MAX_STRINGNAME_SIZE 128

typedef enum DecoderStatus {
	DECODER_OK,
	DECODER_ERROR,
	DECODER_FORMATE_CHANGE,
	DECODER_EOS,
	DECODER_INPUT_UNDERFLOW,
	DECODER_INPUT_OVERFLOW
} DecoderStatus;

typedef enum BufferFlag {
	CODEC_BUFFERFLAG_EOS = 0x00000001,
	CODEC_BUFFERFLAG_ENDOFFRAME = 0x00000010,
	CODEC_BUFFERFLAG_CODECCONFIG = 0x00000080
} BufferFlag;

typedef struct CODEC_BUFFERHEADERTYPE {
	uint32_t size;
	uint8_t *p_buffer;
	uint32_t alloc_len;
	uint32_t fill_len;
	uint32_t offset;
	uint32_t flags;
	int64_t time_stamp;
} CODEC_BUFFERHEADERTYPE;

typedef enum CODEC_INDEXTYPE {
	CODEC_IndexParamStandardComponentRole = 0x01000000,
	CODEC_IndexParamPortDefinition,
	CODEC_IndexParamAudioPcm,
	CODEC_IndexParamAudioMp3,
	CODEC_IndexParamAudioAac,
} CODEC_INDEXTYPE;

/** PCM params */
typedef enum CODEC_NUMERICALDATATYPE {
	CODEC_NumericalDataSigned, /**< signed data */
	CODEC_NumericalDataUnsigned, /**< unsigned data */
	CODEC_NumercialDataMax = 0x7FFFFFFF
} CODEC_NUMERICALDATATYPE;

typedef enum CODEC_AUDIO_CHANNELMODETYPE {
	CODEC_AUDIO_ChannelModeStereo = 0,
	CODEC_AUDIO_ChannelModeJointStereo,
	CODEC_AUDIO_ChannelModeDual,
	CODEC_AUDIO_ChannelModeMono,
	CODEC_AUDIO_ChannelModeKhronosExtensions = 0x6F000000,
	CODEC_AUDIO_ChannelModeVendorStartUnused = 0x7F000000,
	CODEC_AUDIO_ChannelModeMax = 0x7FFFFFFF
} CODEC_AUDIO_CHANNELMODETYPE;

typedef enum CODEC_ENDIANTYPE {
	CODEC_EndianBig,
	CODEC_EndianLittle,
	CODEC_EndianMax = 0x7FFFFFFF
} CODEC_ENDIANTYPE;

typedef enum CODEC_AUDIO_CHANNELTYPE {
	CODEC_AUDIO_ChannelNone = 0x0,
	CODEC_AUDIO_ChannelLF   = 0x1,
	CODEC_AUDIO_ChannelRF   = 0x2,
	CODEC_AUDIO_ChannelCF   = 0x3,
	CODEC_AUDIO_ChannelLS   = 0x4,
	CODEC_AUDIO_ChannelRS   = 0x5,
	CODEC_AUDIO_ChannelLFE  = 0x6,
	CODEC_AUDIO_ChannelCS   = 0x7,
	CODEC_AUDIO_ChannelLR   = 0x8,
	CODEC_AUDIO_ChannelRR   = 0x9,
	CODEC_AUDIO_ChannelKhronosExtensions = 0x6F000000,
	CODEC_AUDIO_ChannelVendorStartUnused = 0x7F000000,
	CODEC_AUDIO_ChannelMax  = 0x7FFFFFFF
} CODEC_AUDIO_CHANNELTYPE;

typedef enum CODEC_AUDIO_PCMMODETYPE {
	CODEC_AUDIO_PCMModeLinear = 0,
	CODEC_AUDIO_PCMModeALaw,
	CODEC_AUDIO_PCMModeMULaw,
	CODEC_AUDIO_PCMModeKhronosExtensions = 0x6F000000,
	CODEC_AUDIO_PCMModeVendorStartUnused = 0x7F000000,
	CODEC_AUDIO_PCMModeMax = 0x7FFFFFFF
} CODEC_AUDIO_PCMMODETYPE;

typedef struct CODEC_AUDIO_PARAM_PCMMODETYPE {
	uint32_t nChannels;
	CODEC_NUMERICALDATATYPE eNumData;
	CODEC_ENDIANTYPE eEndian;
	bool bInterleaved;
	uint32_t nBitPerSample;
	uint32_t nSamplingRate;
	CODEC_AUDIO_PCMMODETYPE ePCMMode;
	CODEC_AUDIO_CHANNELTYPE eChannelMapping[CODEC_AUDIO_MAXCHANNELS];
} CODEC_AUDIO_PARAM_PCMMODETYPE;

/** MP3 params */
typedef enum CODEC_AUDIO_MP3STREAMFORMATTYPE {
	CODEC_AUDIO_MP3StreamFormatMP1Layer3 = 0,
	CODEC_AUDIO_MP3StreamFormatMP2Layer3,
	CODEC_AUDIO_MP3StreamFormatMP2_5Layer3,
	CODEC_AUDIO_MP3StreamFormatKhronosExtensions = 0x6F000000,
	CODEC_AUDIO_MP3StreamFormatVendorStartUnused = 0x7F000000,
	CODEC_AUDIO_MP3StreamFormatMax = 0x7FFFFFFF
} CODEC_AUDIO_MP3STREAMFORMATTYPE;

typedef struct CODEC_AUDIO_PARAM_MP3TYPE {
	uint32_t nChannels;
	uint32_t nBitRate;
	uint32_t nSampleRate;
	uint32_t nAudioBandWidth;
	CODEC_AUDIO_CHANNELMODETYPE eChannelMode;
	CODEC_AUDIO_MP3STREAMFORMATTYPE eFormat;
} CODEC_AUDIO_PARAM_MP3TYPE;

typedef enum CODEC_AUDIO_AACPROFILETYPE {
	CODEC_AUDIO_AACObjectNull = 0,
	CODEC_AUDIO_AACObjectMain = 1,
	CODEC_AUDIO_AACObjectLC,
	CODEC_AUDIO_AACObjectSSR,
	CODEC_AUDIO_AACObjectLTP,
	CODEC_AUDIO_AACObjectHE,
	CODEC_AUDIO_AACObjectScalable,
	CODEC_AUDIO_AACObjectERLC = 17,
	CODEC_AUDIO_AACObjectLD = 23,
	CODEC_AUDIO_AACObjectHE_PS = 29,
	CODEC_AUDIO_AACObjectKhronosExtensions = 0x6F000000,
	CODEC_AUDIO_AACObjectVendorStartUnused = 0x7F000000,
	CODEC_AUDIO_AACObjectMax = 0x7FFFFFFF
} CODEC_AUDIO_AACPROFILETYPE;

typedef enum CODEC_AUDIO_AACSTREAMFORMATTYPE {
	CODEC_AUDIO_AACStreamFormatMP2ADTS = 0,
	CODEC_AUDIO_AACStreamFormatMP4ADTS,
	CODEC_AUDIO_AACStreamFormatMP4LOAS,
	CODEC_AUDIO_AACStreamFormatMP4LATM,
	CODEC_AUDIO_AACStreamFormatADIF,
	CODEC_AUDIO_AACStreamFormatMP4FF,
	CODEC_AUDIO_AACStreamFormatRAW,
	CODEC_AUDIO_AACStreamFormatKhronosExtensions = 0x6F000000,
	CODEC_AUDIO_AACStreamFormatVendorStartUnused = 0x7F000000,
	CODEC_AUDIO_AACStreamFormatMax = 0x7FFFFFFF
} CODEC_AUDIO_AACSTREAMFORMATTYPE;

/** AAC params */
typedef struct CODEC_AUDIO_PARAM_AACPROFILETYPE {
	uint32_t nChannels;
	uint32_t nSampleRate;
	uint32_t nBitRate;
	uint32_t nAudioBandWidth;
	uint32_t nFrameLength;
	uint32_t nAACtools;
	uint32_t nAACERtools;
	CODEC_AUDIO_AACPROFILETYPE eAACProfile;
	CODEC_AUDIO_AACSTREAMFORMATTYPE eAACStreamFormat;
	CODEC_AUDIO_CHANNELMODETYPE eChannelMode;
} CODEC_AUDIO_PARAM_AACPROFILETYPE;

typedef enum CODEC_AUDIO_CODINGTYPE {
	CODEC_AUDIO_CodingUnused = 0,  /**< Placeholder value when coding is N/A  */
	CODEC_AUDIO_CodingAutoDetect,  /**< auto detection of audio format */
	CODEC_AUDIO_CodingPCM,         /**< Any variant of PCM coding */
	CODEC_AUDIO_CodingADPCM,       /**< Any variant of ADPCM encoded data */
	CODEC_AUDIO_CodingAMR,         /**< Any variant of AMR encoded data */
	CODEC_AUDIO_CodingGSMFR,       /**< Any variant of GSM fullrate (i.e. GSM610) */
	CODEC_AUDIO_CodingGSMEFR,      /**< Any variant of GSM Enhanced Fullrate encoded data*/
	CODEC_AUDIO_CodingGSMHR,       /**< Any variant of GSM Halfrate encoded data */
	CODEC_AUDIO_CodingPDCFR,       /**< Any variant of PDC Fullrate encoded data */
	CODEC_AUDIO_CodingPDCEFR,      /**< Any variant of PDC Enhanced Fullrate encoded data */
	CODEC_AUDIO_CodingPDCHR,       /**< Any variant of PDC Halfrate encoded data */
	CODEC_AUDIO_CodingTDMAFR,      /**< Any variant of TDMA Fullrate encoded data (TIA/EIA-136-420) */
	CODEC_AUDIO_CodingTDMAEFR,     /**< Any variant of TDMA Enhanced Fullrate encoded data (TIA/EIA-136-410) */
	CODEC_AUDIO_CodingQCELP8,      /**< Any variant of QCELP 8kbps encoded data */
	CODEC_AUDIO_CodingQCELP13,     /**< Any variant of QCELP 13kbps encoded data */
	CODEC_AUDIO_CodingEVRC,        /**< Any variant of EVRC encoded data */
	CODEC_AUDIO_CodingSMV,         /**< Any variant of SMV encoded data */
	CODEC_AUDIO_CodingG711,        /**< Any variant of G.711 encoded data */
	CODEC_AUDIO_CodingG723,        /**< Any variant of G.723 dot 1 encoded data */
	CODEC_AUDIO_CodingG726,        /**< Any variant of G.726 encoded data */
	CODEC_AUDIO_CodingG729,        /**< Any variant of G.729 encoded data */
	CODEC_AUDIO_CodingAAC,         /**< Any variant of AAC encoded data */
	CODEC_AUDIO_CodingMP3,         /**< Any variant of MP3 encoded data */
	CODEC_AUDIO_CodingSBC,         /**< Any variant of SBC encoded data */
	CODEC_AUDIO_CodingVORBIS,      /**< Any variant of VORBIS encoded data */
	CODEC_AUDIO_CodingWMA,         /**< Any variant of WMA encoded data */
	CODEC_AUDIO_CodingRA,          /**< Any variant of RA encoded data */
	CODEC_AUDIO_CodingMIDI,        /**< Any variant of MIDI encoded data */
	CODEC_AUDIO_CodingKhronosExtensions = 0x6F000000, /**< Reserved region for introducing Khronos Standard Extensions */
	CODEC_AUDIO_CodingVendorStartUnused = 0x7F000000, /**< Reserved region for introducing Vendor Extensions */
	CODEC_AUDIO_CodingMax = 0x7FFFFFFF
} CODEC_AUDIO_CODINGTYPE;

typedef struct CODEC_AUDIO_PORTDEFINITIONTYPE {
	char *cMIMEType;
	void *pNativeRender;
	bool bFlagErrorConcealment;
	CODEC_AUDIO_CODINGTYPE eEncoding;
} CODEC_AUDIO_PORTDEFINITIONTYPE;

typedef enum CODEC_PORTDOMAINTYPE {
	CODEC_PortDomainAudio,
	CODEC_PortDomainVideo,
	CODEC_PortDomainImage,
	CODEC_PortDomainOther,
	CODEC_PortDomainKhronosExtensions = 0x6F000000,
	CODEC_PortDomainVendorStartUnused = 0x7F000000,
	CODEC_PortDomainMax = 0x7ffffff
} CODEC_PORTDOMAINTYPE;

typedef struct CODEC_PARAM_PORTDEFINITIONTYPE {
	uint32_t nPortIndex;
	uint32_t nBufferSize;
	bool bEnabled;
	bool bPopulated;
	CODEC_PORTDOMAINTYPE eDomain;
	union {
		CODEC_AUDIO_PORTDEFINITIONTYPE audio;
	} format;
	bool bBuffersContiguous;
	uint32_t nBufferAlignment;
} CODEC_PARAM_PORTDEFINITIONTYPE;

#endif /* AMEBA_FWK_MEDIA_PLAYBACK_RTCODEC_CODEC_SW_MEDIA_CODEC_UTILS_H */
