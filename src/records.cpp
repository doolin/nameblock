
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <stdlib.h>

using std::string;
using std::vector;
using std::ifstream;

void
read_records() {

  std::cout << "Reading records..." << std::endl;

  string filename("/data/patentdata/patents/full/full.csv");
  ifstream is(filename.c_str());
  while (is.good()) {
    string * line = new string();
    getline(is, *line);
    delete line;
  }
  std::cout << "Finished reading records..." << std::endl;
}


void
make_records_vector() {


  char * foo = (char*)malloc(1024*1024*512);
  free(foo);

  std::cout << "Reading vector records..." << std::endl;
  //vector<string> records(1000000);
  //vector<string> records(100);
  vector<string> records(10000);
  string filename("/data/patentdata/patents/full/full.csv");
  ifstream is(filename.c_str());

  int counter = 0;
  while (is.good()) {
    string line;
    getline(is, line);
    records.push_back(line);
    ++counter;
    if ((counter % 100000) == 0) std::cout << counter << std::endl;
  }
  std::cout << std::endl;

#if 0
  vector<string *>::const_iterator it = records.begin();
  for (; it != records.end(); ++it) {
    delete (*it);
  }
#endif

  std::cout << "Finished reading vector records..." << std::endl;
}


int
main(int argc, char **) {

  //read_records();
  make_records_vector();

  return 0;
}
