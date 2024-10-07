#include "Hero_1.h"


Hero_1::Hero_1()
{
    _texture_hero.loadFromFile("Resourses/Legolas_sprite.png");
    _sprite_hero.setTexture(_texture_hero);
    _sprite_hero.setPosition(250,-465); // posicion inicial
    //_sprite_hero.setPosition(0,0);
    //_sprite_hero.setOrigin(_width_texture/2, 0.f);
    _sprite_hero.setScale(sf::Vector2f(1.5,1.5));
    _state=STATES::STILL_RIGHT; //estado inicial
    _jump_force=0; //Fuerza de salto inicial
}

/*Hero_1::~Hero_1()
{
    //dtor
}*/

void Hero_1::update()
{
    switch (_state)
    {
    case STILL_RIGHT:
        _width_texture=44;
        _sprite_hero.setScale(sf::Vector2f(1.5,1.5));
        _sprite_hero.setTextureRect(sf::IntRect(8, 16, _width_texture, 86));//x,y,w,h

        break;
    case STILL_LEFT:
        _width_texture=44;
        _sprite_hero.setScale(sf::Vector2f(-1.5,1.5));
        _sprite_hero.setTextureRect(sf::IntRect(8, 16, _width_texture, 86));
        break;
    case WALKING_RIGHT:
        _width_texture=70.58;
        _xtexture=(int)_sprite_hero.getPosition().x/12 % 10;
        _xtexture=_xtexture*70.58;
        _sprite_hero.setScale(sf::Vector2f(1.5,1.5));
        _sprite_hero.setTextureRect(sf::IntRect(_xtexture,782,_width_texture,88));
        _sprite_hero.move(4,0);
        _state=STATES::STILL_RIGHT;

        break;
    case WALKING_LEFT:
        _width_texture=70.58;
        _xtexture=(int)_sprite_hero.getPosition().x/12 % 10;
        _xtexture=_xtexture*70.58;
        _sprite_hero.setScale(sf::Vector2f(-1.5,1.5));
        _sprite_hero.setTextureRect(sf::IntRect(_xtexture,782,_width_texture,88));
        _sprite_hero.move(-4,0);
        _state=STATES::STILL_LEFT;

        break;
    case JUMPING:


        break;
    case WALKING_RIGHT_JUMPING:
        _width_texture=69;
        _xtexture=(int)_sprite_hero.getPosition().x/4 % 2;
        _xtexture=_xtexture*69;
        _sprite_hero.setScale(sf::Vector2f(1.5,1.5));
        _sprite_hero.setTextureRect(sf::IntRect(_xtexture,109,_width_texture,88));
        _sprite_hero.move(4,0);
        _jump_force = 10;
        _sprite_hero.move(0,-_jump_force);
        _state=STATES::STILL_RIGHT;



        break;
    case WALKING_LEFT_JUMPING:
        _width_texture=69;
        _xtexture=(int)_sprite_hero.getPosition().x/4 % 2;
        _xtexture=_xtexture*69;
        _sprite_hero.setScale(sf::Vector2f(-1.5,1.5));
        _sprite_hero.setTextureRect(sf::IntRect(_xtexture,109,_width_texture,88));
        _sprite_hero.move(-4,0);
        _jump_force = 10;
        _sprite_hero.move(0,-_jump_force);
        _state=STATES::STILL_LEFT   ;

        break;
    case SHOOTING:


        break;
    case DEATH:


        break;
    }
    _jump_force-=5; //fuerza de gravedad. Se ejerse siempre
    _sprite_hero.move(0,-_jump_force);
}

void Hero_1::mobility()
{
    if(_state==STATES::STILL_RIGHT||_state==STATES::STILL_LEFT)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            _state=STATES::WALKING_RIGHT;
           // std::cout<<_sprite_hero.getPosition().x<<std::endl;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            _state=STATES::WALKING_LEFT;
            //std::cout<<_sprite_hero.getPosition().x<<std::endl;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            _state=STATES::WALKING_RIGHT_JUMPING;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            _state=STATES::WALKING_LEFT_JUMPING;
        }
        /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            _state=STATES::WALKING_RIGHT_JUMPING;
        }*/


    }


    if(_sprite_hero.getPosition().x<100)
    {
        _sprite_hero.setPosition(100,_sprite_hero.getPosition().y);
    }
    if(_sprite_hero.getPosition().y<0)
    {
        _sprite_hero.setPosition(_sprite_hero.getPosition().x,0);
    }

}

sf::Sprite& Hero_1::getDraw()
{
    return _sprite_hero;
}

void Hero_1::floor(float x, float y)
{
    if(_state==STATES::STILL_RIGHT||_state==STATES::STILL_LEFT)
    {
        _jump_force=0;
        _sprite_hero.setPosition(x,y);
    }

}

sf::Vector2f Hero_1::getPosition()
{
    return _sprite_hero.getPosition();
}

void Hero_1::setPosition(float x, float y)
{
    _sprite_hero.setPosition(x,y);
}

