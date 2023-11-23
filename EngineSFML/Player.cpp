#include "Player.h"
#include "Animacja.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <math.h>

Player::Player(sf::Texture* texture,sf::Vector2u licznikObr, float czasZmiany, float predkosc, float wysokoscSkoku) 
: animacja(texture, licznikObr, czasZmiany){
    this->predkosc = predkosc;
    this->wysokoscSkoku = wysokoscSkoku;
    wiersz = 0;
    kierunekPrawo = true;

    player.setSize(sf::Vector2f(95.0f, 151.0f));
    player.setOrigin(player.getSize() / 2.0f);
    player.setPosition(300.0f, 600.0f);
    player.setTexture(texture);
    }

void Player::updatePlayer(float czasDelta){

    szybkosc.x = 0.0f;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        szybkosc.x -= predkosc;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        szybkosc.x += predkosc;
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && skokMozliwy){
        skokMozliwy = false;
        szybkosc.y = -sqrtf(2.0f * 981.0f * wysokoscSkoku);
    }

    szybkosc.y += 981.0f * czasDelta;

    if (szybkosc.x == 0.0f)
        wiersz = 0;
    else {
        wiersz = 1;

    if (szybkosc.x > 0.0f)
        kierunekPrawo = true;
    else
        kierunekPrawo = false;
    }
    animacja.Update(czasDelta,wiersz,kierunekPrawo);
    player.setTextureRect(animacja.texRect);
    player.move(szybkosc * czasDelta);

    if (player.getPosition().x < 0 + player.getSize().x) player.setPosition(0 + player.getSize().x, player.getPosition().y);
    if (player.getPosition().x > 1600-player.getSize().x) player.setPosition(1600-player.getSize().x, player.getPosition().y);
}

void Player::drawPlayer(sf::RenderWindow& window) {
    window.draw(player);
}

void Player::collisionPlayer(sf::Vector2f kierunek)
{
    if (kierunek.x < 0.0f)  szybkosc.x = 0.0f;
    else if (kierunek.x > 0.0f) szybkosc.x = 0.0f;

    if (kierunek.y < 0.0f)
    {
        szybkosc.y = 0.0f;
    }
    else if (kierunek.y > 0.0f)
    {
        szybkosc.y = 0.0f;
        skokMozliwy = true;
    }
}