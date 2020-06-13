#pragma once
#include "FlowerManager.h"
#include <fstream>
#include <set>
class Hud : public sf::Drawable
{
public:
	Hud();
	~Hud() {};
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void updateScore(int score, int health);
	void loadTexture();
	void changeBG();
	void changeBG_scoreboard();
	void changeBG_help();
	void changeBG_menu();
	void changeBG_ending();
	void changeBG_name();
	void setEnding(bool decision);
	void updateName(sf::String name);


private:

	bool name_phase = false;
	bool menu_phase = true;
	bool scoreboard_phase = false;
	bool ending = false;
	int health;
	int score;


	sf::Texture t_heart;
	sf::Texture t_backgroud;
	sf::Texture t_menu;
	sf::Texture t_help;
	sf::Texture t_ending;
	sf::Texture t_name;
	sf::Texture t_scoreboard;

	sf::Sprite s_background;
	sf::Sprite s_heart;
	sf::Sprite s_heart2;
	sf::Sprite s_heart3;

	sf::String name;
	sf::Font font;
};