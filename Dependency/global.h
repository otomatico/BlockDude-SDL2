/* Se pretende usar esta paleta de colores es ma misma de PICO-8  los colores de 0-15 y de 128-143
 char pallete_str[][8]={

    "#000000", "#1d2b53", "#7e2553", "#008751",
    "#ab5236", "#5f574f", "#c2c3c7", "#fff1e8",
    "#ff004d", "#ffa300", "#ffec27", "#00e436",
    "#29adff", "#83769c", "#ff77a8", "#ffccaa", 0-15

    "#291814", "#111d35", "#422136", "#125359", 16-31
    "#742f29", "#49333b", "#a28879", "#f3ef7d",
    "#be1250", "#ff6c24", "#a8e72e", "#00b543",
    "#065ab5", "#754665", "#ff6e59", "#ff9d81"
 };
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _GLOBAL_H
#define _GLOBAL_H

#include <SDL2/SDL.h>

#define _TDA_TAIL_H_
#define newArray(_type, _size) (_type *)calloc((_size), sizeof(_type))
#define newElement(_type) (_type *)malloc(sizeof(_type))

#define PATH_SPRITE ".\\etc\\blockdude-sprite.bmp"
#define PATH_ALPHABETIC ".\\etc\\charmap.bmp"
#define PATH_MAP ".\\etc\\maptile.txt"

#define KEY_UP SDLK_UP
#define KEY_RIGHT SDLK_RIGHT
#define KEY_DOWN SDLK_DOWN
#define KEY_LEFT SDLK_LEFT
#define KEY_SPACE SDLK_SPACE
#define KEY_ESCAPE SDLK_ESCAPE
// Constantes
#define delay(a) SDL_Delay(a)
// 320x240 => 40x30 sprites 8x8
// 320x200 => 40x25 sprites 8x8
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 280
// TIPOS
typedef SDL_Color Color;
typedef struct SDL_Point Point2D, TElement;
// VARIABLES
SDL_Event event;
SDL_Renderer *renderer;
SDL_Window *window;
// PROCEDIMENTOS
void initScreen();
void beginScreen(Color *color);
void endScreen();
void spr(Uint8 n, int x, int y, int w, int h);

// Implementacion
SDL_Texture *loadSprite(char *filenameBMP);

SDL_Texture *loadSprite(char *filenameBMP)
{
    SDL_Texture *texture = NULL;
    SDL_Surface *surface = SDL_LoadBMP(filenameBMP);
    if (surface != NULL)
    {
        texture = SDL_CreateTextureFromSurface(renderer, surface);
    }
    return texture;
}

void spr(Uint8 n, int x, int y, int w, int h)
{
    static SDL_Texture *textureSprite = NULL;
    if (textureSprite == NULL)
    {
        SDL_Surface *surfaceSprite = SDL_LoadBMP(PATH_SPRITE);
        if (surfaceSprite != NULL)
        {
            SDL_SetColorKey(surfaceSprite, SDL_TRUE, 0);
            textureSprite = SDL_CreateTextureFromSurface(renderer, surfaceSprite);
            SDL_FreeSurface(surfaceSprite);
        }
    }
    if (n > 0)
    {
        int MaxWidth, MaxHeight;
        SDL_QueryTexture(textureSprite, NULL, NULL, &MaxWidth, &MaxHeight);
        MaxWidth /= 8;
        int cx = n % MaxWidth,
            cy = (n - cx) / MaxWidth,
            width = w * 8,
            height = h * 8;
        SDL_Rect clip = (SDL_Rect){cx * 8, cy * 8, width, height};
        SDL_Rect screen = (SDL_Rect){x, y, width, height};
        SDL_RenderCopy(renderer, textureSprite, &clip, &screen);
    }
}

void font(char *text, int x, int y)
{
    static SDL_Texture *Alphabetic = NULL;
    char alphaText[] = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
    if (Alphabetic == NULL)
    {
        SDL_Surface *surfaceSprite = SDL_LoadBMP(PATH_ALPHABETIC);
        if (surfaceSprite != NULL)
        {
            SDL_SetColorKey(surfaceSprite, SDL_TRUE, 0);
            Alphabetic = SDL_CreateTextureFromSurface(renderer, surfaceSprite);
            SDL_FreeSurface(surfaceSprite);
        }
    }
    const int MaxWidth = 18,
              width = 7,
              height = 9;
    for (int index = 0; text[index] != '\0'; index++)
    {
        int n = 0;
        while (text[index] != alphaText[n] && n < 97)
        {
            n++;
        }
        int cx = n % MaxWidth,   cy = (n - cx) / MaxWidth;

        SDL_Rect clip = (SDL_Rect){cx * width, cy * height, width, height};
        SDL_Rect screen = (SDL_Rect){x + index * width, y, width, height};
        //SDL_Log("Sprite %c=>{%d,%d,%d,%d}\n", text[index], clip.x, clip.y, clip.w, clip.h);
        SDL_RenderCopy(renderer, Alphabetic, &clip, &screen);
    }
}

void initScreen()
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_JOYSTICK);
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);
    SDL_SetWindowTitle(window, "Block Dude - SDL2");
    SDL_RenderSetScale(renderer, 2.0, 2.0);
    beginScreen(NULL);
}

void beginScreen(Color *color)
{
    if (color == NULL)
    {
        color = &(Color){0, 0, 0, 255};
    }
    SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a);
    SDL_RenderClear(renderer);
}

void endScreen()
{
    SDL_RenderPresent(renderer);
}
#else
#include "../Model/Point2D.h"
#endif

#include "../Model/Collection.h"
#include "../Model/EnumGameState.h"
#include "../Model/Player.h"
#include "../Model/Tile.h"

#include "../Controller/BoxManager.h"
#include "../Controller/GameManager.h"
#include "../Controller/PlayerManager.h"
#include "../Controller/TileManager.h"
