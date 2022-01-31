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

    if (!pGame->snake_init) {
        printf("Init snake segments\n");
        int max_snake_length = (pGame->screen_width -
                                (pGame->wall_thickness * 2) * (pGame->screen_height - (pGame->wall_thickness * 2)) /
                                (SNAKE_SEGMENT_HEIGHT * SNAKE_SEGMENT_WIDTH));

        SDL_Rect snake[max_snake_length];
        pGame->snake = snake;

        for (int i = 0; i < sizeof(snake) / sizeof(snake[0]); ++i) {
            printf("%i init segment to zero\n", i);
            pGame->snake[i].x = 0;
            pGame->snake[i].y = 0;
            pGame->snake[i].w = 0;
            pGame->snake[i].h = 0;
        }

        pGame->snake_init = 1;
    }

    // Draw the snakes head. The head is Snake[0] - the first element
    SDL_SetRenderDrawColor(pGame->renderer, SNAKE_HEAD_COLOR);
    pGame->snake[0].x = SNAKE_START_X;
    pGame->snake[0].y = SNAKE_START_Y;
    pGame->snake[0].w = SNAKE_SEGMENT_WIDTH;
    pGame->snake[0].h = SNAKE_SEGMENT_HEIGHT;

    SDL_RenderFillRect(pGame->renderer, (pGame->snake));

    for (int i = 1; i < 5; ++i) {
        pGame->snake[i].x = SNAKE_START_X - ((SNAKE_SEGMENT_WIDTH+3) * i);
        pGame->snake[i].y = SNAKE_START_Y;
        pGame->snake[i].w = SNAKE_SEGMENT_WIDTH;
        pGame->snake[i].h = SNAKE_SEGMENT_HEIGHT;

        SDL_RenderFillRect(pGame->renderer, (pGame->snake) + i);
    }
}
