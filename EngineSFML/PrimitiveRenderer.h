#pragma once
#include <SFML/Graphics.hpp>
#include "Engine.h"
class PrimitiveRenderer 
{
public:
	sf::RectangleShape pixel;

	void put_pixel(sf::RenderWindow& window,float x, float y, sf::Color color);
    void rysuj_linie(sf::RenderWindow& window,int x0, int y0, int x1, int y1, sf::Color kolor);

};

/*
*    Vertex piksel;
    piksel.position = Vector2f(x, y);
    piksel.color = color;

    window.draw(&piksel, 1, Points);
    window.display();
*/