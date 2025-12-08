#include <SDL2/SDL.h>
#include <stdio.h>

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "SDL2 Drawing Basics",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800, 600,
        0
    );

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Event event;
    int running = 1;

    while (running) {
        // Event loop
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = 0;
        }

        // 1. Clear screen (set background color)
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
        SDL_RenderClear(renderer);

        // 2. Draw a white line
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // white
        SDL_RenderDrawLine(renderer, 50, 50, 750, 50);

        // 3. Draw a filled red rectangle
        SDL_Rect rect = {100, 100, 200, 150};
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect);

        // 4. Draw an outline blue rectangle
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_Rect border = {350, 100, 300, 150};
        SDL_RenderDrawRect(renderer, &border);

        // 5. Update the screen
        SDL_RenderPresent(renderer);

        SDL_Delay(16); // ~60 FPS
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
