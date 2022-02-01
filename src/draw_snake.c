//
// Created by James Carr on 30/01/2022.
//

#include <SDL2/SDL.h>
#include "../include/types.h"

#define ALIVE_SNAKE_COLOUR 0, 0, 0, 255
#define DEAD_SNAKE_COLOUR 180, 0, 0, 255

void draw_snake(t_game *pGame) {

    for (int i = 0; i < pGame->snake_arr_len; ++i) {
        if(pGame->snake[i].w != 0) {
            SDL_SetRenderDrawColor(pGame->renderer, ALIVE_SNAKE_COLOUR);
            SDL_RenderFillRect(pGame->renderer, &pGame->snake[i]);

            SDL_SetRenderDrawColor(pGame->renderer, 0, 127, 0, 255);
            SDL_RenderDrawRect(pGame->renderer, &pGame->snake[i]);
        }
        if(pGame->game_over) {
            SDL_SetRenderDrawColor(pGame->renderer, DEAD_SNAKE_COLOUR);
            SDL_RenderFillRect(pGame->renderer, &pGame->snake[i]);

            SDL_SetRenderDrawColor(pGame->renderer, 0, 0, 255, 255);
            SDL_RenderDrawRect(pGame->renderer, &pGame->snake[i]);
        }
    }

}
