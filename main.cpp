#include "engine.hpp"
#include "sprite.hpp"

int main( int argc, char* args[] )
{
    Engine engine{1024,768};
    engine.AddSprite(new Sprite{"img/pic.bmp"});

    engine.Start();

	return 0;
}