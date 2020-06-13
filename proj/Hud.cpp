#include "Hud.h"

Hud::Hud()
{
	loadTexture();
}


void Hud::loadTexture()
{
	if (!t_heart.loadFromFile("img/heart.png"))
		throw std::runtime_error("Heart texture failed to load");
	else {
		s_heart.setTexture(t_heart);
		s_heart.setPosition(500, 0);
		s_heart2.setTexture(t_heart);
		s_heart2.setPosition(600, 0);
		s_heart3.setTexture(t_heart);
		s_heart3.setPosition(700, 0);
	}

	if (!t_menu.loadFromFile("img/menu.png"))throw std::runtime_error("Menu texture failed to load");
	else {
		s_background.setTexture(t_menu);
	}
	if (!t_backgroud.loadFromFile("img/bg.png"))
		throw std::runtime_error("Background texture failed to load");


	if (!t_help.loadFromFile("img/help.png"))
		throw std::runtime_error("Help texture failed to load");


	if (!t_ending.loadFromFile("img/ending.png"))
		throw std::runtime_error("Ending texture failed to load");

	if (!t_name.loadFromFile("img/name.png"))
		throw std::runtime_error("Name texture failed to load");

	if (!t_scoreboard.loadFromFile("img/scoreboard.png"))
		throw std::runtime_error("Scoreboard texture failed to load");

	if (!font.loadFromFile("arial.ttf"))
		throw std::runtime_error("Font failed to load");


}


void Hud::changeBG()
{
	this->menu_phase = false;
	this->name_phase = false;
	this->s_background.setTexture(t_backgroud);
}

void Hud::changeBG_scoreboard()
{
	this->scoreboard_phase = true;
	this->s_background.setTexture(t_scoreboard);
}

void Hud::changeBG_help()
{
	this->s_background.setTexture(t_help);
}
void Hud::changeBG_menu()
{
	this->s_background.setTexture(t_menu);
}

void Hud::changeBG_ending()
{
	this->scoreboard_phase = false;
	this->s_background.setTexture(t_ending);
}

void Hud::changeBG_name()
{
	name_phase = true;
	this->s_background.setTexture(t_name);
}


void Hud::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
	target.draw(s_background);

	if (menu_phase == false && name_phase == false && scoreboard_phase == false) {

		sf::Text text;
		sf::String s;
		s = std::to_string(score);
		text.setFont(font);
		text.setString(s);
		text.setCharacterSize(64);
		text.setFillColor(sf::Color::Black);
		if (!ending)
			text.setPosition(50, 0);
		else
			text.setPosition(550, 230);

		target.draw(text);


		int tmp_health = this->health;

		if (tmp_health > 0)
			target.draw(s_heart);
		if (tmp_health > 1)
			target.draw(s_heart2);
		if (tmp_health > 2)
			target.draw(s_heart3);


	}
	if (name_phase == true) {

		sf::Text player_text;
		player_text.setFillColor(sf::Color::Black);
		player_text.setFont(font);
		player_text.setPosition(211, 369);
		player_text.setCharacterSize(20);
		player_text.setString(name);
		target.draw(player_text);

	}
}


void Hud::updateScore(int score, int health)
{
	this->score = score;
	this->health = health;
}


void Hud::setEnding(bool decision)
{
	this->ending = decision;
}

void Hud::updateName(sf::String name)
{
	this->name = name;
}

