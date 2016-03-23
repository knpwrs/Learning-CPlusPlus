#include <iostream>
#include <memory>
#include <vector>
#include "SpreadsheetCell.h"
#include "EvenSequence.h"

using namespace std;
using namespace PcppC02E07;

int main()
{
  // On the stack (destroyed when out of scope)
  SpreadsheetCell stackCell, stackCell2; // Omit parentheses for the default constructor
  stackCell.setValue(6);
  stackCell2.setString("3.2");
  cout << "stack cell 1: " << stackCell.getValue() << endl;
  cout << "stack cell 2: " << stackCell2.getValue() << endl;
  // Constructor on the stack
  SpreadsheetCell stackCell3(4.2), stackCell4(9.2);
  cout << "stack cell 3: " << stackCell3.getValue() << endl;
  cout << "stack cell 4: " << stackCell4.getValue() << endl;
  // On the heap
  SpreadsheetCell* heapCell = new SpreadsheetCell();
  heapCell->setValue(3.7);
  cout << "heap cell 1: " << heapCell->getValue() << endl;
  delete heapCell;
  heapCell = nullptr;
  // Constructor on the heap
  auto heapCell2 = new SpreadsheetCell(44);
  cout << "heap cell 2: " << heapCell2->getValue() << endl;
  delete heapCell2;
  heapCell2 = nullptr;
  // Smart pointers for the heap
  auto smartCell = make_unique<SpreadsheetCell>();
  smartCell->setValue(3.14159);
  cout << "smart cell 1: " << smartCell->getValue() << endl;
  // Constructor with for pointer to the heap
  auto smartCell2 = make_unique<SpreadsheetCell>(42);
  cout << "smart cell 2: " << smartCell2->getValue() << endl;
  // Manual heap delayed instantiation
  SpreadsheetCell* heapCell3 = nullptr;
  heapCell3 = new SpreadsheetCell(55);
  cout << "heap cell 3: " << heapCell3->getValue() << endl;
  delete heapCell3;
  heapCell3 = nullptr;
  // Array instantiation requires a default constructor (as to STL collections)
  const int size = 3;
  SpreadsheetCell cells[3];
  SpreadsheetCell* moreCells = new SpreadsheetCell[10]; // HEAP!
  // Stack arrays can use an initializer for non-default constructors
  SpreadsheetCell stackCells[3] = {
    SpreadsheetCell(3),
    SpreadsheetCell(4),
    SpreadsheetCell(5)
  };
  for (int i = 0; i < size; i++) {
    cout << "arr cell " << i << ": " << cells[i].getValue() << endl;
    cout << "heap arr cell " << i << ": " << moreCells[i].getValue() << endl;
    cout << "stack arr cell " << i << ": " << stackCells[i].getValue() << endl;
  }
  delete[] moreCells; // CLEAN THE HEAP!
  moreCells = nullptr;
  // Copy
  auto copyCell = SpreadsheetCell(stackCell);
  cout << "copy cell: " << copyCell.getValue() << endl;
  // Initializer-List Constructor
  // EvenSequence p1 = {1.0, 2.0, 3.0, 4.0, 5.5, 7.7}; // or
  EvenSequence p1 {1.0, 2.0, 3.0, 4.0, 5.5, 7.7};
  p1.dump();
  try {
    EvenSequence p2 = {1.0, 2.0, 3.0};
  } catch (const invalid_argument& err) {
    cout << err.what() << endl;
  }
  // std initializer list
  vector<string> myVec {"Hello", "World"};
  for (auto value : myVec) {
    cout << value << endl;
  }
  // Done
  return 0;
}
