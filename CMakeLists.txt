cmake_minimum_required(VERSION 3.20)
project(snake C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
message(STATUS ${CMAKE_MODULE_PATH})

FIND_PACKAGE(SDL2 REQUIRED)
Message("")
Message( STATUS "FINDING SDL2" )
IF (${SDL2_FOUND})
    Message( STATUS "SDL2_FOUND: " ${SDL2_FOUND})
    Message( STATUS "SDL2_INCLUDE_DIR:" ${SDL2_INCLUDE_DIRS})
    Message( STATUS "SDL2_LIBRARY: " ${SDL2_LIBRARIES})
ELSE()
    Message( STATUS "SDL2_FOUND: " ${SDL2_FOUND})
    Message( FATAL_ERROR "SDL2 NOT FOUND" )
ENDIF()

Message("")

FIND_PACKAGE(SDL2_mixer)
IF (${SDL2_MIXER_FOUND})
    Message( STATUS "FINDING SDL2_Mixer" )
    Message( STATUS "SDL2_Mixer_FOUND: " ${SDL2_MIXER_FOUND} )
    Message( STATUS "SDL2_INCLUDE_DIR:" ${SDL2_MIXER_INCLUDE_DIRS})
    Message( STATUS "SDL2_LIBRARY: " ${SDL2_MIXER_LIBRARIES})
ELSE()
    Message( STATUS "SDL2_MIXER_FOUND: " ${SDL2_MIXER_FOUND})
    Message( FATAL_ERROR "SDL2 NOT FOUND" )
ENDIF()

Message("")

FIND_PACKAGE(SDL2TTF)
IF (${SDL2TTF_FOUND})
    Message( STATUS "FINDING SDL2_TTF" )
    Message( STATUS "SDL2_Mixer_FOUND: " ${SDL2TTF_FOUND} )
    Message( STATUS "SDL2_INCLUDE_DIR:" ${SDL2TTF_INCLUDE_DIR})
    Message( STATUS "SDL2_LIBRARY: " ${SDL2TTF_LIBRARY})
ELSE()
    Message( STATUS "SDL2_TTF_FOUND: " ${SDL2_TTF_FOUND})
    Message( FATAL_ERROR "SDL2 TTF NOT FOUND" )
ENDIF()


Message("")

add_executable(snake src/main.c include/types.h include/init_sdl.h include/check_btn_pressed.h include/terminate.h src/check_btn_pressed.c src/terminate.c src/init_sdl.c include/draw_walls.h src/draw_walls.c src/draw_snake.c include/draw_snake.h src/spawn_snake.c include/spawn_snake.h include/update_snake.h src/update_snake.c include/change_direction.h src/change_direction.c src/check_collision.c include/check_collision.h include/spawn_food.h include/draw_food.h src/draw_food.c src/spawn_food.c include/update_score.h src/update_score.c src/play_sfx.c include/play_sfx.h)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2_MIXER_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_MIXER_LIBRARIES} )

