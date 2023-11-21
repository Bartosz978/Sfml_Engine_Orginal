#include "Animacja.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

Animacja::Animacja(sf::Texture* texture, sf::Vector2u licznikObr, float czasZmiany) {
    this->licznikObr = licznikObr;
    this->czasZmiany = czasZmiany;
    czasCalkowity = 0.0f;
    wyswietlObr.x = 0;

    texRect.width = texture->getSize().x / float(licznikObr.x);
    texRect.height = texture->getSize().y / float(licznikObr.y);
}

void Animacja::Update(float czasDelta, int wiersz, bool kierunekPrawo) {
    wyswietlObr.y = wiersz;
    czasCalkowity += czasDelta;

    if (czasCalkowity >= czasZmiany)
    {
        czasCalkowity -= czasZmiany;
        wyswietlObr.x++;


        if (wyswietlObr.x >= licznikObr.x) {
            wyswietlObr.x = 0;
        }
    }
    texRect.top = wyswietlObr.y * texRect.height;

    if (kierunekPrawo)
    {
        texRect.left = wyswietlObr.x * texRect.width;
        texRect.width = abs(texRect.width);
    }
    else
    {
        texRect.left = (wyswietlObr.x + 1) * abs(texRect.width);
        texRect.width = -abs(texRect.width);
    }
}