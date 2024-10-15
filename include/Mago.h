#pragma once
#ifndef MAGO_H_INCLUDED
#define MAGO_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

class Mago : public sf::Drawable
{
private:
    sf::Sprite _spriteMago;
    sf::Texture _textureMago;
    bool STILL_LEFT;
    float speed;
    float _width_texture;
    float _xtexture=0;

public:
    Mago();
    void Update(const sf::Vector2f& heroPosition, sf::Time deltaTime);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override; // Usar override para mayor claridad
    void respawn();
    sf::FloatRect getBounds() const;
    sf::Sprite& getDraw();
    sf::Vector2f getPosition();
    void setPosition(float x, float y);
    int TiempoCambioDireccion;
    int CambioDireccion;

};

#endif // MAGO_H_INCLUDED
