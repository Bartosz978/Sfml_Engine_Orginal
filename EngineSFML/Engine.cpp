#include "Engine.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int Engine::inicjalizacja(unsigned int X, unsigned int Y,string Tytul,bool pelny_ekran){
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
		Engine::run();

	}
}
void Engine::Klawiatura(char przycisk, void(*wskaznik_na_funckje)(),Event event){
	
		if (event.type == Event::KeyPressed) {
			if (Keyboard::isKeyPressed(Keyboard::Key(przycisk))) {
				wskaznik_na_funckje();
			}
		
	}
}
/*
void Engine::wypelnij_ekran(Color kolor) {
	window.clear(kolor);
	window.display();
}*/
void Engine::Mysz_prawy_nacisniety(void(*wskaznik_na_funckje)(), Event event) {
	if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Right) {
		wskaznik_na_funckje();
	}
}

void Engine::Mysz_prawy_zrelaksowany(void(*wskaznik_na_funckje)(), Event event) {
	if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Right) {
		wskaznik_na_funckje();
	}
}

void Engine::Mysz_lewy_nacisniety(void(*wskaznik_na_funckje)(), Event event) {
	if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
		wskaznik_na_funckje();
	}
}

void Engine::Mysz_lewy_zrelaksowany(void(*wskaznik_na_funckje)(), Event event) {
	if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
		wskaznik_na_funckje();
	}
}

void Engine::Mysz_Ruch_nacisniety(void(*wskaznik_na_funckje)(), Event event) {
	if (event.type == Event::MouseMoved && event.mouseButton.button == Mouse::Left) {
		wskaznik_na_funckje();
	}
}

void Engine::run(){}