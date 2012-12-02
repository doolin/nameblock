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

public:
  RecordTest(std::string name) : CppUnit::TestCase(name) {
    describe_test(INDENT0, name.c_str());
  }

  void test_parse_column_names() {

    Spec spec;
    spec.it("From records test %d", DO_SPEC_HANDLE {
        sprintf(spec.buf, d, 1);
        return true;
    });
  }


  void test_make_records_vector() {

    string filename("./fixtures/ten_records_1973.csv");
    ifstream is(filename.c_str());
    Records records;
    make_records_vector(is, records);

    std::cout << "record size: " << records.size() << std::endl;

    for(auto record : records) {
      //record.print();
    }

    Spec spec;
    spec.it("should load 9 records from fixture file", DO_SPEC_HANDLE {

        return (9 == records.size());
    });
  }

  void runTest() {
    test_parse_column_names();
    test_make_records_vector();
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
