//
// Created by James Carr on 30/01/2022.
//

#include <SDL2/SDL.h>
#include "../include/types.h"

#define SNAKE_COLOUR 0, 0, 0, 255

void draw_snake(t_game *pGame) {

    for (int i = 0; i < pGame->snake_arr_len; ++i) {
        if(pGame->snake[i].w != 0) {
            SDL_SetRenderDrawColor(pGame->renderer, SNAKE_COLOUR);
            SDL_RenderFillRect(pGame->renderer, &pGame->snake[i]);
        }
    }

}
