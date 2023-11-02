#include "Engine.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int Engine::inicjalizajcja(unsigned int X, unsigned int Y,string Tytul,bool pelny_ekran){
	if(pelny_ekran){
		VideoMode fullscreen = VideoMode::getFullscreenModes()[0];
		window.create(fullscreen, Tytul);
	}
	else
	window.create(VideoMode(X, Y), Tytul);

	return 0;
}
void Engine::petla_gry() {
	while (window.isOpen()) {

	}
}
void Engine::Klawiatura(string przycisk) {
	Event event;
	if(event.type == )
}
