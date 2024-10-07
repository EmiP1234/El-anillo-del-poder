#ifndef HERO_1_H
#define HERO_1_H
#include <SFML/Graphics.hpp>

#include <iostream>

class Hero_1
{
public:
    Hero_1();
    //virtual ~Hero_1();
    enum STATES
    {
        STILL_RIGHT,
        STILL_LEFT,
        WALKING_RIGHT,
        WALKING_LEFT,
        JUMPING,
        WALKING_RIGHT_JUMPING,
        WALKING_LEFT_JUMPING,
        SHOOTING,
        DEATH,

    };
    void update();
    void mobility();
    sf::Sprite& getDraw();
    void floor(float x, float y);
    sf::Vector2f getPosition();
    void setPosition(float x, float y);



protected:

private:
    sf::Sprite _sprite_hero;
    sf::Texture _texture_hero;
    STATES _state;
    float _jump_force;
    int _xtexture=0;
    int _width_texture;

};

#endif // HERO_1_H
