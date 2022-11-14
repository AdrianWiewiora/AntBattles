cmake_minimum_required(VERSION 3.21)
project(Zaliczenie LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(Zaliczenie src/main.cpp src/game.h src/game.cpp src/Menu.h src/Menu.cpp)
target_link_libraries(Zaliczenie PRIVATE sfml-graphics)
target_compile_features(Zaliczenie PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET Zaliczenie POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:Zaliczenie> $<TARGET_FILE_DIR:Zaliczenie> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS Zaliczenie)