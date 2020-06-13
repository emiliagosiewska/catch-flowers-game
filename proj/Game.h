#pragma once
#include "FlowerManager.h"
#include "Player.h"
#include "Hud.h"
#include <time.h>
#include <fstream>
#include"FileManager.h"

class Game
{
public:
	Game();
	~Game() { std::cout << "delete g1"; };
	bool menu(Hud& hud);
	bool main_loop();
	bool help_Phase(Hud& hud);
	bool scoreboard_phase(Hud& hud);
	void ending(Hud& hud);
	void update(FlowerManager& flower_manager, Player& player, float& timer, Hud& hud);
	const bool getInfo();
	bool loop();
	void setName(Player& player, Hud& hud);
	void saveToFile(Player& player, Hud& hud);

private:
	bool start, help, exit, mainloop = true, restart = true;
	sf::RenderWindow sf_game_window;
	int score;
	int heart = 3;
	bool menu_p;
	int change_delay = 59;
	int resolution_x = 800;
	int resolution_y = 800;
	int upper_bound_help = 465;
	int lower_bound_help = 405;
	int upper_bound_close = 600;
	int lower_bound_close = 555;
	int upper_bound_start = 320;
	int lower_bound_start = 265;
	int left_bound_menu = 280;
	int right_bound_menu = 460;
	int left_bound_in_help = 690;
	int right_bound_in_help = 760;
	int upper_bound_in_help = 222;
	int lower_bound_in_help = 165;
	int left_bound_after_loose = 120;
	int right_bound_after_loose = 495;
	int upper_bound_play_again = 455;
	int lower_bound_play_again = 370;
	int upper_bound_exit_play_again = 587;
	int lower_bound_exit_play_again = 513;
};