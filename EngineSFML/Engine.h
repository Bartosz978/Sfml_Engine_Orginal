#pragma once
#include <SFML/Graphics.hpp>

class Engine
{
public:
	sf::RenderWindow window;

	 int inicjalizajcja(unsigned int X,unsigned int Y, std::string Tytul,bool pelny_ekran);
	 void petla_gry();
	 void Klawiatura(char przycisk,void(*wskaznik_na_funckje)(), sf::Event event);
	void Mysz_prawy_nacisniety(void(*wskaznik_na_funckje)(), sf::Event event);
 void Mysz_prawy_zrelaksowany(void(*wskaznik_na_funckje)(), sf::Event event);
	 void Mysz_lewy_nacisniety(void(*wskaznik_na_funckje)(), sf::Event event);
	void Mysz_lewy_zrelaksowany(void(*wskaznik_na_funckje)(), sf::Event event);
	 void Mysz_Ruch_nacisniety(void(*wskaznik_na_funckje)(), sf::Event event);

	 void wypelnij_ekran(sf::Color kolor);
	 virtual void run();
};

