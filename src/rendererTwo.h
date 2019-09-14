#ifndef RENDERER_TWO_H
#define RENDERER_TWO_H

#include <vector>
#include "SDL2/SDL.h"
#include "snake.h"
#include "rendererOne.h"

class RendererTwo : public RendererOne {
 public:

  RendererTwo(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height):
                   RendererOne(screen_width, screen_height, grid_width, grid_height){

                        directionFlagUp = 400;
                        directionFlagMid = 100;
                        directionFlagDown = 400;
                   }

     void Render(Snake const snake, SDL_Point const &food);
     bool collision(Snake);
     bool ObstacleCell(int, int);
     
  private:

    void UpdateUp();
    void UpdateMid();
    void UpdateDown();

    int directionFlagUp;
    int directionFlagMid;
    int directionFlagDown;

};

#endif