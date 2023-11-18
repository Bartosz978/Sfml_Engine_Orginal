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
void Point2D::rysuj(sf::RenderWindow& window, unsigned int x, unsigned int y,Color color) {
	PrimitiveRenderer::put_pixel(window, (float)x, (float)y, color);
}

Point2D::Point2D() {
	X_P = 0;
	Y_P = 0;
}
