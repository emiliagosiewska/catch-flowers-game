#pragma once
#include "Flower.h"


class Flower_Red:	public Flower
{
public:
	Flower_Red(int x, int y, sf::Texture& texture);
	~Flower_Red() {std::cout << "Derived Destructor";};
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void setTexture(sf::Texture& texture_figure);
	void setFlower(int x, int y);
	void setPos();
	const int getCount();
	int giveCoord_y();
	sf::Vector2f getPosition();
	const int getValue();
	sf::Sprite getSprite();
private:
	sf::Sprite s_Flower_red;
	static const int count = 10;
	
};

