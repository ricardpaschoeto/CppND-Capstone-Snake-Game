#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL2/SDL.h"
#include "controller.h"
#include "rendererBase.h"
//#include "sound.h"
#include "snake.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height, RendererBase &renderer);
  void Run(Controller const &controller, RendererBase &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

 private:
  Snake snake;
  //Sound sound;
  SDL_Point food;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  void PlaceFood(RendererBase &);
  void Update(RendererBase &);
};

#endif