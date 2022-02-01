//
// Created by James Carr on 01/02/2022.
//

#include "../include/types.h"
#include "../include/spawn_food.h"
#include "../include/update_score.h"

void check_collision(t_game *pGame) {

    /* Wall Collisions */
    if (pGame->snake[0].x > ((pGame->screen_width) - (pGame->wall_thickness) - pGame->snake_seg_size) ||
        (pGame->snake[0].x < pGame->wall_thickness) ||
        ((pGame->snake[0].y + pGame->snake_seg_size) > (pGame->screen_height - pGame->wall_thickness)) ||
        (pGame->snake[0].y < pGame->wall_thickness)) {
        pGame->game_over = true;
    }

    /* Food Collision */
    if (pGame->snake[0].x == pGame->food.x && pGame->snake[0].y == pGame->food.y) {
        // Snake has eaten food.

        spawn_food(pGame); // Spawn another food item.

        pGame->grow_snake = true; // Set grow snake flag true to increase snake size.

        --pGame->game_speed; // Decrement the delay between game loop (increases game speed)

        update_score(pGame);    // Update the score
    }

    /* Check for snake colliding with itself */
    for (int i = 1; i < pGame->snake_arr_len; ++i) {
        if (pGame->snake[0].x == pGame->snake[i].x && pGame->snake[0].y == pGame->snake[i].y) {
            pGame->game_over = true;
            break;
        }
    }

}