#pragma once
#include "Animacja.h"
#include "Collider.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

class Player {
    public:
    sf::RectangleShape player;
    Animacja animacja;
    float predkosc;
    unsigned int wiersz;
    bool kierunekPrawo;
    
    sf::Vector2f szybkosc;
    bool skokMozliwy;
    float wysokoscSkoku;

    Player(sf::Texture* texture,sf::Vector2u licznikObr, float czasZmiany, float predkosc, float wysokoscSkoku);

    void drawPlayer(sf::RenderWindow& window);
    void updatePlayer(float czasDelta);
    void collisionPlayer(sf::Vector2f kierunek);

    sf::Vector2f zwrocPozycje()
    {
        return player.getPosition();
    }
    Collider zwrocKolizje()
    {
        return Collider(player);
    }
};