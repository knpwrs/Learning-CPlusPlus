#pragma once
#include <string>

namespace PcppC02E07 {
  class SpreadsheetCell {
    public:
      // SpreadsheetCell() = default; // Explicitly defaulted constructor
      // SpreadsheetCell() = delete; // Explicitly deleted constructor (only static methods)
      SpreadsheetCell();
      SpreadsheetCell(double initialValue);
      // Copy constructor, called in pass-by-value scenarios or manually
      SpreadsheetCell(const SpreadsheetCell& src);
      // Copy constructors can also be defaulted or deleted:
      // SpreadsheetCell(const SpreadsheetCell& src) = default;
      // SpreadsheetCell(const SpreadsheetCell& src) = delete;
      void setValue(double inValue);
      double getValue() const;
      void setString(const std::string& inString);
      const std::string& getString() const;
    private:
      std::string doubleToString(double inValue) const;
      double stringToDouble(const std::string& inString) const;
      double mValue;
      std::string mString;
  };
}
