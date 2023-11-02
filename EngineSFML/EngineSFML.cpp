#include <SFML/Graphics.hpp>
#include "Engine.h"

using namespace std;
using namespace sf;

int main()
{
    Engine gra;
    gra.inicjalizajcja(600, 700, "Gra", false);
    gra.petla_gry();
    return 0;
}