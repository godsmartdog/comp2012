#include <iostream>
#include <vector>
#include <functional>
#include <sstream>

#ifdef __ZINC__
constexpr int TEST_CASE_NUMBER = 100;

#include "PublicTest.h"
#include "PrivateTest.h"
#else
constexpr int TEST_CASE_NUMBER = 40;

#include "PublicTest.h"
#endif // __ZINC__

#ifdef __ZINC__
#include "Answers.h"
#endif // __ZINC__

static std::vector<std::function<void(void)>> testEntries;

template <int P>
void init() {
  testEntries.push_back([](){ runTestCase<P>(); });
  init<P + 1>();
}

template <>
void init<TEST_CASE_NUMBER>() {
}

int main() {
  init<0>();

  int testNumber;
  std::cin >> testNumber;

  if (testNumber < TEST_CASE_NUMBER) {
#ifdef __ZINC__
    std::streambuf* backup = cout.rdbuf();
    std::stringstream stream;
    std::cout.rdbuf(stream.rdbuf());
#endif // __ZINC__
    testEntries[testNumber]();
#ifdef __ZINC__
    std::string output = stream.str();
    assert(output == ANSWERS[testNumber]);
    cout.rdbuf(backup);
#endif // __ZINC__
  }
  else {
    runTestCase<-1>();
  }

  return 0;
}
