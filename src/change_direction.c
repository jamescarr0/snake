//
// Created by James Carr on 31/01/2022.
//

#include "../include/types.h"

void change_direction(t_game *pGame, SDL_KeyCode btn_pressed) {
    switch (btn_pressed) {
        case SDLK_UP:
            if(pGame->snake_direction == 3) break;
            pGame->snake_dx = 0;
            pGame->snake_yx = -(pGame->snake_seg_size);
            pGame->snake_direction = 1;
            break;

        case SDLK_RIGHT:
            if(pGame->snake_direction == 4) break;
            pGame->snake_dx = pGame->snake_seg_size;
            pGame->snake_yx = 0;
            pGame->snake_direction = 2;
            break;

        case SDLK_DOWN:
            if (pGame->snake_direction == 1) break;
            pGame->snake_dx = 0;
            pGame->snake_yx = pGame->snake_seg_size;
            pGame->snake_direction = 3;
            break;

        case SDLK_LEFT:
            if(pGame->snake_direction == 2) break;
            pGame->snake_dx = -(pGame->snake_seg_size);
            pGame->snake_yx = 0;
            pGame->snake_direction = 4;

        default:
            break;
    }
}
