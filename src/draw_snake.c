//
// Created by James Carr on 30/01/2022.
//

#include "../include/types.h"

#define ALIVE_SNAKE_COLOUR 0, 0, 0, 255
#define DEAD_SNAKE_COLOUR 180, 0, 0, 255

void draw_snake(t_game const *const pGame) {
    SDL_Rect shadow[pGame->snake_arr_len];

    for (int i = 0; i < pGame->snake_arr_len; ++i) {
        if(pGame->snake[i].w != 0) {
            shadow[i] = pGame->snake[i];
            shadow[i].x += 2;
            shadow[i].y += 2;

            SDL_SetRenderDrawBlendMode(pGame->renderer, SDL_BLENDMODE_BLEND);
            SDL_SetRenderDrawColor(pGame->renderer, 100,100,100,200);
            SDL_RenderFillRect(pGame->renderer, &shadow[i]);

            // Snake body
            SDL_SetRenderDrawColor(pGame->renderer, ALIVE_SNAKE_COLOUR);
            SDL_RenderFillRect(pGame->renderer, &pGame->snake[i]);

            // Snake segment border
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
