#include "PrimitiveRenderer.h"

using namespace std;
using namespace sf;

void PrimitiveRenderer::put_pixel(RenderWindow& window, float x, float y, Color color,int rozmiar) {
	pixel.setSize(Vector2f((float)rozmiar, (float)rozmiar));
	pixel.setFillColor(color);
	pixel.setPosition(x, y);
	window.draw(pixel);
   //window.display();

}
void PrimitiveRenderer::rysuj_linie(RenderWindow& window, int x0, int y0, int x1, int y1, Color kolor, int rozmiar) {
    int x, p;
    int dy, dx, y, endY;
    dy = abs(y1 - y0);
    dx = abs(x1 - x0);
    p = 2 * dx - dy;

    if (y0 == y1) {
        if (x0 > x1) {
            swap(x0, x1);
        }
        for (int xi = x0; xi <= x1; xi++) {
            put_pixel(window, xi, y0, kolor,rozmiar);
        }
        return;
    }

    if (y0 > y1) {
        y = y1;
        x = x1;
        endY = y0;
    }
    else {
        y = y0;
        x = x0;
        endY = y1;
    }

    put_pixel(window, x, y, kolor,rozmiar);

    while (y < endY) {
        y++;
        if (p < 0) {
            p = p + 2 * dx;
        }
        else {
            x++;
            p = p + 2 * (dx - dy);
        }
        put_pixel(window, x, y, kolor,rozmiar);
    }
}
void PrimitiveRenderer::rysuj_okrag(RenderWindow& window, int x0, int y0, int radius, Color color,int rozmiar)
{
    float alpha = 0;
    while (alpha <= 2 * 3.14159265358979323846) {
        int x = static_cast<int>(x0 + radius * cos(alpha));
        int y = static_cast<int>(y0 + radius * sin(alpha));
        PrimitiveRenderer::put_pixel(window, x, y, color,rozmiar);
        alpha += 0.01; // Zwiêksz k¹t o ma³¹ wartoœæ
    }
   // window.display();
}

void PrimitiveRenderer:: rysuj_kwadrat(RenderWindow& window,int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4, Color kolor,int rozmiar) {
    PrimitiveRenderer::rysuj_linie(window, x1, y1, x2, y2, kolor, rozmiar);
    PrimitiveRenderer::rysuj_linie(window, x2, y2, x3, y3, kolor, rozmiar);
    PrimitiveRenderer::rysuj_linie(window, x4, y4, x3, y3, kolor, rozmiar);
    PrimitiveRenderer::rysuj_linie(window, x1, y1, x4, y4, kolor, rozmiar);
}
void PrimitiveRenderer::rysuj_trojkat(RenderWindow& window, int x1, int x2, int x3, int y1, int y2, int y3, Color kolor,int rozmiar) {
    PrimitiveRenderer::rysuj_linie(window, x1, y1, x2, y2, kolor, rozmiar);
    PrimitiveRenderer::rysuj_linie(window, x2, y2, x3, y3, kolor, rozmiar);
    PrimitiveRenderer::rysuj_linie(window, x1, y1, x3, y3, kolor, rozmiar);
}
void PrimitiveRenderer::rysuj_okrag_pelny(RenderWindow& window, int x0, int y0, int radius, Color color)
{
    for (int y = -radius; y <= radius; ++y) {
        for (int x = -radius; x <= radius; ++x) {
            if (x * x + y * y <= radius * radius) {
                int x_pixel = x0 + x;
                int y_pixel = y0 + y;
                PrimitiveRenderer::put_pixel(window,(float) x_pixel, (float) y_pixel, color,10);
            }
        }
    }
}
void PrimitiveRenderer::rysuj_trojkat_pelny(RenderWindow& window, int x1, int x2, int x3, int y1, int y2, int y3, Color kolor) {
    sf::VertexArray lines(sf::LinesStrip, 4);

    lines[0].position = sf::Vector2f(x1, y1);
    lines[1].position = sf::Vector2f(x2, y2);
    lines[2].position = sf::Vector2f(x3, y3);
    lines[3].position = sf::Vector2f(x1, y1);  // Zamykamy kontur

    lines[0].color = kolor;
    lines[1].color = kolor;
    lines[2].color = kolor;
    lines[3].color = kolor;

    window.draw(lines);
   
    // Scanline filling
    int minY = std::min({ y1, y2, y3 });
    int maxY = std::max({ y1, y2, y3 });

    for (int y = minY; y < maxY; y++) {
        int xl = std::numeric_limits<int>::max();
        int xr = std::numeric_limits<int>::min();

        for (int i = 0; i < 3; i++) {
            int x1 = lines[i].position.x;
            int y1 = lines[i].position.y;
            int x2 = lines[i + 1].position.x;
            int y2 = lines[i + 1].position.y;

            int x3 = lines[i == 2 ? 0 : i + 2].position.x;
            int y3 = lines[i == 2 ? 0 : i + 2].position.y;

            if ((y1 <= y && y2 > y) || (y2 <= y && y1 > y)) {
                int xi = x1 + (y - y1) * (x2 - x1) / (y2 - y1);
                if (xi < xl) xl = xi;
                if (xi > xr) xr = xi;
            }

            if ((y1 <= y && y3 > y) || (y3 <= y && y1 > y)) {
                int xi = x1 + (y - y1) * (x3 - x1) / (y3 - y1);
                if (xi < xl) xl = xi;
                if (xi > xr) xr = xi;
            }
        }

        if (xl <= xr) {
            sf::VertexArray line(sf::Lines, 2);
            line[0].position = sf::Vector2f(xl, y);
            line[1].position = sf::Vector2f(xr, y);
            line[0].color = kolor;
            line[1].color = kolor;
            window.draw(line);
        }
    }
    
    window.display(); //NIE USUWAJCIE TEGO ANI MI SIÊ WA¯!!!
}
void PrimitiveRenderer::rysuj_czworokat_pelny(RenderWindow& window, int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4, Color kolor) {
    // Definiowanie wierzcho³ków czworok¹ta
    Vertex linie[5]; // Tablica zawieraj¹ca 5 wierzcho³ków (czworo dla konturów i jeden dla zamkniêcia konturów)

    linie[0] = Vertex(Vector2f(x1, y1), kolor);
    linie[1] = Vertex(Vector2f(x2, y2), kolor);
    linie[2] = Vertex(Vector2f(x3, y3), kolor);
    linie[3] = Vertex(Vector2f(x4, y4), kolor);
    linie[4] = linie[0]; // Zamkniêcie konturów przez powrót do pierwszego wierzcho³ka

    // Rysowanie konturów czworok¹ta
    window.draw(linie, 5, LinesStrip);
    
    // Implementacja Scanline Filling
    int minY = std::min({ y1, y2, y3, y4 });
    int maxY = std::max({ y1, y2, y3, y4 });

    for (int y = minY + 1; y < maxY; y++) {
        std::vector<int> intersections;

        for (int i = 0; i < 4; i++) {
            int x1 = linie[i].position.x;
            int y1 = linie[i].position.y;
            int x2 = linie[i + 1].position.x;
            int y2 = linie[i + 1].position.y;

            if ((y1 <= y && y2 > y) || (y2 <= y && y1 > y)) {
                // Oblicz wspó³rzêdne punktu przeciêcia linii z y
                int x = x1 + (static_cast<float>(y - y1) / (y2 - y1)) * (x2 - x1);
                intersections.push_back(x);
            }
        }

        if (intersections.size() >= 2) {
            // Sortuj punkty przeciêcia, aby narysowaæ odpowiednie odcinki
            std::sort(intersections.begin(), intersections.end());

            // Rysuj odcinki miêdzy punktami przeciêcia
            for (int i = 0; i < intersections.size() - 1; i += 2) {
                Vertex linia[2];
                linia[0] = Vertex(Vector2f(intersections[i], y), kolor);
                linia[1] = Vertex(Vector2f(intersections[i + 1], y), kolor);
                window.draw(linia, 2, Lines);
            }
        }
    }
  //  window.display();

}
void PrimitiveRenderer::Rysuj_Linie_lamana(RenderWindow& window, vector<Point2D>zbior_punktow, Color kolor,int rozmiar) {
  
   if(zbior_punktow.size() == 1 || zbior_punktow.size() == 0) {
        return;
    }
    for (int i = 0; i < zbior_punktow.size()-1; i++) {
        PrimitiveRenderer::rysuj_linie(window, zbior_punktow[i].X_P, zbior_punktow[i].Y_P, zbior_punktow[i+1].X_P, zbior_punktow[i+1].Y_P,kolor,rozmiar);
    }
}

void PrimitiveRenderer::rysuj_czworokat_wypelniony(sf::RenderWindow& window, int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4, sf::Color kolor) {
    PrimitiveRenderer::rysuj_kwadrat(window, x1, x2, x3, x4, y1, y2, y3, y4, kolor, 1);

    Texture teksture;
    teksture.create(window.getSize().x, window.getSize().y);
    teksture.update(window);
    Image image = teksture.copyToImage();
    Color pixelColor;

    int max_Y=0, max_X=0, min_X=0, min_Y=0;
    int tablicaX[4] = { x1,x2,x3,x4 };
    int tablicaY[4] = { y1,y2,y3,y4 };
    for (int i = 0; i < 4; i++) {
        if (max_X >= tablicaX[i]) {
            max_X = tablicaX[i];
        }
        if (max_Y >= tablicaY[i]) {
            max_Y = tablicaY[i];
        }
        if (min_X <=  tablicaX[i]) {
            min_X = tablicaX[i];
        }
        if (min_Y <= tablicaX[i]) {
            min_Y = tablicaX[i];
        }
    }
    for (int i = max_X; i < max_X; i++) {
        
    }
    
    
}