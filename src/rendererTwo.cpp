#include "rendererTwo.h"
#include <iostream>
#include <string>


void RendererTwo::Render(Snake const snake, SDL_Point const &food) {

    // Clear screen
    SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    SDL_RenderClear(sdl_renderer);

    // Render Obstacle Up
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
    UpdateUp();
    SDL_RenderFillRect(sdl_renderer, &obstacleUp);

    // Render Obstacle Mid
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    UpdateMid();
    SDL_RenderFillRect(sdl_renderer, &obstacleMid);

    // Render Obstacle Down
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
    UpdateDown();
    SDL_RenderFillRect(sdl_renderer, &obstacleDown);

    // Render food    
    RenderFood(food);

    // Render snake's body
    RenderBody(snake);

    // Render snake's head
    RenderHead(snake);

    SDL_UpdateWindowSurface( sdl_window );
    SDL_RenderPresent(sdl_renderer);
}

void RendererTwo::UpdateUp(){
    if(obstacleUp.x <= 400 && directionFlagUp == 100){
        obstacleUp.x += 2;
    }else{
        directionFlagUp = 400;
    }

    if(obstacleUp.x >= 100 && directionFlagUp == 400){
        obstacleUp.x -= 2;
    }else{
        directionFlagUp = 100;
    }

}

void RendererTwo::UpdateMid(){
    if(obstacleMid.x <= 400 && directionFlagMid == 100){
        obstacleMid.x += 2;
    }else{
        directionFlagMid = 400;
    }

    if(obstacleMid.x >= 100 && directionFlagMid == 400){
        obstacleMid.x -= 2;
    }else{
        directionFlagMid = 100;
    }    
}

void RendererTwo::UpdateDown(){
    if(obstacleDown.x <= 400 && directionFlagDown == 100){
        obstacleDown.x += 2;
    }else{
        directionFlagDown = 400;
    }

    if(obstacleDown.x >= 100 && directionFlagDown == 400){
        obstacleDown.x -= 2;
    }else{
        directionFlagDown = 100;
    }    
}

bool RendererTwo::collision(Snake snake){

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

bool RendererTwo::ObstacleCell(int x, int y){return false;} 