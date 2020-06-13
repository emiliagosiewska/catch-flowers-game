#include "Rotten.h"

Rotten::Rotten(int x, int y, sf::Texture& texture)
{
	setFlower(x, y);
	this->s_rotten.setTexture(texture);
}

void Rotten::setFlower(int x, int y)
{
	this->s_rotten.setPosition(x, y);
	
}

const int Rotten::getCount()
{
	return 0;
}

int Rotten::giveCoord_y()
{
	sf::Vector2f  tmp;
	tmp = this->s_rotten.getPosition();
	return tmp.y;
}

void Rotten::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->s_rotten);
}

void Rotten::setTexture(sf::Texture& texture_figure)
{
	this->s_rotten.setTexture(texture_figure);
}

sf::Vector2f Rotten::getPosition()
{
	return this->s_rotten.getPosition();
}

void Rotten::setPos()
{
	sf::Vector2f roler = getPosition();
	this->s_rotten.setPosition(static_cast<int>(roler.x), static_cast<int>(roler.y + 4));
}

const int Rotten::getValue()
{
	return this->count;
}

sf::Sprite Rotten::getSprite()
{
	return this->s_rotten;
}