#pragma once

#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>

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

	int points;

	sf::Font font;
	sf::Text guiText;
	sf::Text endGameText;

	std::vector<Ball> balls;
	float spawnTimerMax;
	float spawnTimer;
	unsigned int maxBalls;


	void initVariables();
	void initWindow();
	void initFonts();
	void initText();


public:
	// Constructor and Destructor
	Game();
	~Game();


	// Accessors
	const bool& getEndGame();

	// Modifiers

	// Functions
	const bool running();
	void pollEvents();

	void spawnBalls();
	const int randBallType();
	void updatePlayer();
	void updateCollision();
	void updateGui();
	void update();

	void renderGui(sf::RenderTarget* target);
	void render();
};

