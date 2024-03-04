#include "mylibrary.hpp"
#include <SDL2/SDL.h>
#include <iostream>
#include <spdlog/spdlog.h>

int main()
{
    const char* WindowName = "Test SDL Application";
    const unsigned int ScreenWidth = 800;
    const unsigned int ScreenHeight = 600;

    std::cout << "Call function: " << mylibrary::sum(1, 2) << '\n';
    mylibrary::examples::std_vector_custom_allocator();

#ifndef NDEBUG
    spdlog::set_level(spdlog::level::debug);
#endif

    spdlog::debug("Debug - Hello, world!");
    spdlog::info("Hello, world!");

    bool done = false;

    SDL_Init(SDL_INIT_VIDEO);

    auto window = SDL_CreateWindow(
        WindowName,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        ScreenWidth,
        ScreenHeight,
        SDL_WINDOW_SHOWN);

    auto renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 255);

    while (!done) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                done = true;
                break;
            default:
                break;
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);

        spdlog::info("loop");

        SDL_Delay(15);
    }

    spdlog::info("cleanup");

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    SDL_Quit();

    return 0;
}
