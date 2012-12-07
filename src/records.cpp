#include <iostream>
#include <fstream>
#include <list>
#include <map>

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "timer.h"
#include "record.h"

using std::ifstream;
using std::list;
using std::map;
using std::cout;


class Histogram {

  typedef map<uint32_t, uint32_t> Bucket;
  Bucket bucket;

public:

  void print() {
    //std::cout << "Bucket size, Bucket count" << (*it).second << std::endl;
    for (Bucket::const_iterator it = bucket.begin(); it != bucket.end(); ++it) {
      std::cout << (*it).first << ", " << (*it).second << std::endl;
    }
  }

  void add_to_bucket(uint32_t count) {
    bucket[count]++;
  }	
};


Histogram h;

#define NUM_ELEMENTS 10000
#define MAX_ELEMENTS 11000001

// Fast and dirty histogram from the command line:
// cat tmp.txt | awk '{print $2; FS = ", "}' | sort | uniq -c | sort -rn > histo2.txt

void
get_record_pointers(const Records & records, RecordPList & rl) {

  int counter = 0;
  Records::const_iterator rit = records.begin();
  for (; rit != records.end(); ++rit) {
    rl.push_back(&(*rit));
    ++counter;
    //if ((counter % NUM_ELEMENTS) == 0) std::cout << counter << std::endl;
  }
}


string
blocker(RecordPList::const_iterator rit) {

  //return string((*rit)->attributes[1]);
  //return string((*rit)->attributes[1]) + string((*rit)->attributes[0]);

  //*
  // Get first char of first name
  string s = string((*rit)->attributes[0]);
  if (!s.empty()) {
	  return string((*rit)->attributes[1]) + s[0];
  } else {
	  return string((*rit)->attributes[1]);
  }
  //*/

  return string((*rit)->attributes[1]);
  //return string((*rit)->attributes[1]) + string((*rit)->attributes[0]);
}


void
create_blocks(const RecordPList & rpl, Blocks & blocks) {

  int counter = 0;
  RecordPList::const_iterator rit = rpl.begin();
  for (; rit != rpl.end(); ++rit) {

    const Record * rp = *rit;
    // This needs to change to a function which retrieves
    // a Blockingkey, which is a string generated by
    // some sort of blocking rule.
    //string key = (*rit)->attributes[1];
    string key = blocker(rit); //(*rit)->attributes[1];
    RecordPList rplist;

    if (blocks.end() != blocks.find(key)) {
      rplist = blocks[key];
    }

    rplist.push_back(rp);
    blocks[key] = rplist;

    ++counter;
    //if ((counter % NUM_ELEMENTS) == 0) std::cout << counter << std::endl;
  }
}


// This function was used for testing memory and performance,
// but is not used at the moment.
void
read_records() {

  //std::cout << "Reading records..." << std::endl;

  string filename("/data/patentdata/patents/full/full.csv");
  ifstream is(filename.c_str());
  while (is.good()) {
    string * line = new string();
    getline(is, *line);
    delete line;
  }
  //std::cout << "Finished reading records..." << std::endl;
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
Record::print_attributes() const {

  //std::cout << "printing attributes..." << std::endl;
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

      string field;

      pos = line.find(delim, prev_pos);
      if (pos != string::npos) {
          field = line.substr(prev_pos, pos - prev_pos);
      } else {
          field = line.substr(prev_pos );
      }

      attributes.push_back(field);
      prev_pos = pos + delim_size;
  }
}


void
parse_records(vector<Record> & records) {

  vector<Record>::iterator record = records.begin();
  for (; record != records.end(); ++record) {
    record->parse_line();
  }
}


void
make_records_vector(ifstream & is, Records & records) {

  int counter = 0;
  string line;
  // Throw the header away for now
  if (is.good()) getline(is, line);

  while (is.good()) {
    getline(is, line);
    if (line.empty()) {
      break;
    }
    Record r(line);
    records.push_back(r);

    ++counter;
    //if ((counter % NUM_ELEMENTS) == 0) std::cout << counter << std::endl;
    if (counter > MAX_ELEMENTS) break;
  }
}


void
count_blocks(const Blocks & blocks) {

  /*
  for (Blocks::const_iterator it = blocks.begin(); it != blocks.end(); ++it) {
<<<<<<< HEAD
    h.add_to_bucket((*it).second.size());
    //std::cout << (*it).first << ", " << (*it).second.size() << std::endl;
=======
	  h.add_to_bucket((*it).second.size());
  }
  */

  for (auto block : blocks) {
    h.add_to_bucket(block.second.size());
  }
}


void
read_all_records() {

  //read_records();

  Timer t;

  vector<Record> records;
  string filename("/data/patentdata/patents/full/full.csv");
  ifstream is(filename.c_str());
  make_records_vector(is, records);

  //records[14324].print();
  //parse_records(records);

  //records[444].print_attributes();

  RecordPList rpl;
  get_record_pointers(records, rpl);

  const Record * rp = rpl.front();

  //rp->print_attributes();
  //cout << "Att: " << rp->attributes[0] << std::endl;

  Blocks blocks;
  //std::cout << "Blocks size: " << blocks.size() << std::endl;
  create_blocks(rpl, blocks);
  //std::cout << "Blocks size: " << blocks.size() << std::endl;

  count_blocks(blocks);

  h.print();

}

