// Node Method
int isEmpty(Node *this)
{
	return this == NULL;
}

TElement look(Node *this)
{
	return this->value;
}

int any(Node *this, TElement point)
{
	int exist = 0;
	TElement head;
	while (this != NULL && !exist)
	{
		head = look(this);
		exist = (head.x == point.x && head.y == point.y);
		this = this->next;
	}
	return exist;
}

Node *createNode(TElement value)
{
	Node *newbie = (Node *)malloc(sizeof(Node));
	newbie->value = value;
	newbie->next = NULL;
	return newbie;
}
void destroyNode(Node *this)
{
	if (!isEmpty(this))
	{
		free(this);
	}
}
// Stack Method
void stack(Stack *this)
{
	this->first=NULL;
}
int stackIsEmpty(Stack *this)
{
	return isEmpty(this->first);
}

TElement stackLookaHead(Stack *this)
{
	return look(this->first);
}

void stackPush(Stack *this, TElement value)
{
	Node *newbie = createNode(value);
	newbie->next = this->first;
	this->first = newbie;
}

TElement stackPop(Stack *this)
{
	TElement value;
	if (!isEmpty(this->first))
	{
		value = stackLookaHead(this);
		Node *erase = this->first;
		this->first = this->first->next;
		free(erase);
	}
	return value;
}

int stackInclude(Stack *this, TElement point)
{
	Node *pointer = this->first;
	return any(pointer, point);
}

void stackDelete(Stack *this, TElement point)
{
	if (!stackIsEmpty(this))
	{
		TElement head = stackPop(this);
		if (!(head.x == point.x && head.y == point.y))
		{
			stackDelete(this, point);
			stackPush(this, head);
		}
	}
}

void destroyStack(Stack *this)
{

	Node *pointer = this->first, *erase;
	while (!isEmpty(pointer))
	{
		erase = pointer;
		pointer = pointer->next;
		destroyNode(erase);
	}
	this->first=NULL;
}

// Tail Method
int tailIsEmpty(Tail *this)
{
	return isEmpty(this->first);
}

TElement tailLookaHead(Tail *this)
{
	return look(this->last);
}

void tailPush(Tail *this, TElement value)
{
	Node *newbie = createNode(value);
	if (this->first == NULL)
	{
		this->first = newbie;
	}
	if (this->last != NULL)
	{
		this->last->next = newbie;
	}
	this->last = newbie;
}

TElement tailPop(Tail *this)
{
	TElement head;
	if (!isEmpty(this->first))
	{
		head = tailLookaHead(this);
		Node *erase = this->first;
		this->first = this->first->next;
		free(erase);
	}

	return head;
}

int tailInclude(Tail *this, TElement value)
{
	Node *pointer = this->first;
	return any(pointer, value);
}

void destroyTail(Tail *this)
{
	// destroyNode(this->first);
	while (!tailIsEmpty(this))
	{
		tailPop(this);
	}
}
