#ifndef _PLAYERMNG_H_
#define _PLAYERMNG_H_

static int changePosition(Player *player, Tile *board, Stack *boxes, Point2D position);
static int getBox(Player *player, Tile *board, Stack *boxes, Point2D position);
static int gravity(Player *player, Tile *board, Stack *boxes);

int movePlayer(Player *this, Tile *tile, Stack *elements, SDL_Keycode key);
void drawPlayer(Player *this);

#include "PlayerManager.c"
#endif