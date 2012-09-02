#include <string>
#include <vector>
#include <map>
#include <list>


class Tag {
  std::string label;
};

class Record {
  std::vector<std::string> features;
};

class Records {
  std::list<Record> record;
};

class Cluster {
  Records records;
};

class Clusters {
  std::list<Cluster> clusters;
};

class Block {
  Clusters clusters;
};

class Blocks {
  std::map<Tag, Block> blocks;
};

void
instantiate_all() {

  Tag * t = new Tag;
  delete(t);

  Record * r = new Record;
  delete(r);

  Records * rs = new Records;
  delete(rs);

  Cluster * c = new Cluster;
  delete(c);

  Clusters * cs = new Clusters;
  delete(cs);

  Block * b = new Block;
  delete(b);

  Blocks * bs = new Blocks;
  delete(bs);

}

#ifdef objects_STANDALONE
int
main(int argc, char ** argv) {

  instantiate_all();
  return 0;
}
#endif
