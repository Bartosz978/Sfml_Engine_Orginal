#pragma once
#include "Animacja.h"
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


    Player(sf::Texture* texture, sf::Vector2u licznikObr, float czasZmiany, float speed);

    void drawPlayer(sf::RenderWindow& window);
    void updatePlayer(float czasDelta);

};