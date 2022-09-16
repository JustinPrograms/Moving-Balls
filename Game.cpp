#include "Game.h"


void Game::initVariables() {
	this->endGame = false;
	this->spawnTimerMax = 10.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxBalls = 10;
}

void Game::initWindow() {
	this->videoMode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(this->videoMode, "Game 2", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

// Constructor and Destructor
Game::Game() {
	
	this->initVariables();
	this->initWindow();

}

Game::~Game() {
	delete this->window;
}

const bool Game::running() {
	return this->window->isOpen();
}

void Game::pollEvents() {
	while (this->window->pollEvent(this->sfmlEvent)) {
		
		switch (this->sfmlEvent.type) {
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}

	}
}

void Game::spawnBalls() {
	
	// Timer
	if (this->spawnTimer < this->spawnTimerMax)
		this->spawnTimer += 1.f;

	else {
		if (this->balls.size() < this->maxBalls) {

			this->balls.push_back(Ball(*this->window));
			this->spawnTimer = 0.f;
		}

	}
}

void Game::update() {
	this->pollEvents();
	
	this->spawnBalls();
	this->player.update(this->window);
}

void Game::render() {
	this->window->clear();

	// Rendering
	this->player.render(this->window);

	for (auto i : this->balls) {
		i.render(*this->window);
	}

	this->window->display();
}
