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
  /*  screen->input = getch();

   if (screen->insert_mode == false) {
     switch (screen->input) {
     case 'q':
       endwin();
       exit(EXIT_SUCCESS);
       break;
     default:
       break;
     }
   }
   refresh();
 */
}
