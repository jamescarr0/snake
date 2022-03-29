//
// Created by James Carr on 31/01/2022.
//

#include "../include/types.h"

void change_direction(Game *const pGame, SDL_Keycode const btn_pressed) {

    switch (btn_pressed) {
        case SDLK_UP:
            if (pGame->snake[0].y - pGame->snake_seg_size == pGame->snake[1].y)
                break; // Stop snake turning into itself

            pGame->snake_dx = 0;
            pGame->snake_yx = -(pGame->snake_seg_size);
            break;

        case SDLK_RIGHT:
            if (pGame->snake[0].x + pGame->snake_seg_size == pGame->snake[1].x)
                break; // Stop snake turning into itself

            pGame->snake_dx = pGame->snake_seg_size;
            pGame->snake_yx = 0;
            break;

        case SDLK_DOWN:
            if (pGame->snake[0].y + pGame->snake_seg_size == pGame->snake[1].y)
                break;// Stop snake turning into itself

            pGame->snake_dx = 0;
            pGame->snake_yx = pGame->snake_seg_size;
            break;

        case SDLK_LEFT:
            if (pGame->snake[0].x - pGame->snake_seg_size == pGame->snake[1].x)
                break; // Stop snake turning into itself

            pGame->snake_dx = -(pGame->snake_seg_size);
            pGame->snake_yx = 0;
            break;

        default:
            break;
    }
}
