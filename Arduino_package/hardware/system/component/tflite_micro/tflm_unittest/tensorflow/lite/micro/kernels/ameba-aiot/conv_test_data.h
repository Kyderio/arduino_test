/* Copyright 2021 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef TENSORFLOW_LITE_MICRO_KERNELS_CONV_TEST_DATA_H_
#define TENSORFLOW_LITE_MICRO_KERNELS_CONV_TEST_DATA_H_

#include "tensorflow/lite/c/common.h"

namespace tflite {
// Kernel Conv Test Cases: FloatFilter4x2x5x1ShouldMatchGolden
extern const float kConvInput1x2x257x1Data[];
extern int kConvInput1x2x257x1Shape[];
extern const float kFilter4x2x5x1Data[];
extern int kFilter4x2x5x1Shape[];
extern const float kBias4Data[];
extern int kBias4Shape[];
extern const float kConvGoldenOutput1x1x85x4Data[];
extern int kConvGoldenOutput1x1x85x4Shape[];

}  // namespace tflite

#endif  // TENSORFLOW_LITE_MICRO_KERNELS_CONV_TEST_DATA_H_
