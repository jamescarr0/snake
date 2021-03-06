//
// Created by James Carr on 30/01/2022.
//

#include "../include/types.h"
#include "../include/change_direction.h"

void check_btn_pressed(Game *const pGame) {

    SDL_Event event;
    while (SDL_PollEvent(&event)) {

        switch (event.type) {

            case SDL_MOUSEMOTION:
                // Mouse event.
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        // Escape key pressed, set game running state false to end main game loop.
                        pGame->running = false;
                        break;

                    case SDLK_UP:
                        change_direction(pGame, SDLK_UP);
                        break;

                    case SDLK_RIGHT:
                        change_direction(pGame, SDLK_RIGHT);
                        break;

                    case SDLK_DOWN:
                        change_direction(pGame, SDLK_DOWN);
                        break;

                    case SDLK_LEFT:
                        change_direction(pGame, SDLK_LEFT);
                        break;

                    case SDLK_p:
                        if(pGame->game_paused) pGame->game_paused = false;
                        else pGame->game_paused = true;

                    default:
                        break;

                }
        }
    }
}