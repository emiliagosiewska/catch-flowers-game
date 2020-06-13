#include "Player.h"


Player::Player()
{
	loadTexture();
	setTextureOfPlayer(t_player);
	s_player.setOrigin(100, 200);
	s_player.setPosition(400, 800);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
	target.draw(this->s_player);
}


void Player::setTextureOfPlayer(sf::Texture& player_texture)
{
	this->s_player.setTexture(player_texture);
}

void Player::loadTexture()
{
	if (!t_player.loadFromFile("img/player_v2.png"))
		throw std::runtime_error("Player texture failed!");
}
void Player::setPos(sf::Vector2f pos)
{
	this->s_player.setPosition(pos.x, pos.y);
}

sf::Sprite Player::getSprite()
{
	return this->s_player;
}

void Player::setName(std::string name)
{
	this->name = name;
}

std::string const Player::getName()
{
	return this->name;
}

void Player::move(sf::Keyboard::Key key)
{
	sf::Vector2f player_pos = this->s_player.getPosition();
	if (key == sf::Keyboard::Left)
	{
		if (player_pos.x > 80) {
			player_pos.x -= 10;
		}
		s_player.setPosition(player_pos);
	}
	if (key == sf::Keyboard::Right)
	{
		if (player_pos.x <= 790) {
			player_pos.x += 10;
		}
		s_player.setPosition(player_pos);
	}
}