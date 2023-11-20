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
  // LineSegment linia(0,0,0,0);
    gra.inicjalizajcja(1000, 1000, "Gra", false);
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
    GRA.rysuj_czworokat_wypelniony(gra.window, 10, 100, 100, 10, 10, 10, 100, 100, Color::Green);
    gra.window.display();

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