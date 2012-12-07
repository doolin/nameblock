#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <cppunit/TestCase.h>

#include <record.h>
#include <macros.h>
//#include <record_private.h>

#include "testutils.h"

using std::ifstream;


class RecordTest : public CppUnit::TestCase {

private:
  Records records;
  Blocks blocks;

public:

  RecordTest(std::string name) : CppUnit::TestCase(name) {

    describe_test(INDENT0, name.c_str());

    string filename("./fixtures/ten_records_1973.csv");
    ifstream is(filename.c_str());
    make_records_vector(is, records);

    RecordPList rpl;
    get_record_pointers(records, rpl);
    create_blocks(rpl, blocks);

 }

  void test_parse_column_names() {

    describe_test(INDENT2, __PRETTY_FUNCTION__);

    Spec spec;
    spec.it("From records test %d", DO_SPEC_HANDLE {
        sprintf(spec.buf, d, 1);
        return true;
    });
  }


  void test_make_records_vector() {

   for(auto record : records) {
      //record.print();
    }

    Spec spec;
    spec.it("should load 9 records from fixture file", DO_SPEC_HANDLE {
      return (9 == records.size());
    });
  }


  void test_lastname_blocking() {

    Spec spec;
    spec.it("should have 8 blocks", DO_SPEC_HANDLE {
        return (8 == blocks.size());
    });
  }


  void test_block_mann_count_2() {

    describe_test(INDENT2, __PRETTY_FUNCTION__);

    Spec spec;
    spec.it("Block bucket tagged 'MANN' should have count 2", DO_SPEC_HANDLE {
      c_blocks_iter_t it = blocks.find("MANN");
      return (2 == (*it).second.size());
    });

    spec.it("Block bucket tagged 'DURAND' should have count 1", DO_SPEC_HANDLE {
      c_blocks_iter_t it = blocks.find("DURAND");
      return (1 == (*it).second.size());
    });
  }


  void test_parse_line() {

    describe_test(INDENT2, __PRETTY_FUNCTION__);

    string line("att1, att2, att 3, 4 att");
    Record r(line);

    Spec spec;
    spec.xit("should have the correct line and attributes", DO_SPEC_HANDLE {
      //return (line == r.line);
    });

    spec.it("should have 4 attributes", DO_SPEC_HANDLE {
      return (4 == r.attributes.size());
    });

    spec.it("parses 'att1' for the first attribute", DO_SPEC_HANDLE {
      return (string("att1") == r.attributes[0]);
    });

  }

  void runTest() {
    test_parse_column_names();
    test_make_records_vector();
    test_lastname_blocking();
    test_block_mann_count_2();
    test_parse_line();
  }
};


void
test_records() {

  RecordTest * rt = new RecordTest(std::string("Testing records"));
  rt->runTest();
  delete rt;
}


#ifdef test_record_STANDALONE
int
main(int, char **) {

  test_records();
  return 0;
}
#endif
