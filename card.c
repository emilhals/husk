#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "card.h"

Card *head;

Card *create_card(char *front, char *back) {
  Card *card = malloc(sizeof(Card));

  if (card == NULL) {
    endwin();
    printf("Failed to allocate memory to new card");
    exit(EXIT_FAILURE);
  }

  /* card data */
  strcpy(card->front, front);
  strcpy(card->back, back);
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

  file = fopen("cards.csv", "ab");

  fprintf(file, "%d;%s;%s\n", card->id, card->front, card->back);

  fclose(file);
  free(card);
}

void add_card(int id, char *front, char *back) {
  Card *p, *new;

  if (!head) {
    p = malloc(sizeof(Card));
    memset(p, 0, sizeof(Card));
    strncpy(p->front, front, 127);
    strncpy(p->back, back, 127);
    p->id = id;
    p->next = 0;
    head = p;

    return;
  }

  for (p = head; p->next; p = p->next)
    ;
  new = malloc(sizeof(Card));
  memset(new, 0, sizeof(Card));
  strncpy(new->front, front, 127);
  strncpy(new->back, back, 127);
  new->id = id;
  new->next = 0;

  p->next = new;

  return;
}

Card *list_cards(char *search_string) {
  Card *p;

  for (p = head; p; p = p->next) {
    if (!search_string || !strcmp(search_string, p->front)) {
      return p;
    }
  }

  return 0;
}

void read_cards() {
  Card *card = malloc(sizeof(Card));

  char line[100];
  int id;
  char *token;
  char *row;
  char *front;
  char *back;

  FILE *file;
  file = fopen("cards.csv", "r");

  if (file == NULL) {
    perror("Error opening file");
    endwin();
    exit(EXIT_FAILURE);
  }

  while (fgets(row, 128, file)) {
    token = strtok(row, ";");
    id = atoi(token);

    token = strtok(NULL, ";");
    front = token;

    token = strtok(NULL, ";");
    back = token;

    add_card(id, front, back);
  }

  fclose(file);
}
