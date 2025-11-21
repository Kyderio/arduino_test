/* Copyright 2024 The TensorFlow Authors. All Rights Reserved.

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

// An ultra-lightweight testing framework designed for use with microcontroller
// applications. This is designed to be usable even
// when no standard C or C++ libraries are available, and without any dynamic
// memory allocation or reliance on global constructors.
//
// To build a test, you use syntax similar to gunit, but with some extra
// decoration to create a hidden 'main' function containing each of the tests to
// be run. Your code should look something like:
// ----------------------------------------------------------------------------
// #include "path/to/this/header"
//
// TF_LITE_MICRO_TESTS_BEGIN
//
// TF_LITE_MICRO_TEST(SomeTest) {
//   TF_LITE_LOG_EXPECT_EQ(true, true);
// }
//
// TF_LITE_MICRO_TESTS_END
// ----------------------------------------------------------------------------
// If you compile this for your platform, you'll get a normal binary that you
// should be able to run. Executing it will output logging information like this
// to stderr:
// ----------------------------------------------------------------------------
// Testing SomeTest
// 1/1 tests passed
// ~~~ALL TESTS PASSED~~~
// ----------------------------------------------------------------------------
// This is designed to be human-readable, so you can just run tests manually,
// but the string "~~~ALL TESTS PASSED~~~" should only appear if all of the
// tests do pass. This makes it possible to integrate with automated test
// systems by scanning the output logs and looking for that magic value.
//
// This framework is intended to be a rudimentary alternative to no testing at
// all on systems that struggle to run more conventional approaches, so use with
// caution!

#ifndef TENSORFLOW_LITE_MICRO_TESTING_AMEBA_AIOT_MICRO_TEST_H_
#define TENSORFLOW_LITE_MICRO_TESTING_AMEBA_AIOT_MICRO_TEST_H_

#include "tensorflow/lite/micro/testing/micro_test.h"
#include "tensorflow/lite/micro/testing/ameba-aiot/test_registry.h"

#define TF_LITE_MICRO_TESTS_FUNC_NAME tflm_unittest

#undef TF_LITE_MICRO_TESTS_BEGIN
#define TF_LITE_MICRO_TESTS_BEGIN                                          \
static int TF_LITE_MICRO_TESTS_FUNC_NAME(void);                          \
  namespace {                                                              \
  class TestRegistrar {                                                    \
   public:                                                                 \
   TestRegistrar() {                                                      \
      tflite::micro::TestRegistry::GetInstance().RegisterTest(             \
          "test", TF_LITE_MICRO_TESTS_FUNC_NAME);                          \
    }                                                                      \
  };                                                                       \
  static TestRegistrar test_registrar;                     \
  }                                                                        \
  static int TF_LITE_MICRO_TESTS_FUNC_NAME(void) {        \
    micro_test::tests_passed = 0;                         \
    micro_test::tests_failed = 0;                         \
    tflite::InitializeTest();                             \
    MicroPrintf("%s\n",__FILE__);


#endif  // TENSORFLOW_LITE_MICRO_TESTING_AMEBA_AIOT_MICRO_TEST_H_
