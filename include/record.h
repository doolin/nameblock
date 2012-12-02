#ifndef INVENTIUM_RECORD_H
#define INVENTIUM_RECORD_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

using std::string;
using std::vector;
using std::list;

class Record {

  public:

    vector<string> attributes;

    explicit Record(string l) : line(l) {
      parse_line();
    }

    void parse_line();

    void print_attributes() const;

    void print() {
      std::cout << line << std::endl;
    }

  private:
    string line;

};

typedef list<const Record*> RecordPList;
typedef vector<Record> Records;

void make_records_vector(std::ifstream & is, Records & r);

#endif // INVENTIUM_RECORD_H
