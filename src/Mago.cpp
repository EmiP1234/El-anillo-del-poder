#include "Mago.h"

Mago::Mago()
{
    speed = 2.0f;
    _textureMago.loadFromFile("Resourses/Mago_spritever2.png");
    _spriteMago.setTexture (_textureMago);
    _spriteMago.setPosition(250,535);
    _spriteMago.setTextureRect({14,154,60,104});
    _spriteMago.setOrigin(_spriteMago.getGlobalBounds().width /2, _spriteMago.getGlobalBounds().height / 2);
    STILL_LEFT=true;


    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    TiempoCambioDireccion = 0;
    CambioDireccion = 800;
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

void Mago::Update(const sf::Vector2f& heroPosition, sf::Time deltaTime)
{

    //el mago no sale de la pantalla
    if (_spriteMago.getPosition().x<150){
        _spriteMago.setPosition (150,getPosition().y);

    }
    if (_spriteMago.getPosition().x>12250){
        _spriteMago.setPosition (12250,getPosition().y);

    }

    //volteo de personaje
    TiempoCambioDireccion += deltaTime.asMilliseconds();

    _width_texture=70;
    _xtexture=(int)_spriteMago.getPosition().x/8 % 6;
    _xtexture=_xtexture*75;
    _spriteMago.setTextureRect(sf::IntRect(_xtexture,154,_width_texture,104));

    // Cambia de direcci�n aleatoriamente
    if (TiempoCambioDireccion >= CambioDireccion)
    {
        // Decide si cambiar de direcci�n
        if (std::rand() % 2 == 0)
        {
            // Cambia la direcci�n
            speed = -speed; // Invierte la direcci�n
            STILL_LEFT = !STILL_LEFT; // Cambia el estado de direcci�n
            // Cambia la escala del sprite
            _spriteMago.setScale(STILL_LEFT ? sf::Vector2f(-1.5, 1.5) : sf::Vector2f(1.5, 1.5));
        }
        TiempoCambioDireccion = 0; // Reinicia el tiempo
    }


    // Comprueba si el h�roe est� a la izquierda o a la derecha del mago
    if (heroPosition.x < _spriteMago.getPosition().x)
    {
        // H�roe a la izquierda
        if (STILL_LEFT)
        {
            _spriteMago.move(-speed, 0);
        }
        else
        {
            // Si el mago est� mirando a la derecha, mueve hacia la izquierda
            _spriteMago.setScale(sf::Vector2f(-1.5, 1.5));
            STILL_LEFT = false;
            _spriteMago.move(-speed, 0);
        }
    }
    else
    {
        // H�roe a la derecha
        if (!STILL_LEFT)
        {
            _spriteMago.move(speed, 0);
        }
        else
        {
            // Si el mago est� mirando a la izquierda, mueve hacia la derecha
            _spriteMago.setScale(sf::Vector2f(1.5, 1.5));
            STILL_LEFT = true;
            _spriteMago.move(speed, 0);
        }
    }
}


