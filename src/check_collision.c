//
// Created by James Carr on 01/02/2022.
//

#include "../include/types.h"

void check_collision(t_game *pGame) {

    /* Wall Collisions */
    if (pGame->snake[0].x > ((pGame->screen_width) - (pGame->wall_thickness) - pGame->snake_seg_size) ||
        (pGame->snake[0].x < pGame->wall_thickness) ||
        ((pGame->snake[0].y + pGame->snake_seg_size) > (pGame->screen_height - pGame->wall_thickness)) ||
        (pGame->snake[0].y < pGame->wall_thickness)) {
        pGame->game_over = true;
    }

}