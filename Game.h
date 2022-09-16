#pragma once

#include <iostream>
#include <ctime>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


#include "Player.h"
#include "Ball.h"

class Game {

private:
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	bool endGame;
	sf::Event sfmlEvent;

	Player player;

	std::vector<Ball> balls;
	float spawnTimerMax;
	float spawnTimer;
	unsigned int maxBalls;


	void initVariables();
	void initWindow();


public:
	// Constructor and Destructor
	Game();
	~Game();


	// Accessors

	// Modifiers

	// Functions
	const bool running();
	void pollEvents();

	void spawnBalls();
	void update();
	void render();
};

