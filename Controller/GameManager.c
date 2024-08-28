// Funciones & Procedimentos "PRINCIPALES"

void init(Game *this)
{
    initScreen();
    this->state = OPEN;
    stack(&this->boxes);
    this->board.map = NULL;
    this->player.box = NULL;
}
void draw(Game *this)
{
    switch (this->state)
    {
    case OPEN:
        beginScreen(&(Color){0xc2, 0xc3, 0xc7, 255});
        // drawTile(&Open);
        break;
    case OVER:
        beginScreen(&(Color){0xc2, 0xc3, 0xc7, 255});
        // drawTile(&End);
        break;
    default: // GAME/EXIT/OVER
        beginScreen(NULL);
        if(this->level ==0){
            int center = 10*8;
            font("Hecho en casa",center-(6*7),21);
            font("de Oto",center-(3*7),35);
            font("Salir",9,14*8-2);
        }
        if(this->level ==1){
            font("Pulse  para sujetar",10,12*8);
            font("o soltar la caja",4*8,13*8);
            font("Jugar",9,14*8-2);
        }
        drawTile(&this->board);
        drawBox(&(this->boxes));
        drawPlayer(&(this->player));
        break;
    }
    endScreen();
}
int update(Game *this)
{
    if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
    {
        this->state = EXIT;
        return 0;
    }
    static int MaxLevel = 0;
    switch (this->state)
    {
    case OPEN:
        destroyerGame(this);
        this->level = 1;
        MaxLevel = loadLevel(&this->board, this->level);
        parseElementsOfTile(this);
        this->state = GAME;
        return 1;
    case OVER:
        if (event.key.type == SDL_KEYDOWN)
        {
            this->state = EXIT;
            return 1;
        }
        return 0;
    default:
    case GAME:
        if (this->state == GAME)
        {
            int element = getElement(&this->board, this->player.position);
            if (element == DOOR || element == PREV)
            {
                this->level += element == DOOR ? 1 : -1;
                if (this->level == MaxLevel)
                {
                    this->state = OVER;
                }
                else
                {
                    destroyerGame(this);
                    loadLevel(&this->board, this->level);
                    parseElementsOfTile(this);
                }
                return 1;
            }
            SDL_Keycode key = 0;
            if (event.key.type == SDL_KEYDOWN)
            {
                key = event.key.keysym.sym;
            }
            return movePlayer(&this->player, &this->board, &this->boxes, key);
        }
        return 0;
    }
}
void destroyer(Game *this)
{
    destroyerGame(this);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

// Funciones & Procedimentos "publicos" - AUX
void destroyerGame(Game *this)
{
    if (!stackIsEmpty(&this->boxes))
    {
        this->player.box = NULL;
        destroyStack(&(this->boxes));
    }

    if (this->board.map != NULL)
    {
        free(this->board.map);
    }
}

void parseElementsOfTile(Game *this)
{
    int col, row, index, element;
    for (row = 0; row < this->board.height; row++)
    {
        index = row * this->board.width;
        for (col = 0; col < this->board.width; col++)
        {
            element = this->board.map[index + col];
            if (element != BLOCK && element != DOOR && element != PREV)
            {
                this->board.map[index + col] = element;
                if (element == BOX)
                {
                    stackPush(&this->boxes, (Point2D){col, row});
                    this->board.map[index + col] = 0;
                }
                else if (element == PLAYER)
                {
                    this->player.position = (Point2D){col, row};
                    this->player.vector = -1;
                    this->board.map[index + col] = 0;
                }
            }
        }
    }
}
