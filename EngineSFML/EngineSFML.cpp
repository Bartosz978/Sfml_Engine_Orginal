#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "PrimitiveRenderer.h"
#include <iostream>
#include <cmath>

using namespace std;
using namespace sf;
void f1() {
    cout << "Dzialam" << endl;
}


int main()
{
    
   Engine gra;
    gra.inicjalizajcja(400, 400, "Gra", false);
    PrimitiveRenderer GRA;
 // gra.wypelnij_ekran(Color::Magenta);
GRA.put_pixel(gra.window,100, 100, Color::Red);
GRA.rysuj_linie(gra.window,1,100,400,400,Color::Blue);
GRA.rysuj_okrag(gra.window, 100, 100, 60, Color::Yellow);
GRA.rysuj_kwadrat(gra.window, 10, 100, 150, 40, 10, 10, 100, 100, Color::Blue);
GRA.rysuj_trojkat(gra.window, 10, 50, 60, 40, 40, 90, Color::Red);

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