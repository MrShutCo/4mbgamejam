#pragma once

#include <SDL2/SDL.h>
#include <vector>

#include "sprite.hpp"

class Engine {

public:
    int ScreenHeight;
    int ScreenWidth;

    bool EngineIsRunning;

    //The main game loop
    void Start();

    void AddSprite(Sprite*);

    Engine(int width, int height);
    ~Engine();
private:
    std::vector<Sprite*> sprites;
    SDL_Surface* bufferSurface; 
    SDL_Window* window;
};