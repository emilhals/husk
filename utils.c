#include <locale.h>
#include <ncurses.h>

void init_ncurses() { setlocale(LC_CTYPE, "en_US.UTF-8"); }
