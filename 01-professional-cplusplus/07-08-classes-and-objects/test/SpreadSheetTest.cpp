#include "gtest/gtest.h"
#include "Spreadsheet.h"

using namespace std;
using namespace PcppSpreadsheet;

TEST(Spreadsheet, Statics)
{
  EXPECT_EQ(Spreadsheet::kMaxWidth, 100);
  EXPECT_EQ(Spreadsheet::kMaxHeight, 100);
}

TEST(Spreadsheet, BasicOps)
{
  Spreadsheet ss(32, 32);
  EXPECT_EQ(ss.getId(), 0);
  Spreadsheet ss2(64, 64);
  EXPECT_EQ(ss2.getId(), 1);
  ss2 = ss;
  EXPECT_EQ(ss.getId(), 0);
  EXPECT_EQ(ss2.getId(), 1);
  Spreadsheet ss3(ss);
  EXPECT_EQ(ss3.getId(), 2);
  EXPECT_EQ(ss3.getCellAt(3, 3).getValue(), 0);
  SpreadsheetCell ssc = SpreadsheetCell(8);
  ss2.setCellAt(0, 0, ssc);
  EXPECT_EQ(ss2.getCellAt(0, 0).getValue(), 8);
  EXPECT_EQ(ss.getCellAt(0, 0).getValue(), 0);
}
