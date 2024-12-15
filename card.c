#include <stdio.h>
#include <stdlib.h>

#include "card.h"

Card *create_card(char front_text[], char back_text[]) {
  Card *card;
  card = malloc(sizeof(Card));

  if (card == NULL) {
    printf("Failed to allocate memory to new card");
    exit(EXIT_FAILURE);
  }

  card->front[100] = front_text[100];
  card->back[100] = back_text[100];

  return card;
}
