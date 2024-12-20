#ifndef CARD_H
#define CARD_H

#define CHAR_LIMIT 100

typedef struct Card {
  int id;
  char back[CHAR_LIMIT];
  char front[CHAR_LIMIT];
  struct Card *next;
} Card;

Card *create_card(char[], char[]);
Card *show_card();

void save_card(Card *);

#endif
