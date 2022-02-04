//
// Created by James Carr on 04/02/2022.
//

#include "../include/types.h"

void draw_score(t_game *pGame) {
    TTF_Font *font = pGame->font;

    SDL_Color color = {255, 255, 255};

    char score[pGame->snake_arr_len];
    sprintf(score, "%s: %d", "Score", pGame->game_score);

    SDL_Surface *s_surface = TTF_RenderText_Solid(font, score, color);
    SDL_Texture *s_texture = SDL_CreateTextureFromSurface(pGame->renderer, s_surface);

    int text_width = 0;
    int text_height = 0;

    SDL_QueryTexture(s_texture, NULL, NULL, &text_width, &text_height);
    SDL_Rect score_rect = {20, 10, text_width, text_height};
    SDL_RenderCopy(pGame->renderer, s_texture, NULL, &score_rect);


    if(pGame->game_over) {
        int go_text_width = 0;
        int go_text_height = 0;
        char *game_over_str = "* Game Over *";

        SDL_Surface *go_surface = TTF_RenderText_Solid(font, game_over_str, color);
        SDL_Texture *go_texture = SDL_CreateTextureFromSurface(pGame->renderer, go_surface);

        SDL_QueryTexture(go_texture, NULL, NULL, &go_text_width, &go_text_height);

        int align_center = (pGame->screen_width - go_text_width) / 2;

        SDL_Rect go_rect = {align_center, 10, go_text_width, go_text_height};
        SDL_RenderCopy(pGame->renderer, go_texture, NULL, &go_rect);

        SDL_DestroyTexture(go_texture);
        SDL_FreeSurface(go_surface);
    }

    SDL_DestroyTexture(s_texture);
    SDL_FreeSurface(s_surface);
}