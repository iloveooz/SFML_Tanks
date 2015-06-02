#pragma once
#include <SFML/Graphics.hpp>


class Map
{
public:
	Map(sf::Texture &texture);
	~Map();

	void update(float deltaTime);
	void draw(sf::RenderWindow &window);
private:
	sf::Sprite map;
	sf::RectangleShape lines[3];
};

