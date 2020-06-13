#include "FileManager.h"


FileManager::FileManager()
{
	fillScoreboardMap();
	loadFont();
	setText();
	sort();
}

void FileManager::fillScoreboardMap()
{
	std::string key;
	int value;
	std::ifstream file("scoreboard.txt");
	if (file.is_open()) {
		std::string line;
		while (file >> key >> value) {

			_scoreboard[key] = value;
		}
		file.close();
	}
}


void FileManager::setText()
{
	for (int RANKING_INDEX = 0; RANKING_INDEX < RANKING_NUM_FIELDS; RANKING_INDEX++)
	{
		tab_text[RANKING_INDEX].setFillColor(sf::Color::Black);
		tab_text[RANKING_INDEX].setFont(font);
		tab_text[RANKING_INDEX].setPosition(CENTER_OF_SCREEN, 200 + RANKING_INDEX * 100);
		tab_text[RANKING_INDEX].setCharacterSize(30);

	}
}

void FileManager::sort()
{
	std::set<std::pair<std::string, int>, compare> set(_scoreboard.begin(), _scoreboard.end());
	int i = 0;
	for (auto elem : set)
	{
		if (i > 4)break;
		tab_text[i].setString(elem.first + " " + std::to_string(elem.second));
		++i;
	}


}

void FileManager::loadFont()
{
	if (!font.loadFromFile("arial.ttf"))
		throw std::runtime_error("Font failed to load");


}

void FileManager::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
	for (int i = 0; i < 5; i++)
	{
		target.draw(tab_text[i]);
	}
}
