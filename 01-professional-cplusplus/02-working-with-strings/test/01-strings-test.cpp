#include <string>
#include "gtest/gtest.h"
#include "01-strings.h"

using namespace std;
using namespace PcppC02E01Strings;

TEST(strings, copy) {
  string str = "FooBar";
  EXPECT_TRUE(copy(str) == str);
}
