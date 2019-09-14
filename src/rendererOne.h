#ifndef RENDERER_ONE_H
#define RENDERER_ONE_H

#include <vector>
#include "SDL2/SDL.h"
#include "snake.h"
#include "rendererZero.h"

class RendererOne : public RendererZero {
 
 public:

     RendererOne(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height):
                   RendererZero(screen_width, screen_height, grid_width, grid_height){

                        obstacleUp.w = 80;
                        obstacleUp.h = 25;
                        obstacleUp.x = 320;
                        obstacleUp.y = 50;

                        obstacleMid.w = 80;
                        obstacleMid.h = 25;
                        obstacleMid.x = 320;
                        obstacleMid.y = 320;

                        obstacleDown.w = 80;
                        obstacleDown.h = 25;
                        obstacleDown.x = 320;
                        obstacleDown.y = 590;
          
                   }

     void Render(Snake const snake, SDL_Point const &food);
     bool collision(Snake);
     bool ObstacleCell(int, int);
};

#endif