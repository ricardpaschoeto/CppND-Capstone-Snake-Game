#include "rendererOne.h"
#include <iostream>
#include <string>


void RendererOne::Render(Snake const snake, SDL_Point const &food) {

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
    RenderFood(food);

    // Render snake's body
    RenderBody(snake);

    // Render snake's head
    RenderHead(snake);

    SDL_UpdateWindowSurface(sdl_window);
    
    SDL_RenderPresent(sdl_renderer);
  
}

bool RendererOne::collision(Snake snake){

  if((block.w*static_cast<int>(snake.head_x) >= obstacleUp.x && block.w*static_cast<int>(snake.head_x) <= (obstacleUp.x + obstacleUp.w)) &&
     (block.h*static_cast<int>(snake.head_y) >= obstacleUp.y && block.h*static_cast<int>(snake.head_y) <= (obstacleUp.y + obstacleUp.h))){
        return true;
    }

  if((block.w*static_cast<int>(snake.head_x) >= obstacleMid.x && block.w*static_cast<int>(snake.head_x) <= (obstacleMid.x + obstacleMid.w)) &&
     (block.h*static_cast<int>(snake.head_y) >= obstacleMid.y && block.h*static_cast<int>(snake.head_y) <= (obstacleMid.y + obstacleMid.h))){
        return true;
    }

  if((block.w*static_cast<int>(snake.head_x) >= obstacleDown.x && block.w*static_cast<int>(snake.head_x) <= (obstacleDown.x + obstacleDown.w)) &&
     (block.h*static_cast<int>(snake.head_y) >= obstacleDown.y && block.h*static_cast<int>(snake.head_y) <= (obstacleDown.y + obstacleDown.h))){
        return true;
    }
  
  return false;

}

bool RendererOne::ObstacleCell(int x, int y){

  if((block.w*x >= obstacleUp.x && block.w*x <= (obstacleUp.x + obstacleUp.w)) &&
     (block.h*y >= obstacleUp.y && block.h*y <= (obstacleUp.y + obstacleUp.h))){
       return true;
     }

  if((block.w*x >= obstacleMid.x && block.w*x <= (obstacleMid.x + obstacleMid.w)) &&
     (block.h*y >= obstacleMid.y && block.h*y <= (obstacleMid.y + obstacleMid.h))){
       return true;
     }

  if((block.w*x >= obstacleDown.x && block.w*x <= (obstacleDown.x + obstacleDown.w)) &&
     (block.h*y >= obstacleDown.y && block.h*y <= (obstacleDown.y + obstacleDown.h))){
       return true;
     }

  return false;

}