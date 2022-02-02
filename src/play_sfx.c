//
// Created by James Carr on 02/02/2022.
//

#include "../include/types.h"

void play_sfx(t_game *pGame) {
    pGame->sfx_eat = Mix_LoadMUS("/Users/james/Desktop/sfx1.mp3");
    Mix_PlayMusic(pGame->sfx_eat, 1);
}