//
// Created by James Carr on 30/01/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include "../include/types.h"
#include "../include/terminate.h"

#ifdef _WIN32
#include <windows.h>
#endif

bool init_sdl(t_game *const pGame) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        printf("Error: failed to initialize SDL: %s\n", SDL_GetError());
        terminate(pGame, EXIT_FAILURE);
    }

    if (TTF_Init() < 0) {
        printf("Error: failed to initialize SDL_TTF: %s\n", TTF_GetError());
        terminate(pGame, EXIT_FAILURE);
    }

    // Create a game window.
    pGame->window = SDL_CreateWindow("SNAKE",
                                     SDL_WINDOWPOS_UNDEFINED,
                                     SDL_WINDOWPOS_UNDEFINED,
                                     pGame->screen_width,
                                     pGame->screen_height,
                                     SDL_WINDOW_SHOWN);
    if (!pGame->window) {
        printf("Error: failed to create renderer %s\n", SDL_GetError());
        terminate(pGame, EXIT_FAILURE);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    pGame->renderer = SDL_CreateRenderer(pGame->window, -1, SDL_RENDERER_ACCELERATED);

    if (!pGame->renderer) {
        printf("error: failed to create renderer: %s\n", SDL_GetError());
        terminate(pGame, EXIT_FAILURE);
    }

    // Open and Load Audio
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 512);
    pGame->sfx_score_point = Mix_LoadMUS("../sounds/score_point.mp3");
    pGame->sfx_game_over = Mix_LoadMUS("../sounds/game_over.mp3");

    // Load fonts.
    char *font = "../fonts/orange-kid.ttf";
    char abspath[256];
    char *pAbsFontPath;

#ifdef _WIN32
    pAbsFontPath = GetFullPathName(font, 256, abspath, "");
#else
    pAbsFontPath = realpath(font, abspath);
#endif

    pGame->font = TTF_OpenFont(pAbsFontPath, 48);
    if (!pGame->font) {
        printf("TTF Error: %s\n", TTF_GetError());
    }

    return true;
}
