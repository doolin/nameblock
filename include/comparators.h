#ifndef PATENT_COMPARATORS_H
#define PATENT_COMPARATORS_H

#include <cstdint>
#include <string>
using std::string;

uint32_t compare_names    (string r1,
                           string r2);

uint32_t compare_locations(string r1,
                           string r2);

uint32_t compare_assignees(string r1,
                           string r2);

uint32_t compare_classes  (string r1,
                           string r2);

uint32_t compare_coauthors(string r1,
                           string r2);

#endif /* PATENT_COMPARATORS_H */
