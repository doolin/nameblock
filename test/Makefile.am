
AM_CPPFLAGS = -I../include -I/opt/local/include

AM_CXXFLAGS = -O0 -g -Wall -Wextra -ansi -std=c++11 -Wformat-zero-length

LDADD = ../src/libblocking.a
AM_LDFLAGS = $(shell cppunit-config --libs)


TESTS = objects records

bin_PROGRAMS = $(TESTS)

%.o: %.cpp
	g++ $(AM_CPPFLAGS) $(AM_CXXFLAGS) -D$*_STANDALONE -c $<

#COMMON = testdata.cpp

objects_SOURCES = test_objects.cpp
#objects_LDADD = $(LDADD)
records_SOURCES = test_record.cpp testutils.cpp

relink:
	rm -rf $(TESTS)

