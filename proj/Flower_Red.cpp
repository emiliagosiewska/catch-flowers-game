#include "Flower_Red.h"

Flower_Red::Flower_Red(int x, int y, sf::Texture& texture)
{
	setFlower(x, y);
	this->s_Flower_red.setTexture(texture);
}

void Flower_Red::setFlower(int x, int y)
{
	this->s_Flower_red.setPosition(x, y);
}

const int Flower_Red::getCount()
{
	return this->count;
}

int Flower_Red::giveCoord_y()
{
	sf::Vector2f  tmp;
	tmp = this->s_Flower_red.getPosition();
	return tmp.y;
}

void Flower_Red::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->s_Flower_red);
}

void Flower_Red::setTexture(sf::Texture& texture_figure)
{
	this->s_Flower_red.setTexture(texture_figure);
}

sf::Vector2f Flower_Red::getPosition()
{
	return this->s_Flower_red.getPosition();
}

void Flower_Red::setPos()
{
	sf::Vector2f roler = getPosition();
	this->s_Flower_red.setPosition(static_cast<int>(roler.x), static_cast<int>(roler.y + 4));
}

const int Flower_Red::getValue()
{
	return this->count;
}

sf::Sprite Flower_Red::getSprite()
{
	return this->s_Flower_red;
}