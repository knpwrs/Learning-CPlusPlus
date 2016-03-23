#pragma once

#include <initializer_list>
#include <vector>

namespace PcppC02E07 {
  class EvenSequence
  {
    public:
      EvenSequence(std::initializer_list<double> args);
      void dump() const;
      int size() const;
    private:
      std::vector<double> mSequence;
  };
}
