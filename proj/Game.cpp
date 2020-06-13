#include "Game.h"

Game::Game() :
	sf_game_window(sf::VideoMode(800, 800), "Fcatch"),
	start(false),
	help(false),
	exit(false)
{
	std::cout << "Game";
}


const bool Game::getInfo()
{
	return this->restart;
}

bool Game::loop()
{
	while (restart)
	{
		main_loop();
	}
	return true;
}

bool Game::menu(Hud& hud)
{
	while (sf_game_window.isOpen())
	{

		sf::Event event;
		while (sf_game_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				sf_game_window.close();
				restart = false;
			}

			if (event.type == sf::Event::MouseButtonPressed)//tmp fun to help debug
			{
				sf::Vector2i soure_vector2i = sf::Mouse::getPosition(sf_game_window);
				std::cout << "\n" << soure_vector2i.x << " " << soure_vector2i.y << "     x,y of source ";
				if (soure_vector2i.x >= left_bound_menu && soure_vector2i.x <= right_bound_menu)
				{

					if (soure_vector2i.y >= lower_bound_start && soure_vector2i.y <= upper_bound_start) {

						hud.changeBG();
						return true;
					}
					if (soure_vector2i.y >= lower_bound_help && soure_vector2i.y <= upper_bound_help)
					{
						hud.changeBG_help();
						help = help_Phase(hud);
					}
					if (soure_vector2i.y >= lower_bound_close && soure_vector2i.y <= upper_bound_close)
					{
						sf_game_window.close();
						restart = false;
					}
				}
			}



		}


		sf_game_window.clear(sf::Color::White);
		sf_game_window.draw(hud);
		sf_game_window.display();

	}
	return true;
}


bool Game::help_Phase(Hud& hud)
{
	start = false;

	while (sf_game_window.isOpen())
	{

		sf::Event event;
		while (sf_game_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				sf_game_window.close();
				restart = false;
			}


			if (event.type == sf::Event::MouseButtonPressed)//tmp fun to help debug
			{
				sf::Vector2i soure_vector2i = sf::Mouse::getPosition(sf_game_window);
				std::cout << "\n" << soure_vector2i.x << " " << soure_vector2i.y << "     x,y of source ";

				if (soure_vector2i.x >= left_bound_in_help && soure_vector2i.x <= right_bound_in_help && soure_vector2i.y >= lower_bound_in_help && soure_vector2i.y <= upper_bound_in_help)
				{
					hud.changeBG_menu();
					start = true;
					break;
				}
			}
		}


		if (start == true) break;
		sf_game_window.clear(sf::Color::White);
		sf_game_window.draw(hud);
		sf_game_window.display();

	}
	return true;
}

bool Game::scoreboard_phase(Hud& hud)
{
	exit = false;
	FileManager fm;
	hud.changeBG_scoreboard();

	while (sf_game_window.isOpen())
	{

		sf::Event event;
		while (sf_game_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				sf_game_window.close();
				restart = false;
			}


			if (event.type == sf::Event::KeyPressed)//tmp fun to help debug
			{
				if (event.key.code == sf::Keyboard::Enter)
				{
					exit = true;

				}
			}
		}


		if (exit == true) break;
		sf_game_window.clear(sf::Color::White);
		sf_game_window.draw(hud);
		sf_game_window.draw(fm);
		sf_game_window.display();

	}
	return true;
}

bool Game::main_loop()
{
	Hud hud;

	FlowerManager flower_manager;
	Player player;

	menu_p = menu(hud);
	setName(player, hud);


	flower_manager.getPositionOfAllFlowers();

	float timer = 0, timer2 = 0, delay = 0.09;

	sf::Clock clock;

	while (sf_game_window.isOpen())
	{

		float time = clock.getElapsedTime().asSeconds();
		clock.restart();

		timer += time;
		timer2 += time;


		sf::Event event;
		while (sf_game_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				restart = false;
				sf_game_window.close();
				flower_manager.~FlowerManager();
				mainloop = false;
				break;
			}
			if (event.type == sf::Event::KeyPressed)
			{
				player.move(event.key.code);
			}

			if (event.type == sf::Event::MouseButtonPressed)//tmp fun to help debug
			{
				sf::Vector2i soure_vector2i = sf::Mouse::getPosition(sf_game_window);
				std::cout << "\n" << soure_vector2i.x << " " << soure_vector2i.y << "     x,y of source ";
			}
		}
		if (mainloop == false)break;

		if (timer2 > delay* change_delay) //generates new flowers
		{
			flower_manager.generateFlowerPosition();
			flower_manager.getPositionOfAllFlowers();
			timer2 = 0;
		}



		if (timer > delay) //updates score
		{
			update(flower_manager, player, timer, hud);
			timer = 0;
		}

		if ((heart < 1) || (score < 0)) {//to develop

			saveToFile(player, hud);
			scoreboard_phase(hud);
			ending(hud);
			score = 0;
			heart = 3;
			break;
		}

		sf_game_window.clear(sf::Color::White);
		sf_game_window.draw(hud);
		sf_game_window.draw(flower_manager);
		sf_game_window.draw(player);
		sf_game_window.display();


	}

	std::cout << "Game over";
	return true;
}


void Game::update(FlowerManager& flower_manager, Player& player, float& timer, Hud& hud)
{
	flower_manager.dropFlower();
	flower_manager.getPositionOfAllFlowers();
	sf::Sprite s = player.getSprite();
	heart = heart - flower_manager.subtractHeart();
	flower_manager.addHeart(s, heart);
	flower_manager.checkCol(s, score);
	std::cout << "Life left: " << heart << std::endl;
	hud.updateScore(this->score, this->heart);

	timer = 0;
}

void Game::ending(Hud& hud)
{
	exit = false;
	hud.changeBG_ending();
	hud.setEnding(true);
	while (sf_game_window.isOpen())
	{

		sf::Event event;
		while (sf_game_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				sf_game_window.close();
				restart = false;
			}


			if (event.type == sf::Event::MouseButtonPressed)//tmp fun to help debug
			{
				sf::Vector2i soure_vector2i = sf::Mouse::getPosition(sf_game_window);
				std::cout << "\n" << soure_vector2i.x << " " << soure_vector2i.y << "     x,y of source ";


				if (soure_vector2i.x >= left_bound_after_loose && soure_vector2i.x <= right_bound_after_loose)
				{
					if (soure_vector2i.y >= lower_bound_play_again && soure_vector2i.y <= upper_bound_play_again) {
						hud.changeBG_menu();
						hud.setEnding(false);
						exit = true;

						break;
					}
					if (soure_vector2i.y >= lower_bound_exit_play_again && soure_vector2i.y <= upper_bound_exit_play_again)
					{
						sf_game_window.close();
						restart = false;

					}
				}



			}
		}

		if (exit == true) break;
		sf_game_window.clear(sf::Color::White);
		sf_game_window.draw(hud);
		sf_game_window.display();

	}

}

void Game::setName(Player& player, Hud& hud)
{
	exit = false;
	sf::String player_input;
	std::string tmp;
	hud.changeBG_name();

	while (sf_game_window.isOpen())
	{

		sf::Event event;
		while (sf_game_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				sf_game_window.close();
				restart = false;
			}


			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode == '\b' && !player_input.isEmpty())
				{
					tmp = player_input;
					tmp.pop_back();
					player_input = tmp;
					hud.updateName(player_input);
				}
				else if (event.text.unicode < 128 && event.text.unicode != '\b') {
					player_input += event.text.unicode;
					hud.updateName(player_input);
				}
			}



			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Enter && !player_input.isEmpty())
				{
					player.setName(player_input);
					hud.changeBG();
					exit = true;

				}
			}



		}


		if (exit)break;
		sf_game_window.clear(sf::Color::White);
		sf_game_window.draw(hud);
		sf_game_window.display();

	}

}

void Game::saveToFile(Player& player, Hud& hud)
{
	std::ofstream file;
	std::string name = player.getName();

	file.open("scoreboard.txt", std::fstream::app);
	file << name << " " << score;
	file.clear();
	file.close();
}


