#pragma once

#include <SDL2/SDL.h>
#include <string>

class Sprite {
public:
    void Draw(SDL_Surface* bufferSurface);

    Sprite(std::string textureName);
    ~Sprite();
private:
    std::string textureName;
    SDL_Surface* texture;
    void loadTexture();
};