#ifndef _TDA_H
#define _TDA_H

#include <stdlib.h>

/**
 * TAD (Tipo Abstrato de Dato) Pilas, ~Listas~ y Colas
 * Esta es la forma correcta de definir un NODO,
 *  no re-invente que luego el compilador se queja que estas queriendo meter Macintosh en Apple
 * Se ha optado por esta definicion porque el reemplazo de TElement por Point2D ocurre antes de
 *  la compilacion lo que no ocurriria si usamos typedef que haria en tiempo de ejecucion
 **/
//#define TElement Point2D

typedef struct _link Node;
struct _link
{
	TElement value;
	Node *next;
};

// Node Method
int isEmpty(Node *this);
TElement look(Node *this);
int any(Node *this, TElement point);
Node *createNode(TElement value);
void destroyNode(Node *this);
#include "Node.c"

#ifndef _TDA_STACK_H_
#define _TDA_STACK_H_
// Lo mismo dicho en Nodo ahora para Pilas
typedef struct _stack
{
	Node *first;
} Stack;

// Stack Method
void stack(Stack *this);
int stackIsEmpty(Stack *this);
TElement stackLookaHead(Stack *this);
void stackPush(Stack *this, TElement value);
TElement stackPop(Stack *this);
int stackInclude(Stack *this, TElement point);
void stackDelete(Stack *this, TElement point);
void destroyStack(Stack *this);
#include "Stack.c"
#endif

#ifndef _TDA_TAIL_H_
#define _TDA_TAIL_H_
typedef struct _tail
{
	Node *first;
	Node *last;
} Tail;
// Tail Method
int tailIsEmpty(Tail *this);
TElement tailLookaHead(Tail *this);
void tailPush(Tail *this, TElement value);
TElement tailPop(Tail *this);
int tailInclude(Tail *this, TElement value);
void destroyTail(Tail *this);
#include "Tail.c"

typedef struct _list
{
	Node *first;
	Node *current;
	int Length;
} List;

#endif

// #include "Collection.c"
#endif