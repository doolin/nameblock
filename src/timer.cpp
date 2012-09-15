#include <ctime>
#include <stdint.h>

#include "timer.h"

// TODO: move to header file
struct _timer {
  uint32_t elapsed;
};

uint32_t
get_elapsed() {
  return 42;
}

#ifdef timer_STANDALONE
int
main(int, char **) {

  Timer t;

  return 0;
}
#endif
