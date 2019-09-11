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

}

RendererBase::~RendererBase() {
  SDL_DestroyRenderer(sdl_renderer);
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void RendererBase::UpdateWindowTitle(int score, int fps) {
  std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}

void RendererBase::drawHead(Snake const snake){

  int line1_x1 = 320;  int line1_x2 = 300;  int line1_y1 = 300; int line1_y2 = 340;
  int line2_x1 = 320;  int line2_x2 = 340;  int line2_y1 = 300; int line2_y2 = 340;
  int line3_x1 = 300;  int line3_x2 = 340;  int line3_y1 = 340; int line3_y2 = 340;


  SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);

  SDL_RenderDrawLine(sdl_renderer, line1_x1, line1_y1, line1_x2, line1_y2);
  SDL_RenderDrawLine(sdl_renderer, line2_x1, line2_y1, line2_x2, line2_y2);
  SDL_RenderDrawLine(sdl_renderer, line3_x1, line3_y1, line3_x2, line3_y2);
}