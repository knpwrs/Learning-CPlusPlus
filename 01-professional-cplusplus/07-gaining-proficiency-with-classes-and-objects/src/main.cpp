#include <iostream>
#include <memory>
#include "SpreadsheetCell.h"

using namespace std;
using namespace PcppC02E07;

int main() {
  // On the stack
  SpreadsheetCell myCell, anotherCell;
  myCell.setValue(6);
  anotherCell.setString("3.2");
  cout << "stack cell 1: " << myCell.getValue() << endl;
  cout << "stack cell 2: " << anotherCell.getValue() << endl;
  // On the heap
  SpreadsheetCell* myCellp = new SpreadsheetCell();
  myCellp->setValue(3.7);
  cout << "heap cell 1: " << myCellp->getValue() << endl;
  delete myCellp;
  myCellp = nullptr;
  // Smart pointers for the heap
  auto anotherCellp = make_unique<SpreadsheetCell>();
  anotherCellp->setValue(3.14159);
  cout << "heap cell 2: " << anotherCellp->getValue() << endl;
  // Done
  return 0;
}
