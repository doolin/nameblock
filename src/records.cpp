
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

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


// Filched from the disambiguation code.
vector<string>
parse_column_names(string line) {

  size_t pos = 0;
  size_t prev_pos = 0;
  const char * delim = ",";
  const uint32_t delim_size = strlen(delim);
  vector <string> total_col_names;

  while (pos != string::npos) {

      string columnname;

      pos = line.find(delim, prev_pos);
      if (pos != string::npos) {
          columnname = line.substr(prev_pos, pos - prev_pos);
      } else {
          columnname = line.substr(prev_pos );
      }

      total_col_names.push_back(columnname);
      prev_pos = pos + delim_size;
  }
  return total_col_names;
}



class Record {
  private:
    string line;
  public:
    Record(string l) : line(l) {}

    void print() {
      std::cout << line << std::endl;
    }
};


void
make_records_vector(vector<Record> & records) {


  char * foo = (char*)malloc(1024*1024*512);
  free(foo);

  std::cout << "Reading vector records..." << std::endl;
  //vector<string> records(100);
  //vector<Record> records;
  string filename("/data/patentdata/patents/full/full.csv");
  ifstream is(filename.c_str());

  int counter = 0;
  while (is.good()) {
    string line;
    getline(is, line);
    Record r(line);
    records.push_back(r);
    ++counter;
    if ((counter % 100000) == 0) std::cout << counter << std::endl;
    if (counter > 300000) break;
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
  vector<Record> records;
  make_records_vector(records);
  records[0].print();
  records[14324].print();

  return 0;
}
