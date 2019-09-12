#include "rendererOne.h"
#include <iostream>
#include <string>


void RendererOne::Render(Snake const snake, SDL_Point const &food) {

    SDL_Rect block;
    block.w = screen_width / grid_width;
    block.h = screen_height / grid_height;

    // Clear screen
    SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    SDL_RenderClear(sdl_renderer);

    // Render Obstacle Up
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
    SDL_RenderFillRect(sdl_renderer, &obstacleUp);
    
    // Render Obstacle Mid
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(sdl_renderer, &obstacleMid);

    // Render Obstacle Down
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
    SDL_RenderFillRect(sdl_renderer, &obstacleDown);

    // Render food    
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
    SDL_RenderFillRect(sdl_renderer, &block);

    // Render snake's body
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    for (SDL_Point const &point : snake.body) {
      block.x = point.x * block.w;
      block.y = point.y * block.h;
      SDL_RenderFillRect(sdl_renderer, &block);
    }

    // Render snake's head
    //drawHead(snake);
    block.x = static_cast<int>(snake.head_x) * block.w;
    block.y = static_cast<int>(snake.head_y) * block.h;
    if (snake.alive) {
      SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
    }else {
      SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
    }
    
    SDL_RenderFillRect(sdl_renderer, &block);

    SDL_UpdateWindowSurface( sdl_window );
    SDL_RenderPresent(sdl_renderer);
  
}