#include "Point2D.h"

using namespace std;
using namespace sf;

Vector2i Point2D::zwruc_punkt() {
	Vector2i vector2(Vector2i(X_P, Y_P));
	return vector2;
}
void Point2D::edytuj(unsigned int x, unsigned int y) {
	X_P = x;
	Y_P = y;
}
void Point2D::rysuj(sf::RenderWindow& window,Color color) {
	RectangleShape pixel;
	pixel.setSize(Vector2f(1.0f, 1.0f));
	pixel.setFillColor(color);
	pixel.setPosition(X_P, Y_P);
	window.draw(pixel);
	window.display();
	
}

Point2D::Point2D(unsigned int x, unsigned int y) {
	X_P = x;
	Y_P = y;
}
