#pragma once
#include <vector>
#include <random>
#include <iostream>
#include "Flower.h"
#include "Flower_Red.h"
#include "Flower_Blue.h"
#include "Rotten.h"
#include "Box.h"
#include "ExtraHeart.h"

class FlowerManager:	public sf::Drawable
{
public:
	FlowerManager();
	~FlowerManager();
	void generateFlowerPosition();
	void draw(sf::RenderTarget& obcject, sf::RenderStates states)const override;
	/*void setTexture();*/
	void getTexture(sf::Texture& flower_texture_red, sf::Texture flower_texture_blue, sf::Texture flower_texture_rotten, sf::Texture texture_box, sf::Texture texture_extra_heart);
	void addHeart(sf::Sprite& p_sprite, int& serduszko);
	int GetRandom(int x, int y);
	void loadTexture();
	void getPositionOfAllFlowers();
	void checkAxis_y();
	void dropFlower();
	void checkCol(sf::Sprite& sprite, int& score);
	int subtractHeart();
	
private:
	std::vector<std::shared_ptr<Flower>> v_flowers; 
	std::vector<sf::Vector2i> v_coords;

	sf::Texture t_red_flower;
	sf::Texture t_blue_flower;
	sf::Texture t_rotten_flower;
	sf::Texture t_box;
	sf::Texture t_extra_heart;
};