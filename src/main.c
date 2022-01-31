#include <stdbool.h>
#include <SDL2/SDL.h>

#include "../include/types.h"
#include "../include/check_btn_pressed.h"
#include "../include/init_sdl.h"
#include "../include/draw_walls.h"
#include "../include/spawn_snake.h"
#include "../include/draw_snake.h"
#include "../include/update_snake.h"

#define SCREEN_BACKGROUND 0, 100, 25, 255

int main(void) {
    t_game *pGame = malloc(sizeof(t_game));
    pGame->screen_height = 640;
    pGame->screen_width = 1024;
    pGame->wall_thickness = 25;
    pGame->snake_seg_size = 25;
    pGame->x_pos = pGame->snake_seg_size;
    pGame->y_pos = 0;

    init_sdl(pGame); // Init SDL

    // Init successful set game state.
    pGame->running = true;

    spawn_snake(pGame); // Create and spawn the snake.

    // Main game loop
    while (pGame->running) {

        // Set background colour and clear the screen
        SDL_SetRenderDrawColor(pGame->renderer, SCREEN_BACKGROUND);
        SDL_RenderClear(pGame->renderer);

        check_btn_pressed(pGame); // Check for button pressed events.

        draw_snake(pGame); // Draw snake

        draw_walls(pGame); // Draw the walls of the game.

        update_snake(pGame);

        SDL_RenderPresent(pGame->renderer); // Update the screen

        SDL_Delay(250);
    }

    free(pGame->snake);
    free(pGame);

    return 0;
}
