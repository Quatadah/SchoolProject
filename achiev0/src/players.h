#ifndef __PLAYERS_H__
#define __PLAYERS_H__

#define MAX_PLAYERS 20
#define MAX_BOARD_SIZE 50
#include "queue.h"
#include "tile.h"
#include "color.h"

struct player{
  Queue *cards;
};

struct players{
  struct player player[MAX_PLAYERS];
  int length;
  int rank;
};

struct board{
  const struct tile* places[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
  int size;
};

struct positions{
  int i[MAX_BOARD_SIZE*MAX_BOARD_SIZE];
  int j[MAX_BOARD_SIZE*MAX_BOARD_SIZE];
  int length;
};

struct players players_init(int n);

struct board board_init(int b);

struct player get_next_player(struct players *p);

void split_deck(struct deck *d, struct players *p);

int oppose_Direction(int n);

struct positions list_authorized_places(struct board *b, const struct tile *t); 

int is_empty(struct positions *p);

struct positions select_position(struct positions p);

void place_tile(struct board *b, struct positions p, const struct tile *t);

void display_results(struct players *p);

void freeAll(struct players *p);

#endif