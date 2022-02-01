cmake_minimum_required(VERSION 3.20)
project(snake C)

set(CMAKE_C_STANDARD 11)

set(SDL2_INCLUDE_DIR /opt/homebrew/Cellar/sdl2/2.0.20/include)
set(SDL2_LIB_DIR /opt/homebrew/Cellar/sdl2/2.0.20/lib)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

add_executable(snake src/main.c include/types.h include/init_sdl.h include/check_btn_pressed.h include/terminate.h src/check_btn_pressed.c src/terminate.c src/init_sdl.c include/draw_walls.h src/draw_walls.c src/draw_snake.c include/draw_snake.h src/spawn_snake.c include/spawn_snake.h include/update_snake.h src/update_snake.c include/change_direction.h src/change_direction.c src/check_collision.c include/check_collision.h include/spawn_food.h include/draw_food.h src/draw_food.c src/spawn_food.c)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2)
