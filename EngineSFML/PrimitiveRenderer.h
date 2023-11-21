#pragma once
#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "Point2D.h"
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

class PrimitiveRenderer 
{
public:
	sf::RectangleShape pixel;

	void put_pixel(sf::RenderWindow& window,float x, float y, sf::Color color,int rozmiar);
    //void rysuj_linie(sf::RenderWindow& window,int x0, int y0, int x1, int y1, sf::Color kolor, int rozmiar);
    
    void rysuj_kwadrat(sf::RenderWindow& window,int x1, int x2, int x3,int x4,int y1,int y2,int y3,int y4, sf::Color kolor, int rozmiar);
    void rysuj_trojkat(sf::RenderWindow& window, int x1, int x2, int x3, int y1, int y2, int y3,sf::Color kolor,int rozmiar);
    void rysuj_okrag(sf::RenderWindow& window, int x0, int y0, int radius, sf::Color color, int rozmiar);
    void rysuj_okrag_pelny(sf::RenderWindow& window, int x0, int y0, int radius, sf::Color color);

    void rysuj_trojkat_pelny(sf::RenderWindow& window, int x1, int x2, int x3, int y1, int y2, int y3, sf::Color kolor);

    void rysuj_czworokat_pelny(sf::RenderWindow& window, int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4, sf::Color kolor);

    void rysuj_trojkat_wypelniony(sf::RenderWindow& window, int x1, int x2, int x3, int y1, int y2, int y3, sf::Color kolor);

    void rysuj_czworokat_wypelniony(sf::RenderWindow& window, int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4, sf::Color kolor);

    void Rysuj_Linie_lamana(sf::RenderWindow& window, std::vector<Point2D> zbior_punktow, sf::Color kolor, int rozmiar);
    void rysujOdcinek(RenderWindow& window, int& X0, int& Y0, int& X1, int& Y1, Color kolor, float rozmiar);
};

