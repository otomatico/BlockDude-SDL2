#ifndef _GAMEMNG_H_
#define _GAMEMNG_H_
#define _FPS_ 10

typedef struct _dudeGame
{
    Uint8 FPS;
    Uint16 level;
    EnumGameState state;
    Player player;
    Stack boxes;
    Tile board;
} Game;

void init(Game *this);
void draw(Game *this);
int update(Game *this);
void destroyer(Game *this);

void destroyerGame(Game *this);
void parseElementsOfTile(Game *this);

#include "GameManager.c"
#endif