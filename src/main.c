#include <stdlib.h>
#include <stdbool.h>

#ifdef __APPLE__
#include <SDL.h>
#include <SDL_ttf.h>

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
#define SEGMENT_SIZE 20

int main(void) {
    t_game *pGame = malloc(sizeof(t_game));
    pGame->screen_height = 640;
    pGame->screen_width = 640;
    pGame->wall_thickness = SEGMENT_SIZE;
    pGame->top_wall_padding = 60;
    pGame->snake_seg_size = SEGMENT_SIZE;
    pGame->snake_dx = SEGMENT_SIZE;
    pGame->snake_yx = 0;
    pGame->food.h = SEGMENT_SIZE;
    pGame->food.w = SEGMENT_SIZE;
    pGame->game_score = 0;
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

        check_btn_pressed(pGame); // Check for button pressed event.

        draw_snake(pGame); // Draw snake

        draw_walls(pGame); // Draw the walls of the game.

        draw_food(pGame);

        draw_score(pGame);

        if (!pGame->game_over) {
            update_snake(pGame); // Update snakes position unless game over
            check_collision(pGame); // check for collisions.
        }

        SDL_RenderPresent(pGame->renderer); // Update the screen

        SDL_Delay(pGame->game_speed);
    }

    terminate(pGame, 0);

    return 0;
}