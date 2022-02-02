//
// Created by James Carr on 31/01/2022.
//

#include "../include/types.h"

/* Snake body 30x30 pixels */

#define SNAKE_START_X 400
#define SNAKE_START_Y 300

void spawn_snake(t_game *pGame) {

    int max_snake_length = (pGame->screen_width -
                            (pGame->wall_thickness * 2) * (pGame->screen_height - (pGame->wall_thickness * 2)) /
                            (pGame->snake_seg_size * pGame->snake_seg_size));

    // Allocate memory to store each segment in an array.
    SDL_Rect *snake = malloc(sizeof(SDL_Rect) * max_snake_length);

    // Add pointer to Game struct to keep track of allocated memory.
    pGame->snake = (SDL_Rect *) snake;

    // Store the maximum array size into Game struct so other functions can iterate the array.
    pGame->snake_arr_len = max_snake_length;

    for (int i = 0; i < max_snake_length; ++i) {
        pGame->snake[i].x = 0;
        pGame->snake[i].y = 0;
        pGame->snake[i].w = 0;
        pGame->snake[i].h = 0;
    }

    pGame->snake[0].x = SNAKE_START_X;
    pGame->snake[0].y = SNAKE_START_Y;
    pGame->snake[0].w = pGame->snake_seg_size;
    pGame->snake[0].h = pGame->snake_seg_size;

    for (int i = 1; i < 4; ++i) {
        pGame->snake[i].y = SNAKE_START_Y;
        pGame->snake[i].x = SNAKE_START_X - ((pGame->snake_seg_size) * i);
        pGame->snake[i].w = pGame->snake_seg_size;
        pGame->snake[i].h = pGame->snake_seg_size;
    }
}