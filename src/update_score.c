//
// Created by James Carr on 01/02/2022.
//

#include "../include/types.h"
#include "../include/play_sfx.h"

void update_score(t_game *pGame) {
    char score[pGame->snake_arr_len + 1];

    // Increment score by 1 each time the snake eats the food.
    sprintf(score, "Score: %d", ++pGame->game_score);

    // Set the new score.
    SDL_SetWindowTitle(pGame->window, score);
    play_sfx(pGame);
}