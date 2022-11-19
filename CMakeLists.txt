cmake_minimum_required(VERSION 3.21)
project(Zaliczenie2 LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(Zaliczenie2 src/main.cpp src/game.h src/game.cpp src/Menu.h src/Menu.cpp src/Ant.cpp src/Ant.h src/GameState.h src/GameState.cpp src/AntGame.h src/AntGame.cpp src/Button.cpp src/Button.h src/MenuOptions.cpp src/MenuOptions.h)
target_link_libraries(Zaliczenie2 PRIVATE sfml-graphics)
target_compile_features(Zaliczenie2 PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET Zaliczenie2 POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:Zaliczenie2> $<TARGET_FILE_DIR:Zaliczenie2> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS Zaliczenie2)
