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
using std::string;
using std::vector;

typedef vector<uint8_t> SP;

SP
compare_records_1(Record * r1, Record * r2) {
  return SP({1,1});
}

class SimilarityTest : public CppUnit::TestCase {

public:

  SimilarityTest(string name) : CppUnit::TestCase(name) {

    describe_test(INDENT0, name.c_str());
  }

  void test_similarity_equal() {


    Spec spec;
    spec.it("Testing similarity for identical records", DO_SPEC {
        Record * r1 = new Record("Foo, Bar");
        Record * r2 = new Record("Foo, Bar");
        SP sp({1,1});
        return (sp == compare_records_1(r1, r2));
    });
  }

  void run_tests() {
    test_similarity_equal();
  }

};

void
test_similarity() {

  SimilarityTest * st = new SimilarityTest(string("Similarity testing..."));
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
