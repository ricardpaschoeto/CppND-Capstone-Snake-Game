#ifndef RENDERER_ZERO_H
#define RENDERER_ZERO_H

#include <vector>
#include "SDL2/SDL.h"
#include "snake.h"
#include "rendererBase.h"

class RendererZero : public RendererBase {
 public:

  RendererZero(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height):
                   RendererBase(screen_width, screen_height, grid_width, grid_height){}

  void Render(Snake const snake, SDL_Point const &food);
  bool collision(Snake);
  bool ObstacleCell(int, int);
  
};

#endif