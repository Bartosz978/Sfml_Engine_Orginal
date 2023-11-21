#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
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
	void rysuj_inny_punkt(sf::RenderWindow& window, unsigned int x, unsigned int y, sf::Color color);
	void przesun(sf::RenderWindow& window,int x_Celowy,int y_Celowy, sf::Color color);
	void rotacja(sf::RenderWindow& window, int x_Celowy, int y_Celowy, sf::Color color);
};

