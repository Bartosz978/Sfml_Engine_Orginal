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


	linia.push_back(punkt);
}
