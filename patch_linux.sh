find ./src -type f -exec sed -i 's/<SDL.h>/<SDL2\/SDL.h>/g' {} +
find ./src -type f -exec sed -i 's/<SDL_mixer.h>/<SDL2\/SDL_mixer.h>/g' {} +
find ./include -type f -exec sed -i 's/<SDL.h>/<SDL2\/SDL.h>/g' {} +
find ./include -type f -exec sed -i 's/<SDL_mixer.h>/<SDL2\/SDL_mixer.h>/g' {} +
echo "Patched applied"
