#include "gtest/gtest.h"
#include "SpreadsheetCell.h"

using namespace std;
using namespace PcppC02E07;

TEST(SpreadsheetCell, DefaultConstructor)
{
  SpreadsheetCell stackCell;
  EXPECT_EQ(stackCell.getValue(), 0);
  EXPECT_EQ(stackCell.getString(), "0");
}

TEST(SpreadsheetCell, InitialValue)
{
  SpreadsheetCell stackCell(3.4);
  EXPECT_EQ(stackCell.getValue(), 3.4);
  EXPECT_EQ(stackCell.getString(), "3.4");
}

TEST(SpreadsheetCell, InitialString) {
  SpreadsheetCell stackCell("5.6");
  EXPECT_EQ(stackCell.getValue(), 5.6);
  EXPECT_EQ(stackCell.getString(), "5.6");
}

TEST(SpreadsheetCell, SetValue)
{
  SpreadsheetCell stackCell;
  stackCell.setValue(3);
  EXPECT_EQ(stackCell.getValue(), 3);
  EXPECT_EQ(stackCell.getString(), "3");
  stackCell.setString("4.5");
  EXPECT_EQ(stackCell.getValue(), 4.5);
  EXPECT_EQ(stackCell.getString(), "4.5");
}
