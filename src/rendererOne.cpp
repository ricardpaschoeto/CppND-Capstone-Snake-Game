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
    block.x = food.x * block.w;
    block.y = food.y * block.h;
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

bool RendererOne::collision(Snake snake){

  if((factor*static_cast<int>(snake.head_x) >= obstacleUp.x && factor*static_cast<int>(snake.head_x) <= (obstacleUp.x + obstacleUp.w)) &&
     (factor*static_cast<int>(snake.head_y) >= obstacleUp.y && factor*static_cast<int>(snake.head_y) <= (obstacleUp.y + obstacleUp.h))){
        return true;
    }

  if((factor*static_cast<int>(snake.head_x) >= obstacleMid.x && factor*static_cast<int>(snake.head_x) <= (obstacleMid.x + obstacleMid.w)) &&
     (factor*static_cast<int>(snake.head_y) >= obstacleMid.y && factor*static_cast<int>(snake.head_y) <= (obstacleMid.y + obstacleMid.h))){
        return true;
    }

  if((factor*static_cast<int>(snake.head_x) >= obstacleDown.x && factor*static_cast<int>(snake.head_x) <= (obstacleDown.x + obstacleDown.w)) &&
      (factor*static_cast<int>(snake.head_y) >= obstacleDown.y && factor*static_cast<int>(snake.head_y) <= (obstacleDown.y + obstacleDown.h))){
        return true;
    }
  
  return false;

}

bool RendererOne::ObstacleCell(int x, int y){
  std::cout << factor << std::endl;
  if((factor*x >= obstacleUp.x && factor*x <= (obstacleUp.x + obstacleUp.w)) &&
     (factor*y >= obstacleUp.y && factor*y <= (obstacleUp.y + obstacleUp.h))){
       return true;
     }

  if((factor*x >= obstacleMid.x && factor*x <= (obstacleMid.x + obstacleMid.w)) &&
     (factor*y >= obstacleMid.y && factor*y <= (obstacleMid.y + obstacleMid.h))){
       return true;
     }

  if((factor*x >= obstacleDown.x && factor*x <= (obstacleDown.x + obstacleDown.w)) &&
     (factor*y >= obstacleDown.y && factor*y <= (obstacleDown.y + obstacleDown.h))){
       return true;
     }

  return false;

}