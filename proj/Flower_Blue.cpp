#include "Flower_Blue.h"

Flower_Blue::Flower_Blue(int x, int y, sf::Texture& texture)
{
	setFlower(x, y);
	this->s_Flower_blue.setTexture(texture);
}

void Flower_Blue::setFlower(int x, int y)
{
	this->s_Flower_blue.setPosition(static_cast<float>(x), (float)y);
}

const int Flower_Blue::getCount()
{
	return this->count;
}


int Flower_Blue::giveCoord_y()
{
	sf::Vector2f  tmp;
	tmp = this->s_Flower_blue.getPosition();
	return tmp.y;
}


void Flower_Blue::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->s_Flower_blue);
}


void Flower_Blue::setTexture(sf::Texture& texture_figure)
{
	this->s_Flower_blue.setTexture(texture_figure);
}

sf::Vector2f Flower_Blue::getPosition()
{
	return this->s_Flower_blue.getPosition();
}

void Flower_Blue::setPos()
{
	sf::Vector2f roler = getPosition();
	this->s_Flower_blue.setPosition(static_cast<int>(roler.x), static_cast<int>(roler.y + 4));
}

const int Flower_Blue::getValue()
{
	return this->count;
}


sf::Sprite Flower_Blue::getSprite()
{
	return this->s_Flower_blue;
}