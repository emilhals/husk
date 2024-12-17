#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "card.h"

Card *create_card(char front_text[], char back_text[]) {
  Card *card;
  card = malloc(sizeof(Card));

  if (card == NULL) {
    printf("Failed to allocate memory to new card");
    exit(EXIT_FAILURE);
  }

  strcpy(card->front, front_text);
  strcpy(card->back, back_text);

  save_card(card);

  return card;
}

void save_card(Card *card) {
  if (card == NULL) {
    endwin();
    puts("Could not find card!");
    exit(EXIT_FAILURE);
  }

  FILE *file;

  file = fopen("cards.txt", "w");

  fprintf(file, "%s", card->front);

  fclose(file);
  free(card);
}

Card *show_card(int id) {
  Card *card;

  return card;
}
