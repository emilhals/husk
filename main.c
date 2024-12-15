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

  if (screen->insert_mode == false) {
    switch (screen->input) {
    case 'q':
      if (screen->input != -1)
        break;
      endwin();
      exit(EXIT_SUCCESS);
      break;
    case KEY_UP:
      if (screen->menu_position > 0)
        screen->menu_position--;
      break;
    case KEY_DOWN:
      if (screen->menu_position < 2)
        screen->menu_position++;
      break;
    case 10:
      if (screen->current_mode == 0) {
        if (screen->menu_position == 0) {
          screen->current_mode = 1;
        }
        if (screen->menu_position == 1) {
          screen->current_mode = 2;
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
}
