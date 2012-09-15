#include <ctime>

#include "timer.h"


uint32_t
Timer::get_elapsed() {
  return 42;
}

#ifdef timer_STANDALONE
int
main(int, char **) {

  Timer t;

  return 0;
}
#endif
