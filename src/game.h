#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL2/SDL.h"
#include "controller.h"
#include "rendererBase.h"
#include "snake.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height, RendererBase &renderer);
  void Run(Controller const &controller, std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

 private:
  Snake snake;
  SDL_Point food;
  RendererBase &renderer;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  void PlaceFood();
  void Update();
};

#endif