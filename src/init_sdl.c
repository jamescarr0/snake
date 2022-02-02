//
// Created by James Carr on 30/01/2022.
//

#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include "../include/types.h"
#include "../include/terminate.h"

bool init_sdl(t_game *pGame)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        printf("Error: failed to initialize SDL: %s\n", SDL_GetError());
        terminate(pGame, EXIT_FAILURE);
    }

    // Create a game window.
    pGame->window = SDL_CreateWindow("Score: 0",
                                     SDL_WINDOWPOS_UNDEFINED,
                                     SDL_WINDOWPOS_UNDEFINED,
                                     pGame->screen_width,
                                     pGame->screen_height,
                                     SDL_WINDOW_SHOWN);
    if (!pGame->window)
    {
        printf("Error: failed to create renderer %s\n", SDL_GetError());
        terminate(pGame, EXIT_FAILURE);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    pGame->renderer = SDL_CreateRenderer(pGame->window, -1, SDL_RENDERER_ACCELERATED);

    if (!pGame->renderer)
    {
        printf("error: failed to create renderer: %s\n", SDL_GetError());
        terminate(pGame, EXIT_FAILURE);
    }

    // Init Audio and set filepaths to sound effects.
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    pGame->sfx_eat = Mix_LoadMUS("/Users/james/Desktop/sfx1.mp3");

    return true;
}
