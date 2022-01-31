//
// Created by James Carr on 30/01/2022.
//

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "../include/types.h"

void check_btn_pressed(t_game *pGame) {

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

                    case SDLK_RIGHT:
                        // Right key pressed

                        break;
                }
        }
    }
}