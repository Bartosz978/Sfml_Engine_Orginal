#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

class Point2D
{
private:
	int X_P;
	int Y_P;

public:
	sf::Vector2i zwruc_punkt();
	void edytuj(unsigned int x, unsigned int y);

	
};

