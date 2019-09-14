#include "rendererZero.h"
#include <iostream>
#include <string>


void RendererZero::Render(Snake const snake, SDL_Point const &food) {

    // Clear screen
    SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    SDL_RenderClear(sdl_renderer);

    // Render food 
    RenderFood(food);   

    // Render snake's body
    RenderBody(snake);

    // Render snake's head
    RenderHead(snake);

    SDL_UpdateWindowSurface( sdl_window );
    SDL_RenderPresent(sdl_renderer);
   
}

bool RendererZero::collision(Snake snake){return false;}
bool RendererZero::ObstacleCell(int x, int y){return false;}


