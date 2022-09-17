#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

enum BallTypes { DEFAULT = 0, DAMAGING, HEALING, NROFTYPEPS };

class Ball {

private:
	sf::CircleShape shape;
	int type;


	void initShape(const sf::RenderWindow& window);


public:
	Ball(const sf::RenderWindow& window, int type);
	~Ball();

	// Accessor
	const sf::CircleShape getShape();
	const int& getType();


	void update();
	void render(sf::RenderTarget& target);
};

