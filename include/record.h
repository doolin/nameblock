#ifndef INVENTIUM_RECORD_H
#define INVENTIUM_RECORD_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <unordered_set>
#include <unordered_map>

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

//typedef map<string, RecordPList> Blocks;
//typedef std::unordered_set<string, RecordPList> Blocks;
typedef std::unordered_map<string, RecordPList> Blocks;
typedef Blocks::const_iterator c_blocks_iter_t;


void make_records_vector(std::ifstream & is, Records & r);
void get_record_pointers(const Records & r, RecordPList & rpl);
void create_blocks(const RecordPList & rpl, Blocks & blocks);

#endif // INVENTIUM_RECORD_H
