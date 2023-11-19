#include "LineSegment.h"
using namespace std;
using namespace sf;

Point2D LineSegment::zwracam_odcinek(enum Odcinek odcinek) {
	return linia[odcinek];
}
LineSegment::LineSegment(unsigned int x_0, unsigned int y_0, unsigned int x_1, unsigned int y_1) {
	Point2D punkt(x_0,y_0);

	Point2D punkt1(x_1,y_1);

	linia.push_back(punkt);
	linia.push_back(punkt1);
}
void LineSegment::Edytuj(unsigned int nowy_X, unsigned int nowy_Y, enum Odcinek odcinek) {
	linia[odcinek].X_P = nowy_X;
	linia[odcinek].Y_P = nowy_Y;
}
void LineSegment::Rysuj(RenderWindow& window, Color kolor) {
	PrimitiveRenderer pomoc;
	pomoc.rysuj_linie(window, linia[0].X_P, linia[0].Y_P, linia[1].X_P, linia[1].Y_P, kolor);
}