#ifndef CARD_H
#define CARD_H

#define CHAR_LIMIT 128

typedef struct s_card {
  int id;
  char back[CHAR_LIMIT];
  char front[CHAR_LIMIT];
  struct s_card *next;
} Card;

Card *create_card(char *, char *);
Card *display_cards();
Card *list_cards(char *);

void read_cards();
void save_card(Card *);

#endif
