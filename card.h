#ifndef CARD_H
#define CARD_H

#define CHAR_LIMIT 100

typedef struct Card {
  char back[CHAR_LIMIT];
  char front[CHAR_LIMIT];
} Card;

Card *create_card(char[], char[]);

#endif
