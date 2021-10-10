#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;
  

 private:
  Snake snake;
  SDL_Point food;
  SDL_Point poison;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w1;
  std::uniform_int_distribution<int> random_h1;
  std::uniform_int_distribution<int> random_w2;
  std::uniform_int_distribution<int> random_h2;

  int score{0};
  

  void PlaceFood();
  void PlacePoison();
  void Update();
};

#endif