void drawBox(Stack *this)
{
	Node *pointer = this->first;
	Point2D box;
	while (!isEmpty(pointer))
	{
		box = look(pointer);
		spr(BOX, box.x * 8, box.y * 8, 1, 1);
		pointer = pointer->next;
	}
}
static Node *find(Stack *this, Point2D position)
{
    Node *pointer = this->first;
    Point2D box;
    while (!isEmpty(pointer))
    {
        box = look(pointer);
        if (box.x == position.x && box.y == position.y)
        {
            return pointer;
        }
        pointer = pointer->next;
    }
    return NULL;
}