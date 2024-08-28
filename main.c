#define SDL_MAIN_HANDLED
#include "Dependency/global.h"

int main(int argc, char **argv)
{
    Game game;

    int canDraw = 1;
    init(&game);
    while (game.state != EXIT)
    {
        if (canDraw != 0)
        {
            draw(&game);
        }
        canDraw = update(&game);
        delay(1000 / _FPS_);
    }
    destroyer(&game);
    return EXIT_SUCCESS;
}

