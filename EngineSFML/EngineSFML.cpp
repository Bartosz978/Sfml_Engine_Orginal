#include <SFML/Graphics.hpp>
#include "Point2D.h"
#include "Engine.h"
#include "PrimitiveRenderer.h"
#include "LineSegment.h"
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <cmath>
#include "Player.h"
#include "Obstacle.h"
#include <vector>

using namespace std;
using namespace sf;
void f1() {
    cout << "Dzialam" << endl;
}


int main()
{
   // Point2D point(0,0);
   Engine gra;
   //gra.window.clear(Color::Blue);
   //gra.window.display();
  // LineSegment linia(0,0,0,0);
    gra.inicjalizacja(1600, 800, "Gra", false);
    PrimitiveRenderer GRA;
    Texture playerTexture, grassTexture, platformTexture, boxTexture, flagTexture;
    playerTexture.loadFromFile("images/player.bmp");
    grassTexture.loadFromFile("images/grass.bmp");
    platformTexture.loadFromFile("images/platform.bmp");
    boxTexture.loadFromFile("images/box.bmp");
    flagTexture.loadFromFile("images/flag.bmp");
    
    Player player(&playerTexture, sf::Vector2u(3, 2), 0.4f, 150.0f, 150.0f);

    vector<Obstacle> przeszkody;
    
    przeszkody.push_back(Obstacle(&platformTexture, Vector2f(200.0f, 50.0f), sf::Vector2f(500.0f, 600.0f)));
    przeszkody.push_back(Obstacle(&platformTexture, Vector2f(200.0f, 50.0f), sf::Vector2f(775.0f, 525.0f)));
    przeszkody.push_back(Obstacle(&platformTexture, Vector2f(200.0f, 50.0f), sf::Vector2f(1050.0f, 450.0f)));
    przeszkody.push_back(Obstacle(&platformTexture, Vector2f(200.0f, 50.0f), sf::Vector2f(1325.0f, 325.0f)));

    przeszkody.push_back(Obstacle(&grassTexture, Vector2f(1600.0f, 200.0f), sf::Vector2f(800.0f, 800.0f)));

    przeszkody.push_back(Obstacle(&boxTexture, Vector2f(100.0f, 100.0f), sf::Vector2f(50.0f, 650.0f)));
    przeszkody.push_back(Obstacle(&boxTexture, Vector2f(100.0f, 100.0f), sf::Vector2f(50.0f, 550.0f)));
    przeszkody.push_back(Obstacle(&boxTexture, Vector2f(100.0f, 100.0f), sf::Vector2f(1550.0f, 650.0f)));
    przeszkody.push_back(Obstacle(&boxTexture, Vector2f(100.0f, 100.0f), sf::Vector2f(1550.0f, 550.0f)));

    przeszkody.push_back(Obstacle(&flagTexture, Vector2f(125.0f, 125.0f), sf::Vector2f(1350.0f, 225.0f)));
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
   // GRA.rysuj_czworokat_wypelniony(gra.window, 10, 100, 100, 50, 50, 70, 150, 150, Color::Green);
  //  GRA.rysuj_kwadrat(gra.window, 10, 100, 100, 10, 50, 70, 150, 150, Color::Green,1);
    //GRA.rysuj_linie(gra.window, 10, 50, 100, 70, Color::Yellow, 1);
  //  GRA.rysuj_linie(gra.window, 100, 70, 100, 150, Color::Yellow, 1);
  //  GRA.rysuj_ellipse(gra.window, 10, 100, 200, 200, Color::White, 1);
 //  GRA.rysuj_trojkat_wypelniony(gra.window, 50, 50, 60, 50, 100, 100, Color::Yellow);
    //sf::Texture texture;
    //texture.create(gra.window.getSize().x, gra.window.getSize().y);
    //texture.update(gra.window);
    //sf::Image image = texture.copyToImage();
    //point.przesun(gra.window, 100, 100, Color::Red);
  //  gra.window.display();

    // Zapis obrazu na dysk
    /*if (image.saveToFile("nazwa_obrazu.png")) {
        std::cout << "Obraz został pomyślnie zapisany." << std::endl;
    }
        int d = 0;*/
  //  d = pixelColor.g+pixelColor.r+pixelColor.b;
   // cout << d;
//point = linia.zwracam_odcinek(Poczotek);
void(*wskaznik)() = &f1;
float czasDelta = 0.0f;
Clock clock;
while (player.getPosition().x)
{
    czasDelta = clock.restart().asSeconds();
    Event event;
    if (gra.window.pollEvent(event)) {
        gra.Mysz_prawy_nacisniety(wskaznik, event);
    }
    player.updatePlayer(czasDelta);
    Vector2f kierunek;

    Collider kolizja = player.zwrocKolizje();
    
    for(Obstacle& obstacle : przeszkody)
        if(obstacle.zwrocKolizje().sprawdzKolizje(kolizja, kierunek, 1.0f))  player.collisionPlayer(kierunek);
    
    gra.window.clear(Color(150, 150, 150));
    player.drawPlayer(gra.window);
    
    for(Obstacle& obstacle : przeszkody)
        obstacle.rysuj(gra.window);
    
    gra.window.display();
}
    gra.petla_gry();
   
    return 0;
}