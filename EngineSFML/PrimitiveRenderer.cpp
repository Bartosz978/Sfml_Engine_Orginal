#include "PrimitiveRenderer.h"

using namespace std;
using namespace sf;

void PrimitiveRenderer::put_pixel(RenderWindow& window, float x, float y, Color color) {
	pixel.setSize(Vector2f(5.0f, 5.0f));
	pixel.setFillColor(color);
	pixel.setPosition(x, y);
	window.draw(pixel);
	window.display();

}
void PrimitiveRenderer::rysuj_linie(RenderWindow& window,int x0, int y0, int x1, int y1, Color kolor) {
    int x;
    float dy, dx, y, m;
    dy = static_cast<float>(y1 - y0);
    dx = static_cast<float>(x1 - x0);

    if (dx == 0) {

        if (y0 > y1) {
            swap(y0, y1);
        }
        for (int y = y0; y <= y1; y++) {
            PrimitiveRenderer::put_pixel(window,x0,y,kolor);
        }
    }
    else {
        m = dy / dx;
        y = static_cast<float>(y0);

        for (x = x0; x <= x1; x++) {
            put_pixel(window,x, static_cast<int>(y + 0.5), kolor);
            y += m;
        }
    }
}
void PrimitiveRenderer:: rysuj_kwadrat(RenderWindow& window,int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4, sf::Color kolor) {
    PrimitiveRenderer::rysuj_linie(window, x1, y1, x2, y2, kolor);
    PrimitiveRenderer::rysuj_linie(window, x2, y2, x3, y3, kolor);
    PrimitiveRenderer::rysuj_linie(window, x4, y4, x3, y3, kolor);
    PrimitiveRenderer::rysuj_linie(window, x4, y4, x1, y1, kolor);
}