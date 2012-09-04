
#include <iostream>
#include <fstream>
#include <list>
#include <map>

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "record.h"

using std::ifstream;
using std::list;
using std::map;
using std::cout;

typedef list<Record*> RecordPList;
typedef vector<Record> Records;

typedef map<string, RecordPList> Blocks;

#define NUM_ELEMENTS 10000
#define MAX_ELEMENTS 80000


void
get_record_pointers(Records & records, RecordPList & rl) {

  int counter = 0;
  Records::iterator rit = records.begin();
  for (; rit != records.end(); ++rit) {
    rl.push_back(&(*rit));
    ++counter;
    if ((counter % NUM_ELEMENTS) == 0) std::cout << counter << std::endl;
  }
}


void
create_blocks(const RecordPList & rpl, Blocks & blocks) {

  // iterate over rpl...
  int counter = 0;
  RecordPList::const_iterator rit = rpl.begin();
  Blocks::const_iterator b_it;
  for (; rit != rpl.end(); ++rit) {

    Record * rp = *rit;

    string key = (*rit)->attributes[0];
    //cout << "key: " << key << std::endl;
    //break;
    RecordPList rplist;
    // Find out if a string is already keying a recordlist
    b_it = blocks.find(key);
    //if (blocks.end() == blocks.find(key)) {
    if (blocks.end() == b_it) {
      // If not, create a new key, a new RPL, add the current
      // pointer to the end of it and push it into the map.
      rplist.push_back(rp);
      //map.insert(std::pair<string, RecordPList>(rit[0], rplist));
      blocks[key] = rplist;
    } else {
      // If so, fetch the value and push the current rpl to
      // the end of the list.
      rplist = blocks[key];
      rplist.push_back(rp);
      blocks[key] = rplist;
    }
    ++counter;
    if ((counter % NUM_ELEMENTS) == 0) std::cout << counter << std::endl;
  }
}


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
  string line;
  while (is.good()) {
    getline(is, line);
    Record r(line);
    records.push_back(r);
    ++counter;
    if ((counter % NUM_ELEMENTS) == 0) std::cout << counter << std::endl;
    if (counter > MAX_ELEMENTS) break;
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

  //records[444].print_attributes();

  RecordPList rpl;
  get_record_pointers(records, rpl);

  Record * rp = rpl.front();

  rp->print_attributes();
  cout << "Att: " << rp->attributes[0] << std::endl;

  Blocks blocks;
  std::cout << "Blocks size: " << blocks.size() << std::endl;
  create_blocks(rpl, blocks);
  std::cout << "Blocks size: " << blocks.size() << std::endl;

  for (Blocks::const_iterator it = blocks.begin(); it != blocks.end(); ++it) {
    //std::cout << "Key: " << it.first << ", Size: " << it.second.size() << std::endl;
    //break;
    if ((*it).second.size() > 1) {
      std::cout << "Size: " << (*it).second.size() << std::endl;
    }
  }

  return 0;
}
#endif

