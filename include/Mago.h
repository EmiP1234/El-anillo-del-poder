#pragma once
#ifndef MAGO_H_INCLUDED
#define MAGO_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <iostream>

class Mago : public sf::Drawable
{
    sf::Sprite _spriteMago;
    sf::Texture _textureMago;
    int _width_texture;

public:
    Mago();
    void Update(const sf::Vector2f& heroPosition);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void respawn();
    sf::FloatRect getBounds () const;
    sf::Sprite& getDraw();
    sf::Vector2f getPosition();
    void setPosition(float x, float y);
    bool STILL_LEFT;
};
#endif // MAGO_H_INCLUDED
