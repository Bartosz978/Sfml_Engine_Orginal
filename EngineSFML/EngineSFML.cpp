#include <SFML/Graphics.hpp>
#include "Point2D.h"
#include "Engine.h"
#include "PrimitiveRenderer.h"
#include "LineSegment.h"
#include <iostream>
#include <cmath>

using namespace std;
using namespace sf;
void f1() {
    cout << "Dzialam" << endl;
}


int main()
{
    Point2D point(0,0);
   Engine gra;
   gra.window.clear(Color::Blue);
   gra.window.display();
  // LineSegment linia(0,0,0,0);
    gra.inicjalizajcja(500, 500, "Gra", false);
    PrimitiveRenderer GRA;
 /*
 // gra.wypelnij_ekran(Color::Magenta);
GRA.put_pixel(gra.window,100, 100, Color::Red);
GRA.rysuj_linie(gra.window,1,100,400,400,Color::Blue);
GRA.rysuj_okrag(gra.window, 100, 100, 60, Color::Yellow);
GRA.rysuj_kwadrat(gra.window, 10, 100, 150, 40, 10, 10, 100, 100, Color::Blue);
GRA.rysuj_trojkat(gra.window, 10, 50, 60, 40, 40, 90, Color::Red);
GRA.rysuj_okrag_pelny(gra.window, 350, 150, 75, Color::Yellow);
*/
  ;

   // GRA.rysuj_trojkat(gra.window, 10, 50, 60, 40, 40, 90, Color::Red,2);
    //GRA.rysuj_linie(gra.window, 50, 30, 70, 100, Color::Yellow);
   // point.rysuj(gra.window, Color::Red);
   // GRA.rysuj_trojkat_pelny(gra.window, 0, 0, 1000, 0, 1000, 1000, Color::Green);
    //GRA.rysuj_czworokat_pelny(gra.window, 300, 700, 700, 300,300, 300, 700, 700, Color::Blue);
   
  /*for (int i = 0; i < 100; i++) {
      for (int j = 0; j < 200; j++)
      {
          GRA.put_pixel(gra.window, i*10, j*5, Color::Green);
      }
  }*/

    //GRA.rysuj_okrag_pelny(gra.window, 350, 150, 75, Color::Yellow);
    GRA.rysuj_czworokat_wypelniony(gra.window, 10, 100, 100, 50, 50, 70, 150, 150, Color::Green);
  //  GRA.rysuj_kwadrat(gra.window, 10, 100, 100, 10, 50, 70, 150, 150, Color::Green,1);
    //GRA.rysuj_linie(gra.window, 10, 50, 100, 70, Color::Yellow, 1);
  //  GRA.rysuj_linie(gra.window, 100, 70, 100, 150, Color::Yellow, 1);
    GRA.rysuj_ellipse(gra.window, 10, 100, 200, 200, Color::White, 1);
   GRA.rysuj_trojkat_wypelniony(gra.window, 50, 50, 60, 50, 100, 100, Color::Yellow);
    sf::Texture texture;
    texture.create(gra.window.getSize().x, gra.window.getSize().y);
    texture.update(gra.window);
    sf::Image image = texture.copyToImage();
    gra.window.display();

    // Zapis obrazu na dysk
    if (image.saveToFile("nazwa_obrazu.png")) {
        std::cout << "Obraz został pomyślnie zapisany." << std::endl;
    }
        int d = 0;
  //  d = pixelColor.g+pixelColor.r+pixelColor.b;
   // cout << d;
//point = linia.zwracam_odcinek(Poczotek);
void(*wskaznik)() = &f1;
while (true)
{
    Event event;
    if (gra.window.pollEvent(event)) {
        gra.Mysz_prawy_nacisniety(wskaznik, event);
    }
}



    gra.petla_gry();
   


    return 0;
}