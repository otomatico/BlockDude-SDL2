#ifndef _TILEMAP_H_
#define _TILEMAP_H_

typedef struct _tileMap
{
	int lenght;
	Tile * Map;
}TileList;

/*
Load Tile
@param: this out Tile
@param: level id Tile
@return: Max level loaded 
 */
int loadLevel(Tile *this, int level);
void drawTile(Tile *this);
void drawBox(Stack *this);
int getElement(Tile *self, Point2D position);
int parse_Tile(TileList *this, char *filename);
#include "TileManager.c"
#endif