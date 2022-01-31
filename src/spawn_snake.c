//
// Created by James Carr on 31/01/2022.
//

#include <SDL2/SDL.h>
#include "../include/types.h"

/* Snake body 30x30 pixels */

#define SNAKE_SEGMENT_SIZE 30
#define SNAKE_START_X 400
#define SNAKE_START_Y 300

void spawn_snake(t_game *pGame) {

    int max_snake_length = (pGame->screen_width -
                            (pGame->wall_thickness * 2) * (pGame->screen_height - (pGame->wall_thickness * 2)) /
                            (SNAKE_SEGMENT_SIZE * SNAKE_SEGMENT_SIZE));

    SDL_Rect *snake = malloc(sizeof(SDL_Rect) * max_snake_length);

    pGame->snake = (SDL_Rect *) snake;

    pGame->snake_arr_len = max_snake_length;

    for (int i = 0; i < max_snake_length; ++i) {
        pGame->snake[i].x = 0;
        pGame->snake[i].y = 0;
        pGame->snake[i].w = 0;
        pGame->snake[i].h = 0;
    }

    pGame->snake[0].x = SNAKE_START_X;
    pGame->snake[0].y = SNAKE_START_Y - 5; // Offset to centre enlarged head.
    pGame->snake[0].w = SNAKE_SEGMENT_SIZE + 10; // Enlarge snake head
    pGame->snake[0].h = SNAKE_SEGMENT_SIZE + 10; // Enlarge snake head

    for (int i = 1; i < 4; ++i) {
        pGame->snake[i].y = SNAKE_START_Y;
        pGame->snake[i].x = SNAKE_START_X - ((SNAKE_SEGMENT_SIZE + 3) * i);
        pGame->snake[i].w = SNAKE_SEGMENT_SIZE;
        pGame->snake[i].h = SNAKE_SEGMENT_SIZE;
    }
}