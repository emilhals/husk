#define _XOPEN_SOURCE_EXTENDED 1
#include <ncurses.h>
#include <stdlib.h>

#include "screen.h"
#include "utils.h"

void handle_input(Screen *);

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

void handle_input(Screen *screen) {
  screen->input = getch();

  switch (screen->input) {
  case KEY_UP:
  case 'k':
    if (screen->menu_position > 0)
      screen->menu_position--;
    break;
  case KEY_DOWN:
  case 'j':
    if (screen->menu_position < 2)
      screen->menu_position++;
    break;
  case 'q':
    if (getch() != -1)
      break;
    endwin();
    exit(EXIT_SUCCESS);
    break;
  case 10:
    if (screen->current_mode == 0) {
      if (screen->menu_position == 0) {
        printw("View cards");
      }
      if (screen->menu_position == 1) {
        printw("Add cards");
      }
      if (screen->menu_position == 2) {
        endwin();
        exit(EXIT_FAILURE);
      }
      break;
    }
  default:
    break;
  }
}
