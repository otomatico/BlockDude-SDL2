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
