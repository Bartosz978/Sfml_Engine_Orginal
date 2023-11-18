#pragma once
#include <SFML/Graphics.hpp>
#include "Point2D.h"
#include <vector>

class LineSegment 
{

private:
	std::vector<Point2D>linia;
public:
	
	LineSegment();
	Point2D zwracam_odcinek(enum Odcinek odcinek);
	void Edytuj(unsigned int nowy_X, unsigned int nowy_Y, enum Odcinek odcinek);
	void Rysuj(sf:: RenderWindow& window, int x0, int y0, int x1, int y1, sf::Color kolor);
};

enum Odcinek
{
	Poczotek = 0,
	Koniec = 1
};

