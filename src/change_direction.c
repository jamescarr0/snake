//
// Created by James Carr on 31/01/2022.
//

#include "../include/types.h"

void change_direction(t_game *pGame, SDL_KeyCode btn_pressed) {
    switch (btn_pressed) {
        case SDLK_UP:
            pGame->x_pos = 0;
            pGame->y_pos = -(pGame->snake_seg_size);
            break;

        case SDLK_RIGHT:
            pGame->x_pos = pGame->snake_seg_size;
            pGame->y_pos = 0;
            break;

        case SDLK_DOWN:
            pGame->x_pos = 0;
            pGame->y_pos = pGame->snake_seg_size;
            break;

        case SDLK_LEFT:
            pGame->x_pos = -(pGame->snake_seg_size);
            pGame->y_pos = 0;

        default:
            break;
    }
}
