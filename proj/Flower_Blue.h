#pragma once
#include "Flower.h"


class Flower_Blue:	public Flower
{
public:
	Flower_Blue(int x, int y, sf::Texture& texture);
	~Flower_Blue() { std::cout << "Derived Destructor"; };
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void setPos();
	void setFlower(int x, int y) ;
	void setTexture(sf::Texture& texture_figure);
	const int getCount();
	int giveCoord_y();
	sf::Vector2f getPosition();
	const int getValue();
	sf::Sprite getSprite();

private:
	sf::Sprite s_Flower_blue;
	static const int count = 5;
	
};