//
// Created by James Carr on 01/02/2022.
//

#include "../include/types.h"

void draw_food(t_game *pGame) {
    SDL_SetRenderDrawColor(pGame->renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(pGame->renderer, &pGame->food);
}