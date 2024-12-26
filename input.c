#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>

#include "input.h"

void input_home(Screen *screen) {
  screen->input = getch();

  switch (screen->input) {
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
    printf("Error: unhandled input command");
    endwin();
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
  default:
    break;
  }
  refresh();
}
