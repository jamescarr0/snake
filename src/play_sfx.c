//
// Created by James Carr on 02/02/2022.
//

#include "../include/types.h"

void play_sfx(t_game *const pGame, int const sfx) {
    switch (sfx) {
        case POINT_SCORED:
            Mix_PlayMusic(pGame->sfx_score_point, 1);
            break;
        case GAME_OVER:
            Mix_PlayMusic(pGame->sfx_game_over, 1);
            break;
        default:
            break;
    }
}