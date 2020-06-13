
#pragma once
#include <iostream>
#include "FlowerManager.h"
#include <fstream>
#include <set>
#include <map>

#define RANKING_NUM_FIELDS 5
#define CENTER_OF_SCREEN 400

class FileManager : public sf::Drawable
{

public:
	FileManager();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	void setText();
	void loadFont();
	void sort();
	void fillScoreboardMap();

	struct compare {
		template<typename T>
		bool operator()(const T& left, const T& right)const
		{
			if (left.second != right.second)
				return left.second > right.second;
			return left.first > right.first;
		}
	};


private:
	std::map< std::string, int> _scoreboard;
	sf::Text tab_text[RANKING_NUM_FIELDS];
	sf::Font font;
};