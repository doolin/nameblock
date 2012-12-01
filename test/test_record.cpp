#include <string>
#include <vector>

#include <cppunit/TestCase.h>

#include <record.h>

#include "testutils.h"


//#include <record_private.h>

class RecordTest : public CppUnit::TestCase {

public:
  RecordTest(std::string name) : CppUnit::TestCase(name) {

    describe_test(INDENT0, name.c_str());
  }

  void test_parse_column_names() {

    Spec spec;
    spec.it("From records test", DO_SPEC {
        return true;
    });
  }

  void runTest() {
    test_parse_column_names();
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
