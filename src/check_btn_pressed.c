//
// Created by James Carr on 30/01/2022.
//

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "../include/types.h"

void check_btn_pressed(t_game *pGame)
{

    SDL_Event event;
    while (SDL_PollEvent(&event))
    {

        switch (event.type)
        {

            case SDL_MOUSEMOTION:
                printf("Mouse event, TODO\n");
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        printf("Escape key pressed\n");
                        pGame->running = false;
                        break;
                }
        }
    }
}