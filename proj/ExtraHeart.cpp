#include "ExtraHeart.h"

ExtraHeart::ExtraHeart(int x, int y, sf::Texture& texture)
{
	setFlower(x, y);
	this->s_Extra_heart.setTexture(texture);
}

void ExtraHeart::setFlower(int x, int y)
{
	this->s_Extra_heart.setPosition(x, y);

}

const int ExtraHeart::getCount()
{
	return 0;
}

int ExtraHeart::giveCoord_y()
{
	sf::Vector2f  tmp;
	tmp = this->s_Extra_heart.getPosition();
	return tmp.y;
}

void ExtraHeart::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->s_Extra_heart);
}

void ExtraHeart::setTexture(sf::Texture& texture_figure)
{
	this->s_Extra_heart.setTexture(texture_figure);
}

sf::Vector2f ExtraHeart::getPosition()
{
	return this->s_Extra_heart.getPosition();
}

void ExtraHeart::setPos()
{
	sf::Vector2f roler = getPosition();
	this->s_Extra_heart.setPosition(static_cast<int>(roler.x), static_cast<int>(roler.y + 4));
}

const int ExtraHeart::getValue()
{
	return this->count;
}

sf::Sprite ExtraHeart::getSprite()
{
	return this->s_Extra_heart;
}