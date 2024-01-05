#include <SFML/Graphics.hpp>
#include "Player.h"
#include <string>
#include <iostream>

// assets 72 x 64

Player::Player(std::string name)
{
	this->name = name;

	if (playerTexture.loadFromFile("Assets\\Player\\Textures\\spritesheetskeleton.png"))
	{
		std::cout << "-- Player : " << name << " assets loaded " << std::endl;

		playerSprite.setTexture(playerTexture);
		playerSprite.setTextureRect(sf::IntRect(0, 0, 72, 64));
	}
	else
	{
		std::cout << "-- Player : " << name << " failed to load assets" << std::endl;
	}

	setPlayerStats();
}

void Player::setPlayerStats()
{
	moveSpeed = 5;


}

std::string Player::getPlayerName()
{

}

unsigned long Player::getHealth()
{

}

void Player::move(DIRECTION direction)
{
	if (++countStep > 7)
		countStep = 0;

	switch (direction)
	{
		case UP: {
			playerSprite.setTextureRect(sf::IntRect(countStep * 64, 0, 64, 64));
			playerSprite.setPosition(position + sf::Vector2f(0, -1*moveSpeed));
		}break;

		case DOWN: {
			playerSprite.setTextureRect(sf::IntRect(countStep * 64, 128, 64, 64));
			playerSprite.setPosition(position + sf::Vector2f(0, 1 * moveSpeed));
		}break;

		case LEFT: {
			playerSprite.setTextureRect(sf::IntRect(countStep * 64, 64, 64, 64));
			playerSprite.setPosition(position + sf::Vector2f(-1 * moveSpeed, 0));
		}break;

		case RIGHT: {
			playerSprite.setTextureRect(sf::IntRect(countStep * 64, 196, 64, 64));
			playerSprite.setPosition(position + sf::Vector2f(1 * moveSpeed, 0));
		}break;

		default: {
			std::cout << "Wrong direction case : " << direction << std::endl;
		}break;
	}
	std::cout << playerSprite.getGlobalBounds().left << " " << playerSprite.getGlobalBounds().top << " " << playerSprite.getGlobalBounds().height << " " << playerSprite.getGlobalBounds().width << " " << std::endl;
}

void Player::attack(sf::Sprite& target)
{

}

void Player::reloadPosition()
{
	position = playerSprite.getPosition();
}

void Player::setPosition(sf::Vector2f position)
{
	this->position = position;
	this->playerSprite.setPosition(position);

}
