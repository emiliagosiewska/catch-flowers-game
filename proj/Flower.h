#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Flower: public sf::Drawable
{
public:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const=0;
	virtual void setFlower(int x, int y)=0;
	virtual const int getCount()=0;
	virtual void setTexture(sf::Texture& texture_figure)=0;
	virtual sf::Vector2f getPosition()=0;
	virtual void setPos()=0;
	virtual const int getValue() = 0;
	virtual sf::Sprite getSprite() = 0;
	virtual int giveCoord_y() = 0;

};

