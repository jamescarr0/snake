#include <stdbool.h>
#include "../include/init_game.h"

#ifdef __APPLE__
#include <SDL.h>

#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#endif

#include "../include/types.h"
#include "../include/check_btn_pressed.h"
#include "../include/init_sdl.h"
#include "../include/draw_walls.h"
#include "../include/spawn_snake.h"
#include "../include/draw_snake.h"
#include "../include/update_snake.h"
#include "../include/check_collision.h"
#include "../include/spawn_food.h"
#include "../include/draw_food.h"
#include "../include/terminate.h"
#include "../include/draw_score.h"

#define SCREEN_BACKGROUND 0, 90, 55, 255

int main(void) {
    // Initialise a new game.
    Game *pGame = init_game();

    init_sdl(pGame); // Init SDL

    // SDL Init successful set game state.
    pGame->running = true;

    // Spawn the snake and food.
    spawn_snake(pGame);
    spawn_food(pGame);

    // Main game loop
    while (pGame->running) {

        if(pGame->game_paused){
            check_btn_pressed(pGame);
            continue;
        };

        // Set background colour and clear the screen
        SDL_SetRenderDrawColor(pGame->renderer, SCREEN_BACKGROUND);
        SDL_RenderClear(pGame->renderer);

        check_btn_pressed(pGame); // Check for button pressed event.
        draw_snake(pGame); // Draw snake.
        draw_walls(pGame); // Draw the walls of the game.
        draw_food(pGame); // Draw the food.
        draw_score(pGame); // Draw the score.

        if (!pGame->game_over) {
            update_snake(pGame); // Update snakes position unless game over
            check_collision(pGame); // check for collisions.
        }

        SDL_RenderPresent(pGame->renderer); // Update the screen
        SDL_Delay(pGame->game_speed); // Control the speed of gameplay
    }

    terminate(pGame, 0); // Clean up.

    return 0;
}