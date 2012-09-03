#include <string>
#include <vector>

#include <cppunit/TestCase.h>

//#include <disambiguation.h>
//#include <engine.h>

//#include "record.h"

//#include <record_private.h>

class RecordTest : public CppUnit::TestCase {

public:
  RecordTest(std::string name) : CppUnit::TestCase(name) {}

  void test_parse_column_names() {
    std::cout << "From record test..." << std::endl;
  }

  void runTest() {
    test_parse_column_names();
  }
};


void
test_records() {

  RecordTest * rt = new RecordTest(std::string("initial test"));
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
