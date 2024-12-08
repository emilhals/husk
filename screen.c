#include "screen.h"
#include <ncurses.h>
#include <string.h>

void init_screen(Screen *screen) {
  initscr();
  init_colors();

  noecho();
  raw();
  curs_set(0);
  nodelay(stdscr, TRUE);
  keypad(stdscr, TRUE);

  screen->y = LINES;
  screen->x = COLS;
  screen->current_mode = 0;
  screen->menu_position = 0;
}

void display_screen(Screen *screen) {
  nodelay(stdscr, FALSE);
  switch (screen->current_mode) {
  case 0:
    print_home(screen);
    break;
  }
}

void destroy_screen(Screen *screen) {}

void print_home(Screen *screen) {
  char *items[] = {"View", "Add Cards", "Exit"};
  int n = sizeof(items) / sizeof(char *);

  int center_x, center_y;

  center_x = screen->x / 2;
  center_y = screen->y / 2;

  for (int i = 0; i < n; i++) {
    if (screen->menu_position == i) {
      mvprintw(center_y, center_x, "-> %s <-", items[i]);
    } else {
      mvprintw(center_y, center_x, "   %s   ", items[i]);
    }
    center_y++;
  }
  refresh();
}

void print_view_cards(Screen *screen) {}

void init_colors() {
  if (!has_colors()) {
    // endwin();
  }
  if (start_color() != OK) {
    // endwin();
  }
  init_pair(1, COLOR_RED, COLOR_BLACK);
  bkgd(COLOR_PAIR(1));
}
