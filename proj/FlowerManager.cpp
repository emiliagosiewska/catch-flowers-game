#include "FlowerManager.h"

FlowerManager::FlowerManager()
{
	loadTexture();
	this->generateFlowerPosition();
	std::cout << "done";
}

void FlowerManager::loadTexture()
{
	if (!t_red_flower.loadFromFile("img/red_flower.png"))throw std::runtime_error("Red flower failed to load");
	if (!t_blue_flower.loadFromFile("img/blue_flower.png"))throw std::runtime_error("Blue flower failed to load");
	if (!t_rotten_flower.loadFromFile("img/rotten_flower.png"))throw std::runtime_error("Rotten flower failed to load");
	if (!t_box.loadFromFile("img/box.png"))throw std::runtime_error("Box failed to load");
	if (!t_extra_heart.loadFromFile("img/extra_heart.png"))throw std::runtime_error("Extra heart failed to load");
}

int FlowerManager::GetRandom(int x, int y)	// change to random device
{
	static std::default_random_engine generator(std::clock());
	std::uniform_int_distribution<int> random_number(x, y);	
	return random_number(generator);
}

void FlowerManager::generateFlowerPosition()
{
	sf::Vector2i coords;
	coords.y = 0;
	for (int i = 0; i < 3; ++i)
	{
		int flower_color = GetRandom(0, 4);//decides wheter it is blue or red flower
		
		coords.x = GetRandom(0, 16) * 50;
		if (flower_color == 0) {
			v_flowers.push_back(std::make_unique<Flower_Red>(static_cast<int>(coords.x), 0, t_red_flower));	
			v_coords.push_back(coords);	
		}
		else if (flower_color == 1) {
			v_flowers.push_back(std::make_unique<Flower_Blue>(static_cast<int>(coords.x), 0, t_blue_flower));
			v_coords.push_back(coords);
		}
		else if (flower_color == 2) {
			v_flowers.push_back(std::make_unique<Rotten>(static_cast<int>(coords.x), 0, t_rotten_flower));
			v_coords.push_back(coords);
		}

		else if (flower_color == 3) {
			v_flowers.push_back(std::make_unique<Box>(static_cast<int>(coords.x), 0, t_box));
			v_coords.push_back(coords);
		}

		else if (flower_color == 4) {
			v_flowers.push_back(std::make_unique<ExtraHeart>(static_cast<int>(coords.x), 0, t_extra_heart));
			v_coords.push_back(coords);
		}
		else throw std::invalid_argument("Error within creating flowers, |generateFlowerPosition|"); 
	}
	
}

void FlowerManager::draw(sf::RenderTarget& object, sf::RenderStates states)const 
{
	for (auto& sprite : v_flowers)
		object.draw(*sprite, states);
}




void FlowerManager::getTexture(sf::Texture& flower_texture_red, sf::Texture flower_texture_blue, sf::Texture flower_texture_rotten,  sf::Texture texture_box, sf::Texture texture_extra_heart)
{
	this->t_red_flower = flower_texture_red;
	this->t_blue_flower = flower_texture_blue;
	this->t_rotten_flower = flower_texture_rotten;
	this->t_box = texture_box;
	this->t_extra_heart = texture_extra_heart;
}

void FlowerManager::getPositionOfAllFlowers()
{
	sf::Vector2f coords;
	sf::Vector2i coords_i;

	v_coords.clear();
	for (auto& sprite: v_flowers)
	{
		coords = sprite->getPosition();
		coords_i.x = (int)coords.x;
		coords_i.y = (int)coords.y;
		v_coords.push_back(coords_i);
	}
}


void FlowerManager::dropFlower()
{
	for (auto& sprite : v_flowers)
		sprite->setPos();
}

void FlowerManager::checkAxis_y()
{
	sf::Vector2f tmp;
	auto toErase = std::remove_if(v_flowers.begin(), v_flowers.end(),
		[&tmp](std::shared_ptr<Flower> flower){
		tmp = flower->getPosition();
		 
		return tmp.y >= 800;
	});

	v_flowers.erase(toErase, v_flowers.end());
}


void FlowerManager::checkCol(sf::Sprite& p_sprite, int& score)
{
	auto toErase = std::remove_if(v_flowers.begin(), v_flowers.end(),
		[&p_sprite, &score](std::shared_ptr<Flower>flower) {
		bool tmp = p_sprite.getGlobalBounds().intersects((flower->getSprite()).getGlobalBounds());
		if (tmp)score+=flower->getValue();
		return tmp == true;
	});

	v_flowers.erase(toErase, v_flowers.end());

	std::cout << score << std::endl;
}

void FlowerManager::addHeart(sf::Sprite& p_sprite, int& serduszko)
{

	int heart = serduszko;
	for (auto& base_ptr : v_flowers)
	{

			bool tmp = p_sprite.getGlobalBounds().intersects((base_ptr->getSprite()).getGlobalBounds());
			if (tmp)
			{

				auto down_cast_extra_heart = std::dynamic_pointer_cast<ExtraHeart>(base_ptr);
				if (down_cast_extra_heart != nullptr)
				{
					heart += 1;
				}
			}
		
			else continue;
	}
	if (heart > 3)
		heart = 3;
	serduszko = heart;
	
}

int FlowerManager::subtractHeart()
{
	int count = 0;
	getPositionOfAllFlowers();
	int  tmp;
	
	
		for (auto& base_ptr : v_flowers)
		{
			auto down_cast_rotten = std::dynamic_pointer_cast<Rotten>(base_ptr);
			auto down_cast_box = std::dynamic_pointer_cast<Box>(base_ptr);
			auto down_cast_extra_heart = std::dynamic_pointer_cast<ExtraHeart>(base_ptr);
			tmp = base_ptr->giveCoord_y();

				if (tmp >= 800)
				{
					if ((down_cast_rotten == nullptr)&&(down_cast_box==nullptr)&& (down_cast_extra_heart==nullptr))
					{
						count++;
					}

				}
		}
		checkAxis_y();
		return count;


}

FlowerManager::~FlowerManager()
{
	for (size_t i = 0; i < v_flowers.size(); ++i)
	{
		v_flowers.erase(v_flowers.begin() + i);
		--i;
	}
	v_flowers.clear();
	v_coords.clear();
	
}