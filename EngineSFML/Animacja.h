#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
class Animacja {
private:
    float czasZmiany;
    float czasCalkowity;

    sf::Vector2u licznikObr;
    sf::Vector2u wyswietlObr;

public:
    sf::IntRect texRect;

    Animacja(sf::Texture* texture, sf::Vector2u licznikObr, float czasZmiany);
    void Update(float czasDelta, int wiersz, bool kierunekPrawo);
};