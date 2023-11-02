#pragma once
#include <SFML/Graphics.hpp>
#include "Engine.h"
class PrimitiveRenderer 
{
public:
	sf::RectangleShape pixel;

	void put_pixel(sf::RenderWindow& window,float x, float y, sf::Color color);
    void rysuj_linie(sf::RenderWindow& window,int x0, int y0, int x1, int y1, sf::Color kolor);
    
    void rysuj_kwadrat(sf::RenderWindow& window,int x1, int x2, int x3,int x4,int y1,int y2,int y3,int y4, sf::Color kolor);
    void rysuj_trojkat(int x1, int x2, int x3, int y1, int y2, int y3,sf::Color kolor);

};

/*
*    Vertex piksel;
    piksel.position = Vector2f(x, y);
    piksel.color = color;

    window.draw(&piksel, 1, Points);
    window.display();
*/