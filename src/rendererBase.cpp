#include "rendererBase.h"
#include <iostream>
#include <string>


RendererBase::RendererBase(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Texture
  img = IMG_Load("../build/desert.bmp");
  texture = SDL_CreateTextureFromSurface(sdl_renderer, img);
  screen.x = 0;
  screen.y = 100;
  screen.w = 100;
  screen.h = 100;
}

RendererBase::~RendererBase() {
  SDL_FreeSurface(img);
  SDL_DestroyRenderer(sdl_renderer);
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void RendererBase::UpdateWindowTitle(int score, int fps) {
  std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}

bool RendererBase::collision(Snake snake){
  int factor = screen_width/grid_width;
  if((factor*static_cast<int>(snake.head_x) >= obstacleUp.x && factor*static_cast<int>(snake.head_x) <= (obstacleUp.x + obstacleUp.w)) &&
     (factor*static_cast<int>(snake.head_y) >= obstacleUp.y && factor*static_cast<int>(snake.head_y) <= (obstacleUp.y + obstacleUp.h))){
      return true;
    }

  if((factor*static_cast<int>(snake.head_x) >= obstacleMid.x && factor*static_cast<int>(snake.head_x) <= (obstacleMid.x + obstacleMid.w)) &&
     (factor*static_cast<int>(snake.head_y) >= obstacleMid.y && factor*static_cast<int>(snake.head_y) <= (obstacleMid.y + obstacleMid.h))){
      return true;
    }

    if((factor*static_cast<int>(snake.head_x) >= obstacleDown.x && factor*static_cast<int>(snake.head_x) <= (obstacleDown.x + obstacleDown.w)) &&
     (factor*static_cast<int>(snake.head_y) >= obstacleDown.y && factor*static_cast<int>(snake.head_y) <= (obstacleDown.y + obstacleDown.h))){
      return true;
    }
  
  return false;

}

bool RendererBase::ObstacleCell(int x, int y){
  if((x >= obstacleUp.x && x <= (obstacleUp.x + obstacleUp.w)) &&
     (y >= obstacleUp.y && y <= (obstacleUp.y + obstacleUp.h))){
       return true;
     }

  if((x >= obstacleMid.x && x <= (obstacleMid.x + obstacleMid.w)) &&
     (y >= obstacleMid.y && y <= (obstacleMid.y + obstacleMid.h))){
       return true;
     }

  if((x >= obstacleDown.x && x <= (obstacleDown.x + obstacleDown.w)) &&
     (y >= obstacleDown.y && y <= (obstacleDown.y + obstacleDown.h))){
       return true;
     }

  return false;

}
