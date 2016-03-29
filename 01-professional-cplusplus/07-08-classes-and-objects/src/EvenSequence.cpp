#include "EvenSequence.h"
#include <initializer_list>
#include <vector>
#include <iostream>

using namespace std;

namespace PcppC02E07 {
  EvenSequence::EvenSequence(initializer_list<double> args)
  {
    if (args.size() % 2 != 0) {
      throw invalid_argument("initializer_list should contain even number of elements");
    }
    mSequence.reserve(args.size());
    // for (auto value : args) {
    //   mSequence.pushBack(value);
    // } // or
    mSequence.insert(cend(mSequence), cbegin(args), cend(args));
  }
  
  void EvenSequence::dump() const
  {
    for (auto value : mSequence) {
      cout << value << ", ";
    }
    cout << endl;
  }
  
  int EvenSequence::size() const
  {
    return mSequence.size();
  }
}
