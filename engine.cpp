#include "engine.hpp"

Engine::Engine(int width, int height){
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	 {
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        exit(1);
	}
    window = SDL_CreateWindow("Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    bufferSurface = SDL_GetWindowSurface(window);
}

Engine::~Engine(){
    SDL_DestroyWindow(window);
    window = NULL;
    SDL_Quit();
}

void Engine::AddSprite(Sprite* sprite) {
    sprites.push_back(sprite);
}

void Engine::Start(){
    EngineIsRunning = true;

    SDL_Event e;

    while (EngineIsRunning) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                EngineIsRunning = false;
            }

            //Draw all the different sprites
            for (auto* spr: sprites) {
                spr->Draw(bufferSurface);
            }

            SDL_UpdateWindowSurface(window);
        }
    }
}