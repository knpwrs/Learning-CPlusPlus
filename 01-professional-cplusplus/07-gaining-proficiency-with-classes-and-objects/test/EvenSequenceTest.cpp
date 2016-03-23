#include "gtest/gtest.h"
#include "EvenSequence.h"

using namespace std;
using namespace PcppC02E07;

TEST(EvenSequence, InitializerListConstructor) {
  EvenSequence p1 {1.0, 2.0, 3.0, 4.0, 5.5, 7.7};
  EXPECT_EQ(p1.size(), 6);
}

TEST(EvenSequence, InvalidArgument) {
    try {
        EvenSequence p1 {1.0, 2.0, 3.0};
        FAIL() << "Expected std::invalid_argument";
    }
    catch(invalid_argument const & err) {
        EXPECT_EQ(err.what(), string("initializer_list should contain even number of elements"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }
}
