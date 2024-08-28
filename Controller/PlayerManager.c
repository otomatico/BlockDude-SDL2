void drawPlayer(Player *this)
{
    int n = this->vector > 0 ? 5 : 4;
    Point2D el = this->position;
    spr(n, el.x * 8, el.y * 8, 1, 1);
}

int movePlayer(Player *this, Tile *board, Stack *boxes, SDL_Keycode key) // SDL_KeyCode key = event.key.keysym.sym;
{
    int canDraw = 0;
    if (key != 0)
    {
        Point2D position = this->position;
        switch (key)
        {
        case KEY_LEFT:
            position.x--;
            this->vector = -1;
            break;
        case KEY_RIGHT:
            position.x++;
            this->vector = 1;
            break;
        case KEY_DOWN:
            position.y++;
            break;
        case KEY_UP:
            position.x += this->vector;
            break;
        }
        if (key != KEY_UP)
        {
            canDraw = changePosition(this, board, boxes, position);
        }
        else
        {
            canDraw = getBox(this, board, boxes, position);
        }
    }
    return gravity(this, board, boxes) || canDraw == 1;
}

static int changePosition(Player *player, Tile *board, Stack *boxes, Point2D position)
{

    int can = 0, element = getElement(board, position);
    Node *pointer = find(boxes, position);
    if (element == BLOCK || !isEmpty(pointer))
    {
        position.y--;
        element = getElement(board, position);
    }
    if (element == DOOR || element == EMPTY || element == PREV)
    {
        player->position = position;
        can = 1;
    }
    if (!isEmpty(player->box))
    {
        player->box->value = player->position;
        player->box->value.y--;
        can = 1;
    }
    return can;
}

static int getBox(Player *player, Tile *board, Stack *boxes, Point2D position)
{
    int can = 0;
    if (isEmpty(player->box))
    {
        Node *pointer = find(boxes, position);
        if (!isEmpty(pointer))
        {
            player->box = pointer;
            player->box->value = player->position;
            player->box->value.y--;
            can = 1;
        }
    }
    else
    {
        int element = getElement(board, position);
        Node *pointer = find(boxes, position);
        if (element == EMPTY && isEmpty(pointer))
        {
            player->box->value = position;
            player->box = NULL;
            can = 1;
        }
    }
    return can;
}

static int gravity(Player *player, Tile *board, Stack *boxes)
{
    Point2D position = player->position;
    position.y++;
    return changePosition(player, board, boxes, position);
}
