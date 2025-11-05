#include "stdio.h"
#include <stdlib.h>

#define FREQ_RESPONSE_N   4096   // frequency response resolution, user can adjust it
#define BIQUAD_NUN 15  // BU spec , the max biquad number is 15

#define PI 3.14159265358979323846

typedef enum {
    LOWPASS,
    HIGHPASS,
    BANDPASS,
    PEAKING,
    NOTCH,
    LOW_SHELF,
    HIGH_SHELF,
} FilterType;

typedef struct
{
    int enable ;
    int filter_type;
    float fc;             //
    float q ;             //
    float gain;           //
} parametric_eq_t;

typedef struct
{
    float b0;
    float b1;
    float b2;             //
    float a1 ;             //
    float a2;           //
} BiquadCoeff_t;


//================================================================================
// Function: ParametricEQ_init
// Describe: Parametric equalizer initialize
// input:
//    para_eq: the parametric eq parameter setting
// return : NONE
//================================================================================
void ParametricEQ_init(parametric_eq_t* para_eq);
//================================================================================
// Function: ParametricEQ_ComputeBiqaudCoeff
// Describe: compute the filter biqaud coefficient from parametric eq parameter setting
// input:
//    parametric_eq: the parametric eq parameter setting
//    sample_rate  : the sample rate for the processed the auido signal
// output :
//    biquadCoeff  :　the biquad coefficient of every parametric eq parameter setting by enabled parametric eq
// return : the number of enabled parametric eq
//================================================================================
int ParametricEQ_ComputeBiqaudCoeff(parametric_eq_t *parametric_eq ,BiquadCoeff_t *biquadCoeff,int sample_rate);
//================================================================================
// Function: ParametricEQ_FrequencyResponse
// Describe: compute the overall amplitude frequency response of enabledeq filter by using the biquad coefficient
// input:
//    coeffs     : the biquad coefficient
//    frequency  : the frequency point buffer, the more point have more frequency resolution
//    numPoints  : the number of frequency point resolution
//    sample_rate  : the sample rate for the processed the auido signal
//    parametric_eq_number  : the number of enabled parametric eq

// output :
//    magnitude  :　overall amplitude frequency response
// return : NONE
//================================================================================
void ParametricEQ_FrequencyResponse(BiquadCoeff_t * coeffs, float* frequency, float* magnitude, int numPoints, float sampleRate,int parametric_eq_number);