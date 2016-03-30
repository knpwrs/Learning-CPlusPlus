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

TEST(Spreadsheet, DefaultArgs)
{
  Spreadsheet ss;
  EXPECT_EQ(ss.getWidth(), 100);
  EXPECT_EQ(ss.getHeight(), 100);
  Spreadsheet ss2(50);
  EXPECT_EQ(ss2.getWidth(), 50);
  EXPECT_EQ(ss2.getHeight(), 100);
  Spreadsheet ss3(50, 75);
  EXPECT_EQ(ss3.getWidth(), 50);
  EXPECT_EQ(ss3.getHeight(), 75);
}

TEST(Spreadsheet, Clamping)
{
  Spreadsheet ss(Spreadsheet::kMaxWidth + 1, Spreadsheet::kMaxHeight + 1);
  EXPECT_EQ(ss.getWidth(), Spreadsheet::kMaxWidth);
  EXPECT_EQ(ss.getHeight(), Spreadsheet::kMaxHeight);
}
