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


class ComparatorTest : public CppUnit::TestCase {

private:
  Records records;

public:

  ComparatorTest(std::string name) : CppUnit::TestCase(name) {

    describe_test(INDENT0, name.c_str());

    string filename("./fixtures/ten_records_1973.csv");
    ifstream is(filename.c_str());
    make_records_vector(is, records);
  }


  void test_name_similarity() {

    describe_test(INDENT2, __PRETTY_FUNCTION__);

    Spec spec;
    spec.it("From name similarity test %d", DO_SPEC_HANDLE {
        sprintf(spec.buf, d, 1);
        return (1 == compare_names(string("foo"), string("foo")));
    });
  }


  void test_location_similarity() {

    describe_test(INDENT2, __PRETTY_FUNCTION__);

    Spec spec;
    spec.it("From location similarity test %d", DO_SPEC_HANDLE {
        sprintf(spec.buf, d, 1);
        return (1 == compare_locations(string("foo"), string("foo")));
    });
  }

  void test_assignee_similarity() {

    describe_test(INDENT2, __PRETTY_FUNCTION__);

    Spec spec;
    spec.it("From assignee similarity test %d", DO_SPEC_HANDLE {
        sprintf(spec.buf, d, 1);
        return (1 == compare_assignees(string("foo"), string("foo")));
    });
  }

  void test_class_similarity() {

    describe_test(INDENT2, __PRETTY_FUNCTION__);

    Spec spec;
    spec.it("From class similarity test %d", DO_SPEC_HANDLE {
        sprintf(spec.buf, d, 1);
        return (1 == compare_classes(string("foo"), string("foo")));
    });
  }


  void test_coauthor_similarity() {

    describe_test(INDENT2, __PRETTY_FUNCTION__);

    Spec spec;
    spec.it("From coauthor similarity test %d", DO_SPEC_HANDLE {
        sprintf(spec.buf, d, 1);
        return (1 == compare_coauthors(string("foo"), string("foo")));
    });
  }


  void runTest() {
    test_name_similarity();
    test_location_similarity();
    test_assignee_similarity();
    test_class_similarity();
    test_coauthor_similarity();
  }

};


void
test_comparators() {
  ComparatorTest * ct = new ComparatorTest(std::string("Testing comparators"));
  ct->runTest();
  delete ct;
}


#ifdef test_comparators_STANDALONE
int
main(int, char **) {

  test_comparators();
  return 0;
}
#endif
