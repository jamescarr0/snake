//
// Created by James Carr on 01/02/2022.
//

#include "../include/types.h"

void spawn_food(Game *pGame) {
    // Randomly generate x and y co-ordinates for food.

    int food_xy_set = false;
    int x;
    int y;

    while (!food_xy_set) {
        x = (rand() % (((pGame->screen_width - (pGame->wall_thickness * 2)) / pGame->snake_seg_size)) *
             pGame->snake_seg_size);
        y = (rand() % (((pGame->screen_height - ((pGame->wall_thickness * 2) + pGame->top_wall_padding)) /
                        pGame->snake_seg_size)) *
             pGame->snake_seg_size);

        // If food is spawned in the wall, adjust and place inside wall on the map.
        if (x == 0) x += pGame->wall_thickness;
        if (y < pGame->wall_thickness + pGame->top_wall_padding) y += pGame->wall_thickness + pGame->top_wall_padding;

        // DO NOT spawn food on snake body segments.
        for (int i = 0; i < pGame->snake_arr_len; ++i) {
            if (x == pGame->snake[i].x && y == pGame->snake[i].y) {
                break;
            } else if (i == pGame->snake_arr_len - 1) food_xy_set = true;
        }
    }

    // Update food coordinates.
    pGame->food.x = x;
    pGame->food.y = y;
}