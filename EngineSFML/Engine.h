#pragma once
#include <SFML/Graphics.hpp>

class Engine
{
public:
	sf::RenderWindow window;

	int inicjalizajcja(unsigned int X,unsigned int Y, std::string Tytul,bool pelny_ekran);
	void petla_gry();
	void Klawiatura(std::string przycisk);
};

