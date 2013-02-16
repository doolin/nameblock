#ifndef PATENT_LOCATION_H
#define PATENT_LOCATION_H

#include <string>

class Location {

public:
  std::string * street;
  std::string * city;
  std::string * state;
  std::string * country;
  std::string * zipcode;
  // Let's convert these ahead of time and
  // store them explicitly, because that
  // will save a lot of run time conversion
  float latitude;
  float longitude;
};

#endif  /* PATENT_LOCATION_H */
