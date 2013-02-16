#ifndef PATENT_COMPARATORS_H
#define PATENT_COMPARATORS_H

#include <cstdint>
#include <string>
using std::string;

// Probably move the compare_locations function
// to locations.cpp, a better place for it.
#include <location.h>

uint32_t compare_names    (string r1,
                           string r2);

uint32_t compare_locations(const Location l1,
                           const Location l2);

uint32_t compare_assignees(string r1,
                           string r2);

uint32_t compare_classes  (string r1,
                           string r2);

uint32_t compare_coauthors(string r1,
                           string r2);

#endif /* PATENT_COMPARATORS_H */
