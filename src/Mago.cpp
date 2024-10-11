#include "Mago.h"

Mago::Mago()
{
    _textureMago.loadFromFile("Resourses/Mago_sprite.png");
    _spriteMago.setTexture (_textureMago);
    _spriteMago.setPosition(12550,535);
    _spriteMago.setTextureRect({11,153,56,100});
    _spriteMago.setOrigin(_spriteMago.getGlobalBounds().width /2, _spriteMago.getGlobalBounds().height / 2);
    STILL_LEFT=true;
}

void Mago::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_spriteMago, states);
}


sf::FloatRect Mago::getBounds() const
{
    return _spriteMago.getGlobalBounds();
}

sf::Sprite& Mago::getDraw()
{
    return _spriteMago;
}
sf::Vector2f Mago::getPosition()
{
    return _spriteMago.getPosition();
}

void Mago::Update(const sf::Vector2f& heroPosition)
{
    // Comprueba si el héroe está a la izquierda o a la derecha del mago
    if (heroPosition.x < _spriteMago.getPosition().x)
    {
        // Héroe a la izquierda
        if (STILL_LEFT) // Si el mago está mirando a la derecha
        {
            _spriteMago.setScale(sf::Vector2f(-1.5, 1.5)); // Cambia a mirar a la izquierda
            STILL_LEFT = false;
        } // Mueve a la izquierda
    }
    else
    {
        // Héroe a la derecha
        if (!STILL_LEFT) // Si el mago está mirando a la izquierda
        {
            _spriteMago.setScale(sf::Vector2f(1.5, 1.5)); // Cambia a mirar a la derecha
            STILL_LEFT = true;
        } // Mueve a la derecha
    }
}
