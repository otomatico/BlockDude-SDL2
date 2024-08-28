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