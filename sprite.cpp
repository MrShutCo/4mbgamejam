#include "sprite.hpp"

Sprite::Sprite(std::string textureFile){
    this->textureName = textureFile;
    loadTexture();
}

Sprite::~Sprite(){
    SDL_FreeSurface(texture);
    texture = NULL;
}

void Sprite::Draw(SDL_Surface* bufferSurface){
    SDL_BlitSurface(texture, NULL, bufferSurface, NULL );
}

void Sprite::loadTexture(){
    //Load image at specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP(this->textureName.c_str());
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", this->textureName.c_str(), SDL_GetError() );
	}

	texture = loadedSurface;
}