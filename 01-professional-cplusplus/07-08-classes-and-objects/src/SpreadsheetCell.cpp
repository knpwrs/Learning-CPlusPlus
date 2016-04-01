#include "SpreadsheetCell.h"
#include <iostream>
#include <sstream>
using namespace std;

namespace PcppSpreadsheet {
  SpreadsheetCell::SpreadsheetCell()/* : mValue(0)*/ // Now initialized in class definition (see header)
  {
    // mValue initialized above before constructor is called, this has implications for const members and similar
    // initialization is done in declaration order, not the order above!
    // mValue = 0; // Generated default constructor does not create language primitives
    // No need to initialize string value, string constructor is automatically called
  }
  SpreadsheetCell::SpreadsheetCell(double initialValue)
  {
    set(initialValue);
  }
  // Delegated constructor
  SpreadsheetCell::SpreadsheetCell(const string& initialString): SpreadsheetCell(stringToDouble(initialString))
  {
    // Empy delegated constructor
  }
  // Copy constructor
  SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell& src) : mValue(src.mValue), mString(src.mString)
  {
    // Empty copy constructor, called in pass-by-value scenarios or manually
  }
  // Assignment operator
  SpreadsheetCell& SpreadsheetCell::operator=(const SpreadsheetCell& rhs)
  {
    if (this == &rhs) {
      return *this;
    }
    mValue = rhs.mValue;
    mString = rhs.mString;
    return *this;
  }
  // Addition operators
  // First commented to avoid ambiguity
  // SpreadsheetCell SpreadsheetCell::operator+(const SpreadsheetCell& rhs) const
  // {
  //   return SpreadsheetCell(rhs.mValue + mValue);
  // }
  SpreadsheetCell SpreadsheetCell::operator+(const double& value) const
  {
    return SpreadsheetCell(value + mValue);
  }
  void SpreadsheetCell::set(double inValue)
  {
    mValue = inValue;
    mString = doubleToString(inValue);
  }
  void SpreadsheetCell::set(const string& inString)
  {
    mString = inString;
    mValue = stringToDouble(inString);
  }
  string SpreadsheetCell::doubleToString(double inValue)
  {
    ostringstream ostr;
    ostr << inValue;
    return ostr.str();
  }
  double SpreadsheetCell::stringToDouble(const string& inString)
  {
    double temp;
    istringstream istr(inString);
    istr >> temp;
    if (istr.fail() || !istr.eof()) {
      return 0;
    }
    return temp;
  }
  void SpreadsheetCell::setColor(Colors color)
  {
    mColor = color;
  }
  SpreadsheetCell::Colors SpreadsheetCell::getColor() const
  {
    return mColor;
  }
  // "Global" Addition Operator (Friend)
  SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
  {
    return SpreadsheetCell(lhs.mValue + rhs.mValue);
  }
}
