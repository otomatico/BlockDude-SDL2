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