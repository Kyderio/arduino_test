#ifndef TENSORFLOW_LITE_MICRO_TESTING_AMEBA_AIOT_TEST_REGISTRY_H_
#define TENSORFLOW_LITE_MICRO_TESTING_AMEBA_AIOT_TEST_REGISTRY_H_

#include <cstddef>

namespace tflite {
namespace micro {

typedef int (*TestFunction)(void);

struct TestCase {
  const char* name;
  TestFunction function;
};

class TestRegistry {
 public:
  static TestRegistry& GetInstance();
  void RegisterTest(const char* name, TestFunction function);
  const TestCase* GetTests() const;
  size_t NumTests() const;

 private:
  TestRegistry();
  static constexpr size_t kMaxTests = 100;
  TestCase tests_[kMaxTests];
  size_t num_tests_;
};

} // namespace micro
} // namespace tflite

#endif // TENSORFLOW_LITE_MICRO_TESTING_AMEBA_AIOT_TEST_REGISTRY_H_