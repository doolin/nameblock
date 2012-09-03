#ifndef INVENTIUM_RECORD_H
#define INVENTIUM_RECORD_H

#include <string>
#include <vector>

using std::string;
using std::vector;


class Record {
  private:
    string line;
    vector<string> attributes;
  public:
    Record(string l) : line(l) {}

    void print() {
      std::cout << line << std::endl;
    }
};



#endif // INVENTIUM_RECORD_H
