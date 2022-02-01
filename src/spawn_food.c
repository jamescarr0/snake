//
// Created by James Carr on 01/02/2022.
//

#include "../include/types.h"

void spawn_food(t_game *pGame) {
    int x = (rand() % (((pGame->screen_width - (pGame->wall_thickness * 2)) / pGame->snake_seg_size)) *
             pGame->snake_seg_size);
    int y = (rand() % (((pGame->screen_height - (pGame->wall_thickness * 2)) / pGame->snake_seg_size)) *
             pGame->snake_seg_size);
    printf("Spawning food at x:%d y:%d\n", x, y);
    pGame->food.x = x;
    pGame->food.y = y;
}