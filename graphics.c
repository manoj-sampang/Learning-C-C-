#include<SDL2/SDL.h>
#include<stdio.h>

int main() {
    // Initialization of SDL
    if(SDL_Init(SDL_INIT_VIDEO)!= 0) {
        printf("SDL Error %s/n", SDL_GetError());
        return 1;
    }
    //creating window
    SDL_Window* window = SDL_CreateWindow(
        "SDL2 drawing graphics",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        600, 800, 
        0
    );
    //Create Renderer for the window
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    //EVENT HANDLER
    SDL_Event event;
    int running = 1;

    while (running) {
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) running = 0;
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        int data[] = {5, 10, 7, 12, 4, 9};
int n = 6;

int startX = 50;
int graphBottom = 450;
int spacing = 80;
int scale = 10;

SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // white

for (int i = 0; i < n - 1; i++) {
    int x1 = startX + i * spacing;
    int y1 = graphBottom - data[i] * scale;

    int x2 = startX + (i + 1) * spacing;
    int y2 = graphBottom - data[i+1] * scale;

    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

        SDL_RenderPresent(renderer);
        SDL_Delay(16);

    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;

}