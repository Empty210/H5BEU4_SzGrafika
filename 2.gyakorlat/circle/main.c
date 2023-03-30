﻿#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include <math.h>
#include <stdlib.h>

/* ablak letrehozasa */
void sdl_init(char const *felirat, int szeles, int magas, SDL_Window **pwindow, SDL_Renderer **prenderer) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        SDL_Log("Nem indithato az SDL: %s", SDL_GetError());
        exit(1);
    }
    SDL_Window *window = SDL_CreateWindow(felirat, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, szeles, magas, 0);
    if (window == NULL) {
        SDL_Log("Nem hozhato letre az ablak: %s", SDL_GetError());
        exit(1);
    }
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (renderer == NULL) {
        SDL_Log("Nem hozhato letre a megjelenito: %s", SDL_GetError());
        exit(1);
    }
    SDL_RenderClear(renderer);

    *pwindow = window;
    *prenderer = renderer;
}


int main(int argc, char *argv[]) {

    int a=2;
    printf("%d",a);
    /* ablak letrehozasa */
    SDL_Window *window;
    SDL_Renderer *renderer;
    sdl_init("SDL peldaprogram", 440, 360, &window, &renderer);

    /* rajzok */
    int x, y, r;
    r = 50;

    /* karika */
    x = 100;
    y = 100;
    circleRGBA(renderer, x, y, r, 255, 0, 0, 255);
    circleRGBA(renderer, x + r, y, r, 0, 255, 0, 255);
    circleRGBA(renderer, x + r * cos(3.1415 / 3), y - r * sin(3.1415 / 3), r, 0, 0, 255, 255);

    /* antialias karika */
    x = 280;
    y = 100;
    aacircleRGBA(renderer, x, y, r, 255, 0, 0, 255);
    aacircleRGBA(renderer, x + r, y, r, 0, 255, 0, 255);
    aacircleRGBA(renderer, x + r * cos(3.1415 / 3), y - r * sin(3.1415 / 3), r, 0, 0, 255, 255);

    /* kitoltott kor */
    x = 100;
    y = 280;
    filledCircleRGBA(renderer, x, y, r, 255, 0, 0, 255);
    filledCircleRGBA(renderer, x + r, y, r, 0, 255, 0, 255);
    filledCircleRGBA(renderer, x + r * cos(3.1415 / 3), y - r * sin(3.1415 / 3), r, 0, 0, 255, 255);

    /* attetszo kor */
    x = 280;
    y = 280;
    filledCircleRGBA(renderer, x, y, r, 255, 0, 0, 96);
    filledCircleRGBA(renderer, x + r, y, r, 0, 255, 0, 96);
    filledCircleRGBA(renderer, x + r * cos(3.1415 / 3), y - r * sin(3.1415 / 3), r, 0, 0, 255, 96);

    /* szoveg */
    stringRGBA(renderer, 110, 350, "Kilepeshez: piros x az ablakon", 255, 255, 255, 255);

    /* az elvegzett rajzolasok a kepernyore */
    SDL_RenderPresent(renderer);

    /* varunk a kilepesre */
    SDL_Event ev;
    while (SDL_WaitEvent(&ev) && ev.type != SDL_QUIT) {
    }

    /* ablak bezarasa */
    SDL_Quit();

    return 0;
}
