#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define SCREEN_BACKGROUND 0, 0, 250, 255

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

typedef struct
{
    SDL_Renderer *renderer;
    SDL_Window *window;
    bool running;
} t_game;

bool init_sdl(t_game *);
void check_btn_pressed(t_game *);
void terminate(t_game *, int exit_code);

int main(void)
{

    t_game *pGame = malloc(sizeof(t_game));

    init_sdl(pGame);
    pGame->running = true;

    // Main game loop
    while (pGame->running)
    {
        SDL_SetRenderDrawColor(pGame->renderer, SCREEN_BACKGROUND);
            SDL_RenderClear(pGame->renderer);

        check_btn_pressed(pGame);

        SDL_RenderPresent(pGame->renderer);

        SDL_Delay(500);
    }

    free(pGame);

    return 0;
}

bool init_sdl(t_game *pGame)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Error: failed to initialize SDL: %s\n", SDL_GetError());
        terminate(pGame, EXIT_FAILURE);
    }

    // Create a game window.
    pGame->window = SDL_CreateWindow("Score: 0",
                                     SDL_WINDOWPOS_UNDEFINED,
                                     SDL_WINDOWPOS_UNDEFINED,
                                     SCREEN_WIDTH,
                                     SCREEN_HEIGHT,
                                     SDL_WINDOW_SHOWN);
    if (!pGame->window)
    {
        printf("Error: failed to create renderer %s\n", SDL_GetError());
        terminate(pGame, EXIT_FAILURE);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    pGame->renderer = SDL_CreateRenderer(pGame->window, -1, SDL_RENDERER_ACCELERATED);

    if (!pGame->renderer)
    {
        printf("error: failed to create renderer: %s\n", SDL_GetError());
        terminate(pGame, EXIT_FAILURE);
    }

    return true;
}

void terminate(t_game *pGame, int exit_code)
{
    if (pGame->renderer)
    {
        SDL_DestroyRenderer(pGame->renderer);
    }
    if (pGame->window)
    {
        SDL_DestroyWindow(pGame->window);
    }

    SDL_Quit();
    exit(exit_code);
}

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
