#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "PrimitiveRenderer.h"

using namespace std;
using namespace sf;



int main()
{
   Engine gra;
    gra.inicjalizajcja(400, 400, "Gra", false);
    PrimitiveRenderer GRA;
    
GRA.put_pixel(gra.window,100, 100, Color::Red);
//GRA.rysuj_linie(gra.window,1,100,400,400,Color::Blue);
GRA.rysuj_kwadrat(gra.window, 10, 100, 100, 10, 10, 10, 100, 100, Color::Blue);
GRA.rysuj_trojkat(gra.window, 10, 50, 60, 40, 40, 90,Color::Red);
  
    gra.petla_gry();
   
  //  Przyklad F1;
    //F1.inicjalizajcja(600, 700, "tEST,", false);
    return 0;
}