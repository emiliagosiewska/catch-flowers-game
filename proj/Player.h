#pragma once
#include "FlowerManager.h"

class Player : public sf::Drawable
{
public:
	Player();
	~Player() {};
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void setTextureOfPlayer(sf::Texture& player_texture);
	void loadTexture();
	void setPos(sf::Vector2f pos);
	void move(sf::Keyboard::Key key);
	sf::Sprite getSprite();
	void setName(std::string name);
	std::string const getName();
private:
	std::string name;
	sf::Sprite s_player;
	sf::Texture t_player;
	int health = 3;
};