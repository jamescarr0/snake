//
// Created by James Carr on 01/02/2022.
//

#include "../include/types.h"
#include "../include/play_sfx.h"

void update_score(t_game *const pGame) {

    pGame->game_score++;

    // Play point scored sound effect.
    play_sfx(pGame, POINT_SCORED);
}