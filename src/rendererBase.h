#ifndef RENDERER_BASE_H
#define RENDERER_BASE_H

#include <vector>
#include "SDL2/SDL.h"
#include "snake.h"

class RendererBase {
 public:
  RendererBase();  
  RendererBase(const std::size_t screen_width, const std::size_t screen_height,
                const std::size_t grid_width, const std::size_t grid_height);
  ~RendererBase();

  void UpdateWindowTitle(int score, int fps);
  virtual void Render(Snake const , SDL_Point const &){};
  virtual bool collision(Snake){};
  virtual bool ObstacleCell(int, int){};

  SDL_Rect obstacleUp;
  SDL_Rect obstacleMid;
  SDL_Rect obstacleDown;
  SDL_Rect block;

 protected:

  void RenderHead(Snake const);
  void RenderBody(Snake const);
  void RenderFood(SDL_Point const &);
 
  SDL_Window* sdl_window;
  SDL_Renderer* sdl_renderer;

  int factor;
  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;

};

#endif