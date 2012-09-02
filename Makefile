
export GLIBCXX_FORCE_NEW=1

CC = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter

CPPUNIT_LIBS = $(shell cppunit-config --libs)
CPPUNIT_INCLUDES = $(shell cppunit-config --cflags)

LDFLAGS=$(CPPUNIT_LIBS) -lsqlite3

commit := $(shell git reflog -1)
branch := $(shell git show-branch --reflog=1)

ALL = colortest sqlite disambiguation similarity objects mapkeys interface
ofiles = objects.o sqlite.o disambiguation.o similarity.o colortest.o mapkeys.o \
				 interface.o

#all: $(ofiles)
all: $(ALL)

$(ofiles): %.o: %.cpp
	echo $(commit)
	g++ $(CXXFLAGS) -c -D$*_STANDALONE $(CPPUNIT_INCLUDES) $<

clean:
	rm -rf *~ a.out $(ALL) $(ofiles) *.sqlite3
