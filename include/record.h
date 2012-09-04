#ifndef INVENTIUM_RECORD_H
#define INVENTIUM_RECORD_H

#include <string>
#include <vector>

using std::string;
using std::vector;


class Record {

  public:

    vector<string> attributes;

    explicit Record(string l) : line(l) {
      parse_line();
    }

    void parse_line();

    void print_attributes();

    void print() {
      std::cout << line << std::endl;
    }

  private:
    string line;

};



#endif // INVENTIUM_RECORD_H
