#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "card.h"
#include "screen.h"

void init_screen(Screen *screen) {
  initscr();

  init_colors();

  raw();
  curs_set(0);
  nodelay(stdscr, TRUE);
  keypad(stdscr, TRUE);

  screen->y = LINES;
  screen->x = COLS;
  screen->current_mode = 0;
  screen->menu_position = 0;
  screen->insert_mode = false;
}

void display_screen(Screen *screen) {
  erase();

  box(stdscr, 10, 10);
  switch (screen->current_mode) {
  case 0:
    print_home(screen);
    break;
  case 1:
    print_view_cards(screen);
    break;
  case 2:
    print_add_card(screen);
    break;
  }

  refresh();
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
      mvprintw(center_y, (screen->x - strlen(items[i])) / 2, "-> %s <-",
               items[i]);
    } else {
      mvprintw(center_y, (screen->x - strlen(items[i])) / 2, "   %s   ",
               items[i]);
    }
    center_y++;
  }
  refresh();
}

void print_add_card(Screen *screen) {
  char *front_text = malloc(128);
  char *back_text = malloc(128);

  int ch;

  screen->insert_mode = true;
  curs_set(1);
  WINDOW *front_win;
  WINDOW *back_win;
  front_win =
      newwin(screen->y / 2, screen->x / 2, screen->y / 4, screen->x / 4);

  back_win = newwin(screen->y / 2, screen->x / 2, screen->y / 4, screen->x / 4);

  if (front_win == NULL || back_win == NULL) {
    printf("%s", "Failed to create card window.");
    exit(EXIT_FAILURE);
  }

  box(front_win, 0, 0);

  waddstr(front_win, "Front: ");
  wgetnstr(front_win, front_text, 127);

  getch();
  wrefresh(front_win);

  box(back_win, 0, 0);

  waddstr(back_win, "Back: ");
  wgetnstr(back_win, back_text, 127);
  getch();

  Card *card = create_card(front_text, back_text);

  curs_set(0);
  screen->current_mode = 0;
  screen->insert_mode = false;
  touchwin(stdscr);
}

void print_view_cards(Screen *screen) {
  screen->insert_mode = false;

  printw("View cards");
}

void print_info(Screen *screen) {

  WINDOW *bottom;

  bottom = newwin(LINES / 2, COLS / 2, LINES / 4, COLS / 4);

  mvprintw(0, 0, "%d", screen->insert_mode);
}

void init_colors() {
  if (!has_colors()) {
    endwin();
  }
  if (start_color() != OK) {
    endwin();
  }
  init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
  bkgd(COLOR_PAIR(1));
}
