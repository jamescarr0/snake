//
// Created by James Carr on 30/01/2022.
//
#include <stdio.h>
#include <SDL2/SDL.h>
#include "../include/types.h"

/* Snake body 30x30 pixels */

#define SNAKE_SEGMENT_WIDTH 30
#define SNAKE_SEGMENT_HEIGHT 30
#define SNAKE_START_X 400
#define SNAKE_START_Y 300
#define SNAKE_HEAD_COLOR 0, 0, 0, 255

void draw_snake(t_game *pGame) {

    if(!pGame->snake_init) {
        printf("Init snake segments\n");
        int max_snake_length = (pGame->screen_width -
                                (pGame->wall_thickness * 2) * (pGame->screen_height - (pGame->wall_thickness * 2)) /
                                (SNAKE_SEGMENT_HEIGHT * SNAKE_SEGMENT_WIDTH));

        SDL_Rect snake[max_snake_length];
        pGame->snake = snake;
        pGame->snake_init = 1;
    }

    // Draw the snakes head.
    SDL_SetRenderDrawColor(pGame->renderer, SNAKE_HEAD_COLOR);
    SDL_RenderFillRect(pGame->renderer, (pGame->snake));

    pGame->snake->x = SNAKE_START_X;
    pGame->snake->y = SNAKE_START_Y;
    pGame->snake->w = SNAKE_SEGMENT_WIDTH;
    pGame->snake->h = SNAKE_SEGMENT_HEIGHT;
}
