#include "SpreadsheetCell.h"
#include <iostream>
#include <sstream>
using namespace std;

namespace PcppC02E07 {
  void SpreadsheetCell::setValue(double inValue) {
    mValue = inValue;
    mString = doubleToString(inValue);
  }
  double SpreadsheetCell::getValue() const {
    return mValue;
  }
  void SpreadsheetCell::setString(const string& inString) {
    mString = inString;
    mValue = stringToDouble(inString);
  }
  const string& SpreadsheetCell::getString() const {
    return mString;
  }
  string SpreadsheetCell::doubleToString(double inValue) const {
    ostringstream ostr;
    ostr << inValue;
    return ostr.str();
  }
  double SpreadsheetCell::stringToDouble(const string& inString) const {
    double temp;
    istringstream istr(inString);
    istr >> temp;
    if (istr.fail() || !istr.eof()) {
      return 0;
    }
    return temp;
  }
}
