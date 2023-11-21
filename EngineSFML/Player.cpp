#include "Player.h"
#include "Animacja.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

Player::Player(sf::Texture* texture, sf::Vector2u licznikObr, float czasZmiany, float predkosc)
    : animacja(texture, licznikObr, czasZmiany) {
    this->predkosc = predkosc;
    wiersz = 0;
    kierunekPrawo = true;

    player.setSize(sf::Vector2f(125.0f, 180.0f));
    player.setPosition(300.0f, 300.0f);
    player.setTexture(texture);
}

void Player::updatePlayer(float czasDelta) {
    sf::Vector2f ruch(0.0f, 0.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        ruch.x -= predkosc * czasDelta;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        ruch.x += predkosc * czasDelta;
    }

    if (ruch.x == 0.0f)
        wiersz = 0;
    else {
        wiersz = 1;

        if (ruch.x > 0.0f)
            kierunekPrawo = true;
        else
            kierunekPrawo = false;
    }
    animacja.Update(czasDelta, wiersz, kierunekPrawo);
    player.setTextureRect(animacja.texRect);
    player.move(ruch);
}

void Player::drawPlayer(sf::RenderWindow& window) {
    window.draw(player);
}