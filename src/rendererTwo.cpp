#include "rendererTwo.h"
#include <iostream>
#include <string>


void RendererTwo::Render(Snake const snake, SDL_Point const &food) {

    SDL_Rect block;
    block.w = screen_width / grid_width;
    block.h = screen_height / grid_height;

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