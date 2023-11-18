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
};

enum Odcinek
{
	Poczotek = 0,
	Koniec = 1
};

