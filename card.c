#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "card.h"

Card *create_card(char front_text[], char back_text[]) {
  Card *card = malloc(sizeof(Card));

  if (card == NULL) {
    endwin();
    printf("Failed to allocate memory to new card");
    exit(EXIT_FAILURE);
  }

  /* card data */
  strcpy(card->front, front_text);
  strcpy(card->back, back_text);
  card->id = rand();

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

  file = fopen("cards.txt", "ab");

  fprintf(file, "%d %s %s\n", card->id, card->front, card->back);

  fclose(file);
  free(card);
}

Card *show_card() {
  Card *card;

  char line[100];
  int id;
  char *front;
  char *back;

  FILE *file;
  file = fopen("cards.txt", "r");

  while (fgets(line, sizeof(line), file)) {
    char *idStr = strtok(line, " \t\n");
    if (idStr == NULL)
      continue;
    id = atoi(idStr);

    front = strtok(line, " \t\n");
    if (front == NULL)
      continue;

    back = strtok(line, " \t\n");
    if (back == NULL)
      continue;
  }

  strcpy(card->front, front);
  strcpy(card->back, back);

  return card;
}
