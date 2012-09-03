
#include <iostream>
#include <fstream>

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "record.h"

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


void
Record::print_attributes() {

  std::cout << "printing attributes..." << std::endl;
  vector<string>::const_iterator at = attributes.begin();
  for (; at != attributes.end(); ++at) {
  //for (auto att : attributes) {
    std::cout << *at << std::endl;
  }
}

void
Record::parse_line() {

  size_t pos = 0;
  size_t prev_pos = 0;
  const char * delim = ",";
  const uint32_t delim_size = strlen(delim);

  while (pos != string::npos) {

      string columnname;

      pos = line.find(delim, prev_pos);
      if (pos != string::npos) {
          columnname = line.substr(prev_pos, pos - prev_pos);
      } else {
          columnname = line.substr(prev_pos );
      }

      attributes.push_back(columnname);
      prev_pos = pos + delim_size;
  }
}


void
parse_records(vector<Record> & records) {

  vector<Record>::iterator record = records.begin();
  for (; record != records.end(); ++record) {
  //for (auto record : records) {
    //std::cout << "parsing records..." << std::endl;
    //record.print();
    record->parse_line();
    //record->print_attributes();
    //break;
  }
  records[4].print_attributes();
}

void
make_records_vector(vector<Record> & records) {

  std::cout << "Reading vector records..." << std::endl;

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
  std::cout << "Finished reading vector records..." << std::endl;
  std::cout << std::endl;

}


#ifdef records_STANDALONE
int
main(int argc, char **) {

  //read_records();
  vector<Record> records;
  make_records_vector(records);
  //records[14324].print();
  //parse_records(records);

  records[444].print_attributes();

  return 0;
}
#endif

