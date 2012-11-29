
export GLIBCXX_FORCE_NEW=1

CC = g++
CXXFLAGS = -std=c++11 -O3 -Wall -Wextra -Wno-unused-parameter

INCLUDES = -I../include

CPPUNIT_LIBS = $(shell cppunit-config --libs)
CPPUNIT_INCLUDES = $(shell cppunit-config --cflags)

LDFLAGS=$(CPPUNIT_LIBS) -lsqlite3

commit := $(shell git reflog -1)
branch := $(shell git show-branch --reflog=1)

bin_PROGRAMS = objects records timer
objects_SOURCES = objects.cpp
records_SOURCES = records.cpp
timer_SOURCES   = timer.cpp

noinst_LIBRARIES = libblocking.a libtimer.a
libblocking_a_SOURCES = records.cpp
libtimer_a_SOURCES = timer.cpp

ALL = objects
ofiles = objects.o records.o timer.o

#all: $(ofiles)
all: $(ALL)

#$(ofiles): %.o: %.cpp
%.o: %.cpp
	echo $(commit)
	g++ $(CXXFLAGS) -c $(INCLUDES) -D$*_STANDALONE $(CPPUNIT_INCLUDES) $<

clean:
	rm -rf *~ a.out $(ALL) $(ofiles) *.sqlite3
