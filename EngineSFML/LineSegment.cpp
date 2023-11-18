#include "LineSegment.h"
using namespace std;
using namespace sf;

Point2D LineSegment::zwracam_odcinek(enum Odcinek Odcinek) {
	Point2D wynik;
	wynik = linia[Odcinek];

	return wynik;
}
LineSegment::LineSegment() {
	Point2D punkt;

	Point2D punkt1;

	linia.push_back(punkt);
	linia.push_back(punkt1);
}
void LineSegment::Edytuj(unsigned int nowy_X, unsigned int nowy_Y, enum Odcinek odcinek) {
	linia[odcinek].X_P = nowy_X;
	linia[odcinek].Y_P = nowy_Y;
}
void LineSegment::Rysuj(RenderWindow& window, int x0, int y0, int x1, int y1, Color kolor) {
	PrimitiveRenderer pomoc;
	pomoc.rysuj_linie(window, x0, y0, x1, y1, kolor);
}