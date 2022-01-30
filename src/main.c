#include <stdbool.h>
#include <SDL2/SDL.h>

#include "../include/types.h"
#include "../include/check_btn_pressed.h"
#include "../include/init_sdl.h"
#include "../include/draw_walls.h"

#define SCREEN_BACKGROUND 0, 100, 25, 255

int main(void)
{
    t_game *pGame = malloc(sizeof(t_game));

    // Set screen height and the width
    pGame->screen_height = 600;
    pGame->screen_width = 800;

    init_sdl(pGame); // Init SDL

    // Init successful set game state.
    pGame->running = true;

    // Main game loop
    while (pGame->running)
    {
        // Set background colour and clear the screen
        SDL_SetRenderDrawColor(pGame->renderer, SCREEN_BACKGROUND);
        SDL_RenderClear(pGame->renderer);

        check_btn_pressed(pGame); // Check for button pressed events.

        draw_walls(pGame);

        SDL_RenderPresent(pGame->renderer); // Update the screen
    }

    free(pGame);

    return 0;
}
