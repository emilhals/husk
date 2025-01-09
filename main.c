#define _XOPEN_SOURCE_EXTENDED 1
#include <ncurses.h>

#include "input.h"
#include "screen.h"
#include "utils.h"

int main(void) {
  init_ncurses();
  init_colors();

  Screen screen;
  init_screen(&screen);

  while (1) {
    handle_input(&screen);

    display_screen(&screen);

    napms(1000 / 60);
  }

  endwin();
  return 0;
}
