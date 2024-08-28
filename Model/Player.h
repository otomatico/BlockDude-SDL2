#ifndef _PLAYER_H_
#define _PLAYER_H_

typedef struct _dudePlayer
{
	Point2D position;
	int vector;
	Node *box;
} Player;

#endif
