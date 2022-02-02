//
// Created by James Carr on 30/01/2022.
//
// Setup and draw the walls of the game to the render target.
//

#include "../include/types.h"

#define WALL_COLOUR 0, 0, 0, 255

void draw_walls(t_game *pGame) {
    SDL_SetRenderDrawColor(pGame->renderer, WALL_COLOUR); // Set the walls colour

    // Initialise and create the LEFT wall.
    SDL_Rect wall_rect = {
            .x = 0, // Upper left corner x position
            .y = 0, // Upper left corner y position
            .w = pGame->wall_thickness,
            .h = pGame->screen_height
    };

    // Fill the wall rect on the renderer target
    SDL_RenderFillRect(pGame->renderer, &wall_rect);

    // Create the right wall and fill the rect.
    wall_rect.x = pGame->screen_width - pGame->wall_thickness;
    SDL_RenderFillRect(pGame->renderer, &wall_rect);

    // Create a Top Wall and fill rect.
    wall_rect.x = 0;
    wall_rect.y = 0;
    wall_rect.w = pGame->screen_width;
    wall_rect.h = pGame->wall_thickness;
    SDL_RenderFillRect(pGame->renderer, &wall_rect);

    // Create a bottom wall and fill
    wall_rect.y = pGame->screen_height - pGame->wall_thickness;
    SDL_RenderFillRect(pGame->renderer, &wall_rect);
}