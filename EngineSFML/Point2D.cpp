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
void Point2D::rysuj_inny_punkt(sf::RenderWindow& window,unsigned int x,unsigned int y, Color color) {
	RectangleShape pixel;
	pixel.setSize(Vector2f(5.0f, 5.0f));
	pixel.setFillColor(color);
	pixel.setPosition(x, y);
	window.draw(pixel);
//	window.display();

}
void Point2D::przesun(RenderWindow& window, int x_Celowy, int y_Celowy, Color color) {

	Texture texture;
	texture.create(window.getSize().x, window.getSize().y);
	texture.update(window);
	Image image = texture.copyToImage();
	
	Vector2i poczotek = Point2D::zwruc_punkt();
	int roznica_X = abs(x_Celowy - poczotek.x);
	int roznica_Y = abs(y_Celowy - poczotek.y);
	Color tmp;
	float C = sqrt(pow(roznica_X, 2) + pow(roznica_Y, 2));
	float deltaX = (float)roznica_X / (float)C;
	float deltaY = (float)roznica_Y / (float)C;
	float stary_X = 0, stary_Y = 0, nowy_X=poczotek.x,nowy_Y=poczotek.y;

	for (int i = 0; i <C ; i++) {
		stary_X = nowy_X;
		stary_Y = nowy_Y;
		//tmp = (image.getPixel(stary_X, stary_Y).a == 0) ? Color::Black : image.getPixel(stary_X , stary_Y );
		
		//Point2D::rysuj_inny_punkt(window,stary_X , stary_Y, Color::Black);
		window.clear(Color::Black);
		nowy_X = poczotek.x + ((i + 1) * deltaX);
		nowy_Y = poczotek.y + ((i + 1) * deltaY);
		//Point2D::edytuj(nowy_X, nowy_Y);
		Point2D::rysuj_inny_punkt(window, nowy_X, nowy_Y, Color::Red);
		window.display();
		sleep(seconds(0.1));

		
		
	}


}

Point2D::Point2D(unsigned int x, unsigned int y) {
	X_P = x;
	Y_P = y;
}
