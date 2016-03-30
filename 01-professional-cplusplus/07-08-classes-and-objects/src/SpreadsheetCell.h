#pragma once
#include <string>

namespace PcppSpreadsheet {
  class SpreadsheetCell
  {
    public:
      // SpreadsheetCell() = default; // Explicitly defaulted constructor
      // SpreadsheetCell() = delete; // Explicitly deleted constructor (only static methods)
      SpreadsheetCell();
      SpreadsheetCell(double initialValue);
      SpreadsheetCell(const std::string& initialString);
      // Copy constructor, called in pass-by-value scenarios or manually
      SpreadsheetCell(const SpreadsheetCell& src);
      // Copy constructors can also be defaulted or deleted:
      // SpreadsheetCell(const SpreadsheetCell& src) = default;
      // SpreadsheetCell(const SpreadsheetCell& src) = delete;
      // Assignment operator
      SpreadsheetCell& operator=(const SpreadsheetCell& rhs);
      // Assignment operators can also be defaulted or deleted:
      // SpreadsheetCell& operator=(const SpreadsheetCell& rhs) = default;
      // SpreadsheetCell& operator=(const SpreadsheetCell& rhs) = delete;
      void set(double inValue);
      void set(const std::string& inString);
      
      // Inline methods with inline keyword:
      double getValue() const
      {
        mNumAccesses++;
        return mValue;
      };
      const std::string& getString() const
      {
        mNumAccesses++;
        return mString;
      }
    private:
      static std::string doubleToString(double inValue);
      static double stringToDouble(const std::string& inString);
      double mValue = 0; // C++11 allows initializers in class definitions
      std::string mString = "0"; // Previously this only worked for static const integral members
      mutable int mNumAccesses = 0; // Can be changed from const methods
  };
}
