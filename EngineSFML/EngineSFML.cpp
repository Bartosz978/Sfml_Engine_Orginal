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
   LineSegment linia(0,0,0,0);
    gra.inicjalizajcja(800, 800, "Gra", false);
    PrimitiveRenderer GRA;
 /*
 // gra.wypelnij_ekran(Color::Magenta);
GRA.put_pixel(gra.window,100, 100, Color::Red);
GRA.rysuj_linie(gra.window,1,100,400,400,Color::Blue);
GRA.rysuj_okrag(gra.window, 100, 100, 60, Color::Yellow);
GRA.rysuj_kwadrat(gra.window, 10, 100, 150, 40, 10, 10, 100, 100, Color::Blue);
GRA.rysuj_trojkat(gra.window, 10, 50, 60, 40, 40, 90, Color::Red);
GRA.rysuj_okrag_pelny(gra.window, 350, 150, 75, Color::Yellow);
GRA.rysuj_trojkat_pelny(gra.window, 30, 200, 80, 700, 750, 500, Color::Green);
GRA.rysuj_czworokat_pelny(gra.window, 483, 636, 563, 332, 499, 580, 766, 563, Color::Blue);
*/

   // GRA.rysuj_trojkat(gra.window, 10, 50, 60, 40, 40, 90, Color::Red);
    GRA.rysuj_linie(gra.window, 50, 30, 70, 100, Color::Yellow);
    point.rysuj(gra.window, Color::Red);
   
point = linia.zwracam_odcinek(Poczotek);
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