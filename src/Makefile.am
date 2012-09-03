
export GLIBCXX_FORCE_NEW=1

CC = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter

INCLUDES = -I../include

CPPUNIT_LIBS = $(shell cppunit-config --libs)
CPPUNIT_INCLUDES = $(shell cppunit-config --cflags)

LDFLAGS=$(CPPUNIT_LIBS) -lsqlite3

commit := $(shell git reflog -1)
branch := $(shell git show-branch --reflog=1)

bin_PROGRAMS = objects records

ALL = objects
ofiles = objects.o

#all: $(ofiles)
all: $(ALL)

$(ofiles): %.o: %.cpp
	echo $(commit)
	g++ $(CXXFLAGS) -c -D$*_STANDALONE $(CPPUNIT_INCLUDES) $<

objects_SOURCES = objects.cpp
records_SOURCES = records.cpp

clean:
	rm -rf *~ a.out $(ALL) $(ofiles) *.sqlite3
