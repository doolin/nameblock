
INCLUDES = -I../include -I/opt/local/include

AM_CXXFLAGS = -O0 -g -Wall -Wextra -ansi  -Wformat-zero-length

#LDADD = ../src/libblocking.a
AM_LDFLAGS = $(shell cppunit-config --libs)


TESTS = objects

bin_PROGRAMS = $(TESTS)

%.o: %.cpp
	g++ $(INCLUDES) $(AM_CXXFLAGS) -D$*_STANDALONE -c $<

#COMMON = testdata.cpp

objects_SOURCES = test_objects.cpp
#objects_LDADD = $(LDADD)

relink:
	rm -rf $(TESTS)

