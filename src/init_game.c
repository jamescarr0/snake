//
// Created by James Carr on 11/02/2022.
//

#include "../include/types.h"

#define SEGMENT_SIZE 20

Game *init_game() {
    Game *pGame = malloc(sizeof(Game));
    pGame->screen_height = 640;
    pGame->screen_width = 640;
    pGame->wall_thickness = SEGMENT_SIZE;
    pGame->top_wall_padding = 60;
    pGame->snake_seg_size = SEGMENT_SIZE;
    pGame->snake_dx = SEGMENT_SIZE;
    pGame->snake_yx = 0;
    pGame->food.h = SEGMENT_SIZE;
    pGame->food.w = SEGMENT_SIZE;
    pGame->game_score = 0;
    pGame->game_speed = 100;
    pGame->game_over = false;
    pGame->game_paused = false;
    return pGame;
}