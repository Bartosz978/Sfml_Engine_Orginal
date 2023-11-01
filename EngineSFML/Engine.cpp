#include "Engine.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int Engine::inicjalizajcja(unsigned int X, unsigned int Y,string Tytul){

	window.create(VideoMode(X, Y), Tytul);

	return 0;
}
