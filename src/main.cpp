#include <iostream>
#include <stdio.h>
#include "controller.h"
#include "game.h"
#include "rendererBase.h"
#include "rendererZero.h"
#include "rendererOne.h"
#include "rendererTwo.h"
#include "SDL2/SDL.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000/ kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  int level;

  SDL_Init(SDL_INIT_VIDEO);

  std::cout << "LEVELS OF DIFICULTY:" << std::endl;
  std::cout << "        LEVEL EASY : TYPE 0" << std::endl;
  std::cout << "LEVEL INTERMEDIATE : TYPE 1" << std::endl;
  std::cout << "        LEVEL HARD : TYPE 2" << std::endl;
  
  std::cout << "CHOOSE LEVEL OF DIFICULTY:" << std::endl;
  std::cin >> level;

  Controller controller;
  RendererBase *renderer;
  Game *game;

  if (level == 0){
    renderer = new RendererZero(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  }else if (level == 1){
    renderer = new RendererOne(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  }else if (level == 2){
    renderer = new  RendererTwo(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  }else{
    std::cout << "Choose an valid Input!" << std::endl;
  }

  game = new Game(kGridWidth, kGridHeight, *renderer);
  game->Run(controller, kMsPerFrame);

  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game->GetScore() << "\n";
  std::cout << "Size: " << game->GetSize() << "\n";

  delete renderer;
  delete game;
    
  return 0;
}