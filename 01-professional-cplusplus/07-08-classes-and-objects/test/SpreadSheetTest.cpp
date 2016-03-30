#include "gtest/gtest.h"
#include "Spreadsheet.h"

using namespace std;
using namespace PcppSpreadsheet;

TEST(Spreadsheet, Statics)
{
  EXPECT_EQ(Spreadsheet::kMaxWidth, 100);
  EXPECT_EQ(Spreadsheet::kMaxHeight, 100);
}

TEST(Spreadsheet, Constructor)
{
  Spreadsheet ss(32, 32);
  EXPECT_EQ(ss.getId(), 0);
  Spreadsheet ss2(64, 64);
  EXPECT_EQ(ss2.getId(), 1);
  ss2 = ss;
  EXPECT_EQ(ss.getId(), 0);
  EXPECT_EQ(ss2.getId(), 1);
}
