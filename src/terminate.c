//
// Created by James Carr on 30/01/2022.
//

#include <SDL2/SDL.h>
#include "../include/types.h"

void terminate(t_game *pGame, int exit_code)
{
    if (pGame->renderer)
    {
        SDL_DestroyRenderer(pGame->renderer);
    }
    if (pGame->window)
    {
        SDL_DestroyWindow(pGame->window);
    }

    SDL_Quit();
    exit(exit_code);
}