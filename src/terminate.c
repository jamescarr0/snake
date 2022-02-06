//
// Created by James Carr on 30/01/2022.
//

#include "../include/types.h"

void terminate(t_game *const pGame, int const exit_code)
{
    if (pGame->renderer)
    {
        SDL_DestroyRenderer(pGame->renderer);
    }
    if (pGame->window)
    {
        SDL_DestroyWindow(pGame->window);
    }

    Mix_Quit();
    Mix_FreeMusic(pGame->sfx_score_point);
    Mix_FreeMusic(pGame->sfx_game_over);
    Mix_CloseAudio();

    free(pGame->snake);
    free(pGame);

    TTF_Quit();
    SDL_Quit();

    if(exit_code == 0) {
        return;
    } else {
        exit(exit_code);
    }
}