#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <cppunit/TestCase.h>

#include <record.h>
#include <macros.h>

#include <comparators.h>

#include "testutils.h"

using std::ifstream;


class SimilarityTest : public CppUnit::TestCase {

public:

  void run_tests() {
  }

};

void
test_similarity() {

  SimilarityTest * st = new SimilarityTest();
  delete st;
  st->run_tests();
}


#ifdef test_similarity_STANDALONE
int
main(int, char **) {

  test_similarity();
  return 0;
}
#endif
