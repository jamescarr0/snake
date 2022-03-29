//
// Created by James Carr on 01/02/2022.
//

#include "../include/types.h"

void draw_food(Game const *const pGame) {
    SDL_Rect shadow;

    shadow = pGame->food;
    shadow.x += 3;
    shadow.y += 3;

    // Draw drop shadow
    SDL_SetRenderDrawBlendMode(pGame->renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(pGame->renderer, 0, 0, 0, 200);
    SDL_RenderFillRect(pGame->renderer, &shadow);

    // Draw food
    SDL_SetRenderDrawColor(pGame->renderer, 255, 90, 0, 255);
    SDL_RenderFillRect(pGame->renderer, &pGame->food);
}