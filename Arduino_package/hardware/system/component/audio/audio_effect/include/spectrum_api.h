#ifndef AMEBA_COMPONENT_AUDIO_AUDIO_EFFECT_INCLUDE_AUDIO_SPECTRUM_H
#define AMEBA_COMPONENT_AUDIO_AUDIO_EFFECT_INCLUDE_AUDIO_SPECTRUM_H

#ifdef __cplusplus
extern "C" {
#endif

// #include "arm_math.h"
// #include "arm_common_tables.h"
// #include "arm_const_structs.h"
// #define M_PI 3.14159265358979323846

// #define FFT_INBUF_MAX  3072  //1024*3
// #define FFT_SIZE 1024

typedef struct
{
    int     fft_size ;
} spectrum_config_t;

//===============================================================================================================================
// Function: AirHarmony_SpectrumCreate
// Describe: Spectrum Analyzer create & initialize & start
// input:
//  *spectrum_config:  spectrum_config input setting
//  sample_rate: sample rate
//  sys_frame_size: frame size
//  n_ch: only support 1 now.
// return :
//  *p_Spectrum_mem: Spectrum Analyzer malloc memory pointer
//================================================================================================================================
void *AirHarmony_SpectrumCreate(spectrum_config_t *spectrum_config, float sample_rate, int sys_frame_size,int n_ch);

//===============================================================================================================================
// Function: AirHarmony_SpectrumProcess
// Describe: Spectrum Analyzer main process
// input:
//  *p_Spectrum_mem: Spectrum Analyzer malloc memory pointer
//  *input  : PCM input buffer
// return   : User can call AirHarmony_SpectrumGetData() function to get the output data of Spectrum Analyzer
//  none
//===============================================================================================================================
void AirHarmony_SpectrumProcess(void *p_Spectrum_mem,float* input);

//===============================================================================================================================
// Function: AirHarmony_SpectrumGetData
// Describe: provide the user to get the data of Spectrum Analyzer
// input:
//  *pParametricEq_Mem: Spectrum Analyzer memory pointer the data of Spectrum Analyzer
// output:
//   user set the output memory pointer,and get 10 spectrum data for Band_num =10 , and 20 spectrum data for Band_num =20
// return :
//  none
//===============================================================================================================================
void AirHarmony_SpectrumGetData(void *p_Spectrum_mem,float* fft_output);

//===============================================================================================================================
// Function: AirHarmony_SpectrumRelease
// Describe: Spectrum Analyzer close & release memory
// input:
//  *pSpectrum_Mem: Spectrum Analyzer memory pointer
// return :
//  none
//===============================================================================================================================
void AirHarmony_SpectrumRelease(void *pSpectrum_Mem);

//===============================================================================================================================
// Function: AirHarmony_SpectrumGetVersion
// Describe: Get version
// input:
//    none
// return : ex. 0x10000000  ==> version V1.0.0.0
//===============================================================================================================================
unsigned int AirHarmony_SpectrumGetVersion(void);

#ifdef __cplusplus
}
#endif


#endif



