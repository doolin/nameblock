#include <ctime>
#include <stdint.h>

// TODO: move to header file
typedef struct _timer {
  uint32_t elapsed;
} Timer;

uint32_t
get_elapsed() {
  return 42;
}

#ifdef timer_STANDALONE
int
main(int, char **) {

  return 0;
}
#endif
