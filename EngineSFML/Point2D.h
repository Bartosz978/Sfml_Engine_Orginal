#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include "PrimitiveRenderer.h"

class Point2D 
{
public:
	int X_P;
	int Y_P;
	sf::RectangleShape pixel;


	Point2D();
	sf::Vector2i zwruc_punkt();
	void edytuj(unsigned int x, unsigned int y);
	void rysuj(sf::RenderWindow& window, unsigned int x, unsigned int y, sf::Color color);
	
};

