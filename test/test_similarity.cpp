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

typedef vector<uint32_t> SP;


class SimilarityTest : public CppUnit::TestCase {

private:
  Records records;
  Blocks blocks;

public:

  SimilarityTest(string name) : CppUnit::TestCase(name) {

    describe_test(INDENT0, name.c_str());

    string filename("./fixtures/ten_records_1973.csv");
    ifstream is(filename.c_str());
    make_records_vector(is, records);

    RecordPList rpl;
    get_record_pointers(records, rpl);
    create_blocks(rpl, blocks);
  }


  void test_similarity_equal() {

    Spec spec;
    spec.it("Testing similarity for identical records", DO_SPEC_THIS {
        Record * r1 = &records[0];
        Record * r2 = &records[0];
        SP sp({1,1});
        SP result = compare_records(r1, r2);
        return (sp == result);
    });
  }

  void run_tests() {
    test_similarity_equal();
  }

};


void
test_similarity() {

  SimilarityTest * st = new SimilarityTest(string("Similarity testing..."));
  st->run_tests();
  delete st;
}


#ifdef test_similarity_STANDALONE
int
main(int, char **) {

  test_similarity();
  return 0;
}
#endif
