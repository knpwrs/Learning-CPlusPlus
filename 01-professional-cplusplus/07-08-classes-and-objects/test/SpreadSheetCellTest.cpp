#include "gtest/gtest.h"
#include "SpreadsheetCell.h"

using namespace std;
using namespace PcppSpreadsheet;

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
  stackCell.set(3);
  EXPECT_EQ(stackCell.getValue(), 3);
  EXPECT_EQ(stackCell.getString(), "3");
  stackCell.set("4.5");
  EXPECT_EQ(stackCell.getValue(), 4.5);
  EXPECT_EQ(stackCell.getString(), "4.5");
}

TEST(SpreadsheetCell, Colors)
{
  SpreadsheetCell cell;
  EXPECT_EQ(cell.getColor(), SpreadsheetCell::Colors::Red);
  cell.setColor(SpreadsheetCell::Colors::Green);
  EXPECT_EQ(cell.getColor(), SpreadsheetCell::Colors::Green);
}

TEST(SpreadsheetCell, Addition)
{
  SpreadsheetCell cell1(4), cell2(3);
  auto cell3 = cell1 + cell2;
  EXPECT_EQ(cell3.getValue(), 7);
}

TEST(SpreadsheetCell, AdditionDouble)
{
  SpreadsheetCell cell1(4);
  auto cell2 = cell1 + 6;
  EXPECT_EQ(cell2.getValue(), 10);
}

TEST(SpreadsheetCell, AdditionImplicit)
{
  SpreadsheetCell cell1(4);
  auto cell2 = 4 + cell1;
  EXPECT_EQ(cell2.getValue(), 8);
}

TEST(SpreadsheetCell, AdditionAssignment)
{
  SpreadsheetCell cell1(4), cell2(8);
  cell1 += cell2;
  EXPECT_EQ(cell1.getValue(), 12);
  EXPECT_EQ(cell2.getValue(), 8);
}

TEST(SpreadsheetCell, Comparison)
{
  SpreadsheetCell cell1(5), cell2(4);
  EXPECT_TRUE(cell1 > cell2);
  EXPECT_TRUE(cell2 < cell1);
  EXPECT_FALSE(cell1 < cell2);
  EXPECT_FALSE(cell2 > cell1);
  EXPECT_TRUE(cell1 > 4);
  EXPECT_TRUE(cell1 < 6);
}
