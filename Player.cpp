#include "Player.h"

void Player::initVariables() {
	this->movementSpeed = 5.f;
	this->hpMax = 10;
	this->hp = hpMax;
}

void Player::initShape() {
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
}

Player::Player(float x, float y) {

	this->shape.setPosition(x, y);

	this->initVariables();
	this->initShape();

}

Player::~Player() {
}

const sf::RectangleShape& Player::getShape() {

	return this->shape;
}

void Player::updateInput() {
	// Keyboard input

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		this->shape.move(-this->movementSpeed, 0.f);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		this->shape.move(this->movementSpeed, 0.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		this->shape.move(0.f, -this->movementSpeed);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		this->shape.move(0.f, this->movementSpeed);
	}
}

void Player::updateWindowBoundsCollision(const sf::RenderTarget* target) {


	// Left
	if (this->shape.getGlobalBounds().left <= 0.f)
		this->shape.setPosition(0.f, this->shape.getGlobalBounds().top);

	// Right
	if (this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width >= target->getSize().x)
		this->shape.setPosition(target->getSize().x - this->shape.getGlobalBounds().width, this->shape.getGlobalBounds().top);

	// Top
	if (this->shape.getGlobalBounds().top <= 0.f)
		this->shape.setPosition(this->shape.getGlobalBounds().left, 0.f);

	// Bottom
	if (this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height >= target->getSize().y)
		this->shape.setPosition(this->shape.getGlobalBounds().left, target->getSize().y - this->shape.getGlobalBounds().height);
}

void Player::update(const sf::RenderTarget* target) {


	this->updateInput();

	// Boundaries 
	this->updateWindowBoundsCollision(target);

}

void Player::render(sf::RenderTarget* target) {
	target->draw(this->shape);
}
