//
// Created by James Carr on 30/01/2022.
//
#include <stdbool.h>

#ifndef SNAKE_TYPES_H
#define SNAKE_TYPES_H

typedef struct
{
    short screen_height;
    short screen_width;
    short wall_thickness;

    SDL_Renderer *renderer;
    SDL_Window *window;

    SDL_Rect *snake;

    bool running;
    bool snake_init;
} t_game;

#endif //SNAKE_TYPES_H
