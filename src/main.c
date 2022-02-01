#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

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

#define SCREEN_BACKGROUND 0, 90, 55, 255
#define SEGMENT_SIZE 20

int main(void) {
    t_game *pGame = malloc(sizeof(t_game));
    pGame->screen_height = 640;
    pGame->screen_width = 1040;
    pGame->wall_thickness = SEGMENT_SIZE;
    pGame->snake_seg_size = SEGMENT_SIZE;
    pGame->snake_dx = SEGMENT_SIZE;
    pGame->snake_yx = 0;
    pGame->food.h = SEGMENT_SIZE;
    pGame->food.w = SEGMENT_SIZE;
    pGame->game_score = 0;
    pGame->grow_snake = false;
    pGame->game_speed = 100;

    init_sdl(pGame); // Init SDL

    // Init successful set game state.
    pGame->running = true;
    pGame->game_over = false;

    spawn_snake(pGame); // Create and spawn the snake.
    spawn_food(pGame);

    // Main game loop
    while (pGame->running) {

        // Set background colour and clear the screen
        SDL_SetRenderDrawColor(pGame->renderer, SCREEN_BACKGROUND);
        SDL_RenderClear(pGame->renderer);

        check_btn_pressed(pGame); // Check for button pressed events.

        draw_snake(pGame); // Draw snake

        draw_walls(pGame); // Draw the walls of the game.

        if (!pGame->game_over) {
            update_snake(pGame); // Update snakes position.
        }

        draw_food(pGame);

        check_collision(pGame); // check for collisions.

        SDL_RenderPresent(pGame->renderer); // Update the screen

        SDL_Delay(pGame->game_speed);
    }

    free(pGame->snake);
    free(pGame);

    return 0;
}
