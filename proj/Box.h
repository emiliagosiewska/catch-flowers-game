#pragma once
#include "Flower.h"
#include <random>


class Box : public Flower
{
public:
	Box(int x, int y, sf::Texture& texture);
	~Box() { std::cout << "Derived Destructor"; };
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void setPos();
	void setFlower(int x, int y);
	void setTexture(sf::Texture& texture_figure);
	const int getCount();
	int giveCoord_y();
	sf::Vector2f getPosition();
	const int getValue();
	sf::Sprite getSprite();
	int GetRandom(int x, int y);

private:
	sf::Sprite s_box;
	 const int count = GetRandom(-30, 20);
	
};