#ifndef PlayZone_H
#define PlayZone_H

#include <vector>
#ifdef WINDOWS
    #include "ui_layer/sdl/include/windows/SDL.h"
    #include "ui_layer/sdl/include/windows/SDL2_gfxPrimitives.h"
    #include "ui_layer/sdl/include/windows/SDL_ttf.h"
#else
    #include "ui_layer/sdl/include/linux/SDL.h"
    #include "ui_layer/sdl/include/linux/SDL2_gfxPrimitives.h"
    #include "ui_layer/sdl/include/linux/SDL_ttf.h"
#endif
#include "domain_layer/snake/Snake.hpp"

class PlayZone {
 public:
  PlayZone(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~PlayZone();

  void Render(Snake const snake, SDL_Point const &food);
  void UpdateWindowTitle(int score, int fps);
  void PlaceFood(Snake snake,SDL_Point food); // to place food on the screen

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif