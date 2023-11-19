#pragma once
#include <SFML/Graphics.hpp>
#include "Point2D.h"
#include "PrimitiveRenderer.h"
#include <vector>

class LineSegment 
{

private:
	std::vector<Point2D>linia;
public:
	
	LineSegment(unsigned int x_0, unsigned int y_0, unsigned int x_1, unsigned int y_1);
	Point2D zwracam_odcinek(enum Odcinek odcinek);
	void Edytuj(unsigned int nowy_X, unsigned int nowy_Y, enum Odcinek odcinek);
	void Rysuj(sf:: RenderWindow& window, sf::Color kolor);
};

enum Odcinek
{
	Poczotek = 0,
	Koniec = 1
};

