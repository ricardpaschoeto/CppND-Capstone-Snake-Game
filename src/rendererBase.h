#ifndef RENDERER_BASE_H
#define RENDERER_BASE_H

#include <vector>
#include "SDL.h"
#include "snake.h"

class RendererBase {
 public:
  RendererBase();  
  RendererBase(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~RendererBase();

  virtual void Render(Snake const , SDL_Point const &){};
  void UpdateWindowTitle(int score, int fps);
  void drawHead(Snake const);

 protected:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  SDL_Rect obstacleUp;
  SDL_Rect obstacleMid;
  SDL_Rect obstacleDown;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif