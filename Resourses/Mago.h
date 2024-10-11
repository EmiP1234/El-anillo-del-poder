#pragma once
#ifndef MAGO_H_INCLUDED
#define MAGO_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <iostream>

class Mago : public sf::Drawable
{
    sf::Sprite _spriteMago;
    sf::Texture _textureMago;
public:
    Mago();
    void Update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void respawn();
    sf::FloatRect getBounds () const;
};
#endif // MAGO_H_INCLUDED
