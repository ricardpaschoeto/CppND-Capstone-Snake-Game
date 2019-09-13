#ifndef RENDERER_BASE_H
#define RENDERER_BASE_H

#include <vector>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "snake.h"

class RendererBase {
 public:
  RendererBase();  
  RendererBase(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~RendererBase();

  virtual void Render(Snake const , SDL_Point const &){};
  void UpdateWindowTitle(int score, int fps);
  bool collision(Snake);
  bool ObstacleCell(int, int);

  SDL_Rect obstacleUp;
  SDL_Rect obstacleMid;
  SDL_Rect obstacleDown;

 protected:
  SDL_Window* sdl_window;
  SDL_Renderer* sdl_renderer;
  Snake snake;

  int factor = screen_width/grid_width;
  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;

};

#endif