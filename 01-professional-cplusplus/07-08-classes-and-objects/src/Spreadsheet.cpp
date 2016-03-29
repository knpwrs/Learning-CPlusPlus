#include <iostream>
#include "Spreadsheet.h"

namespace PcppSpreadsheet {
  Spreadsheet::Spreadsheet(int inWidth, int inHeight) : mWidth(inWidth), mHeight(inHeight)
  {
    mCells = new SpreadsheetCell*[mWidth];
    for (int i = 0; i < mWidth; i++) {
      mCells[i] = new SpreadsheetCell[mHeight];
    }
  }
  
  Spreadsheet::Spreadsheet(const Spreadsheet& src)
  {
    copyFrom(src);
  }
  
  Spreadsheet::~Spreadsheet()
  {
    destroy();
  }
  
  Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs)
  {
    if (this == &rhs) {
      return *this;
    }
    // Free the old memory
    destroy();
    // Copy the new memory
    copyFrom(rhs);
    return *this;
  }
  
  void Spreadsheet::destroy()
  {
    for (int i = 0; i < mWidth; i++) {
      delete[] mCells[i];
    }
    delete[] mCells;
    mCells = nullptr;
  }
  
  void Spreadsheet::copyFrom(const Spreadsheet& src)
  {
    mWidth = src.mWidth;
    mHeight = src.mHeight;
    mCells = new SpreadsheetCell*[mWidth];
    for (int x = 0; x < mWidth; x++) {
      mCells[x] = new SpreadsheetCell[mHeight];
      for (int y = 0; y < mHeight; y++) {
        mCells[x][y] = src.mCells[x][y];
      }
    }
  }
  
  void Spreadsheet::setCellAt(int x, int y, const SpreadsheetCell& cell)
  {
    if (!inRange(x, mWidth) || !inRange(y, mHeight)) {
      throw std::out_of_range("");
    }
    mCells[x][y] = cell;
  }
  
  SpreadsheetCell& Spreadsheet::getCellAt(int x, int y) const
  {
    if (!inRange(x, mWidth) || !inRange(y, mHeight)) {
      throw std::out_of_range("");
    }
    return mCells[x][y];
  }
  
  bool Spreadsheet::inRange(int val, int upper) const
  {
    return val >= 0 && val < upper;
  }
}
