#ifndef SCREEN_H
#define SCREEN_H

typedef struct Screen {
  int width, height;
  int x, y;
  int current_mode;
  int menu_position;
  int input;
  int input_mode;
  int running;
  bool insert_mode;

} Screen;

void init_screen(Screen *);
void destroy_screen(Screen *);
void display_screen(Screen *);

void print_view_cards(Screen *);
void print_add_card(Screen *);
void print_home(Screen *);

void init_colors();

#endif
