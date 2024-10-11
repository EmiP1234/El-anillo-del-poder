#include "Mago.h"
#include<iostream>

Mago::Mago()
{
    _textureMago.loadFromFile("Resourses/Mago_sprite.png");
    _spriteMago.setTexture (_textureMago);
    _spriteMago.setOrigin(_spriteMago.getGlobalBounds().width /2, _spriteMago.getGlobalBounds.height / 2);
}

void Mago::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_spriteMago, states);
}

void Mago::respawn();
{
    _spriteMago.setPosition(std::rand() % 700 + _spriteMago.getglobalBounds().width, std::rand()%500 + _spriteMago.getglobalBounds().height, 20)
}
