//
// Created by James Carr on 31/01/2022.
//

#include "../include/types.h"

void update_snake(t_game *pGame) {
// Shift elements to the right and create a new head.
    for (int i = (pGame->snake_arr_len - 1); i >= 0; --i) {
        pGame->snake[i] = pGame->snake[i - 1]; // Shift right
    }

    // Insert a new head at the start of the array.
    pGame->snake[0].x = pGame->snake[1].x + pGame->snake_dx;
    pGame->snake[0].y = pGame->snake[1].y + pGame->snake_yx;
    pGame->snake[0].w = pGame->snake_seg_size;
    pGame->snake[0].h = pGame->snake_seg_size;


    if (pGame->grow_snake) {
        pGame->grow_snake = false;
    } else {
        // Remove the tail after a new head has been created.
        for (int i = 5; i < pGame->snake_arr_len; ++i) {
            if (pGame->snake[i].w == 0) {
                pGame->snake[i - 1].x = 0;
                pGame->snake[i - 1].y = 0;
                pGame->snake[i - 1].w = 0;
                pGame->snake[i - 1].h = 0;
                break;
            }
        }
    }
}