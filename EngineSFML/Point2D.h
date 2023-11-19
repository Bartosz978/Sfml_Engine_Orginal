#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
//#include "PrimitiveRenderer.h"

class Point2D 
{
public:
	int X_P;
	int Y_P;



	Point2D(unsigned int x,unsigned int y );
	sf::Vector2i zwruc_punkt();
	void edytuj(unsigned int x, unsigned int y);
	void rysuj(sf::RenderWindow& window, sf::Color color);
	
};

