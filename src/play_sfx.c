//
// Created by James Carr on 02/02/2022.
//

#include "../include/types.h"

void play_sfx(t_game *const pGame, int const sfx) {
    switch (sfx) {
        case POINT_SCORED:
            pGame->sfx = Mix_LoadMUS("../sounds/sfx1.mp3");
            break;
        case GAME_OVER:
            pGame->sfx = Mix_LoadMUS("../sounds/game_over.mp3");
            break;
        default:
            break;
    }
    Mix_PlayMusic(pGame->sfx, 1);
}