#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>

#include "input.h"

void handle_input(Screen *screen) {}

void input_home(Screen *screen) {
  screen->input = getch();

  cbreak();
  noecho();
  switch (screen->input) {
  case 'k':
  case KEY_UP:
    if (screen->menu_position > 0)
      screen->menu_position--;
    break;
  case 'j':
  case KEY_DOWN:
    if (screen->menu_position < 2)
      screen->menu_position++;
    break;
  case 'q':
    endwin();
    exit(EXIT_SUCCESS);
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
  refresh();
}

void input_view_cards(Screen *screen) {
  screen->input = getch();

  switch (screen->input) {
  case 'q':
    endwin();
    exit(EXIT_SUCCESS);
    break;
  default:
    break;
  }
  refresh();
}
