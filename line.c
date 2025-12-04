#include <SDL2/SDL.h>
#include <stdio.h>

int main() {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow(
        "SDL2 Line Drawing",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        640, 480,
        SDL_WINDOW_SHOWN
    );

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Draw a line
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);      // black background
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // white line
    SDL_RenderDrawLine(renderer, 100, 100, 500, 300);
    SDL_RenderPresent(renderer);

    // Event loop to keep window responsive
    SDL_Event e;
    int quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) { // Close window
                quit = 1;
            }
        }
        SDL_Delay(10); // small delay to reduce CPU usage
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
