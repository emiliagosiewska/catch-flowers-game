#include "Box.h"

Box::Box(int x, int y, sf::Texture& texture)
{
	setFlower(x, y);
	this->s_box.setTexture(texture);
}

void Box::setFlower(int x, int y)
{
	this->s_box.setPosition(x, y);
}

const int Box::getCount()
{
	return this->count;
}

int Box::giveCoord_y()
{
	sf::Vector2f  tmp;
	tmp = this->s_box.getPosition();
	return tmp.y;
}

void Box::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->s_box);
}

void Box::setTexture(sf::Texture& texture_figure)
{
	this->s_box.setTexture(texture_figure);
}

sf::Vector2f Box::getPosition()
{
	return this->s_box.getPosition();
}

void Box::setPos()
{
	sf::Vector2f roler = getPosition();
	this->s_box.setPosition(static_cast<int>(roler.x), static_cast<int>(roler.y + 4));
}

const int Box::getValue()
{
	static const int count = GetRandom(-30, 20);
	return this->count;
}

sf::Sprite Box::getSprite()
{
	return this->s_box;
}

int Box::GetRandom(int x, int y)	
{
	static std::default_random_engine generator(std::clock());
	std::uniform_int_distribution<int> random_number(x, y);
	return random_number(generator);
}