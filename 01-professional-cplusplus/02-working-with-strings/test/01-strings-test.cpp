#include <string>
#include "gtest/gtest.h"
#include "01-strings.h"

using namespace std;
using namespace PcppC02E01Strings;

TEST(Strings, Copy) {
  string str = "FooBar";
  EXPECT_EQ(copy(str), str);
}

TEST(Strings, CopyLiteral) {
  auto str = "FooBar"s;
  EXPECT_EQ(copy(str), str);
}

TEST(Strings, FromNumber) {
  EXPECT_EQ(to_string(-4), "-4"s);
  EXPECT_EQ(to_string(4U), "4"s);
  EXPECT_EQ(to_string(-5L), "-5"s);
  EXPECT_EQ(to_string(5UL), "5"s);
  EXPECT_EQ(to_string(-6LL), "-6"s);
  EXPECT_EQ(to_string(6ULL), "6"s);
  EXPECT_EQ(to_string(3.14f), "3.140000"s);
  EXPECT_EQ(to_string(3.14), "3.140000"s);
  EXPECT_EQ(to_string(3.14L), "3.140000"s);
}

TEST(Strings, ToNumber) {
  EXPECT_EQ(stoi("-4"s), -4);
  EXPECT_EQ(stol("-5"s), -5L);
  EXPECT_EQ(stoul("5"s), 5L);
  EXPECT_EQ(stoll("-7"s), -7LL);
  EXPECT_EQ(stoull("7"s), 7LL);
  EXPECT_EQ(stof("-3.14"s), -3.14f);
  EXPECT_EQ(stod("3.14159"s), 3.14159);
  EXPECT_EQ(stold("3.14159"s), 3.14159L);
}
