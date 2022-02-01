//
// Created by James Carr on 30/01/2022.
//
#include <SDL2/SDL.h>
#include <stdbool.h>

#ifndef SNAKE_TYPES_H
#define SNAKE_TYPES_H

typedef struct
{
    int screen_height;
    int screen_width;
    int wall_thickness;
    int snake_seg_size;
    int x_pos;
    int y_pos;
    int snake_direction;

    int snake_arr_len;

    SDL_Renderer *renderer;
    SDL_Window *window;
    SDL_Rect *snake;

    bool running;
} t_game;

#endif //SNAKE_TYPES_H
