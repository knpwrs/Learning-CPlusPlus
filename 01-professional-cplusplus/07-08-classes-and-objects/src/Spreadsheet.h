#pragma once
#include "SpreadsheetCell.h"

namespace PcppSpreadsheet {
  class Spreadsheet
  {
    public:
      static const unsigned int kMaxWidth = 100;
      static const unsigned int kMaxHeight = 100;
      Spreadsheet(int inWidth, int inHeight);
      Spreadsheet(const Spreadsheet& src); // Copy constructor, should be implemented for dynamic memory
      // Spreadsheet(const Spreadsheet& src) = delete; // Otherwise explicitly delete
      ~Spreadsheet(); // Destructor, called when object is destroyed, should be implemented for dynamic memory
      Spreadsheet& operator=(const Spreadsheet& rhs); // Assignment operator, should be implemented for dynamic memory
      // Spreadsheet& operator=(const Spreadsheet& rhs) = delete; // Otherwise explicitly delete
      unsigned int getId() const;
      void setCellAt(int x, int y, const SpreadsheetCell& cell);
      SpreadsheetCell& getCellAt(int x, int y) const; // Not const in book
    private:
      static unsigned int sCounter;
      const unsigned int mId;
      bool inRange(int val, int upper) const; // Not const in book
      int mWidth, mHeight;
      SpreadsheetCell** mCells; // Naked pointers for learning purposes.
      void destroy();
      void copyFrom(const Spreadsheet& src);
  };
}
