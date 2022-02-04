//
// Created by James Carr on 30/01/2022.
//

#ifdef __APPLE__
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
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
    int top_wall_padding;
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

    Mix_Music *sfx_game_over;
    Mix_Music *sfx_score_point;

    TTF_Font *font;

    bool running;
    bool game_over;
    bool grow_snake;
} t_game;

#endif //SNAKE_TYPES_H
