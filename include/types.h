//
// Created by James Carr on 30/01/2022.
//

#ifdef __APPLE__
#include <SDL.h>
#include <SDL_mixer.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#endif

#include <stdbool.h>

#ifndef SNAKE_TYPES_H
#define SNAKE_TYPES_H

enum sfx {
    POINT_SCORED,
    GAME_OVER,
};

typedef struct
{
    int screen_height;
    int screen_width;
    int wall_thickness;
    int snake_seg_size;
    int snake_dx;
    int snake_yx;
    int snake_arr_len;

    int game_score;
    int game_speed;

    SDL_Renderer *renderer;
    SDL_Window *window;

    SDL_Rect *snake;
    SDL_Rect food;

    Mix_Music *sfx;

    bool running;
    bool game_over;
    bool grow_snake;
} t_game;

#endif //SNAKE_TYPES_H
