#include "Game.h"


void Game::initVariables() {
	this->endGame = false;
	this->spawnTimerMax = 10.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxBalls = 10;
	this->points = 0;
}

void Game::initWindow() {
	this->videoMode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(this->videoMode, "Game 2", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

void Game::initFonts() {
	if (!this->font.loadFromFile("Fonts/FunHouse.ttf")) {
		std::cout << "ERROR::GAME::INNITFONTS::Failed to load font! (\"Fonts / FunHouse.ttf\")" << std::endl;
	}
}

void Game::initText() {
	this->guiText.setFont(this->font);
	this->guiText.setFillColor(sf::Color::White);
	this->guiText.setCharacterSize(50);
	this->guiText.setString("Test");
}

// Constructor and Destructor
Game::Game() {

	this->initVariables();
	this->initWindow();
	this->initFonts();
	this->initText();

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

void Game::updateCollision() {
	// Collision Check

	for (size_t i = 0; i < this->balls.size(); i++) {
		if (this->player.getShape().getGlobalBounds().intersects(this->balls[i].getShape().getGlobalBounds())) {

			this->balls.erase(this->balls.begin() + i);
			this->points++;
		}

	}
}

void Game::updateGui() {

	std::stringstream ss;

	ss << "Points: " << this->points;

	this->guiText.setString(ss.str());
}

void Game::update() {
	this->pollEvents();

	this->spawnBalls();
	this->player.update(this->window);
	this->updateCollision();
	this->updateGui();
}

void Game::renderGui(sf::RenderTarget* target) {
	target->draw(this->guiText);
}

void Game::render() {
	this->window->clear();

	// Rendering
	this->player.render(this->window);

	for (auto i : this->balls) {
		i.render(*this->window);
	}

	// Render GUI
	this->renderGui(this->window);

	this->window->display();
}
