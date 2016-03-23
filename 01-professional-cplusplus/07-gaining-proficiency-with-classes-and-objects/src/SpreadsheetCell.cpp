#include "SpreadsheetCell.h"
#include <iostream>
#include <sstream>
using namespace std;

namespace PcppC02E07 {
  SpreadsheetCell::SpreadsheetCell()/* : mValue(0)*/ { // Now initialized in class definition (see header)
    // mValue initialized above before constructor is called, this has implications for const members and similar
    // initialization is done in declaration order, not the order above!
    // mValue = 0; // Generated default constructor does not create language primitives
    // No need to initialize string value, string constructor is automatically called
  }
  SpreadsheetCell::SpreadsheetCell(double initialValue) {
    setValue(initialValue);
  }
  SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell& src) : mValue(src.mValue), mString(src.mString) {
    // Empty copy constructor, called in pass-by-value scenarios or manually
  }
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
