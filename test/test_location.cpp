
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <cppunit/TestCase.h>

#include <location.h>
#include <macros.h>

#include "testutils.h"

using std::ifstream;


class LocationTest : public CppUnit::TestCase {

private:
  Location location;

public:

  LocationTest(std::string name) : CppUnit::TestCase(name) {

    describe_test(INDENT0, name.c_str());
  }

  void runTest() {
  }
};


void
test_locations() {

  LocationTest * lt = new LocationTest(std::string("Testing locations"));
  lt->runTest();
  delete lt;
}


#ifdef test_location_STANDALONE
int
main(int, char **) {

  test_locations();
  return 0;
}
#endif
