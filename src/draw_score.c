//
// Created by James Carr on 04/02/2022.
//

#include "../include/types.h"

void draw_score(t_game *pGame) {
    TTF_Font *font = pGame->font;

    SDL_Color color = {255, 255, 255};

    char *score[pGame->snake_arr_len];
    sprintf(score, "%s: %d", "Score", pGame->game_score);

    SDL_Surface *surface = TTF_RenderText_Solid(font, score, color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(pGame->renderer, surface);

    int text_width = 0;
    int text_height = 0;

    SDL_QueryTexture(texture, NULL, NULL, &text_width, &text_height);

    SDL_Rect score_rect = {20, 10, text_width, text_height};

    SDL_RenderCopy(pGame->renderer, texture, NULL, &score_rect);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}