#include <SFML/Graphics.hpp>
#include "Engine.h"

using namespace std;
using namespace sf;



int main()
{
   Engine gra;
    gra.inicjalizajcja(600, 700, "Gra", false);
    gra.petla_gry();
  //  Przyklad F1;
    //F1.inicjalizajcja(600, 700, "tEST,", false);
    return 0;
}