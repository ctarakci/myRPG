#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Goblin.h"

Goblin::Goblin(std::string name)
{
	this->name = name;

	if (playerTexture.loadFromFile("Assets\\Player\\Textures\\spritesheetgoblin.png"))
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


void Goblin::setPlayerStats()
{
	moveSpeed = 2;
	
}

std::string Goblin::getPlayerName()
{

	return name;
}

unsigned long Goblin::getHealth()
{
	return health;
}

void Goblin::move(DIRECTION direction)
{
	if (++countStep > 7)
		countStep = 0;

	switch (direction)
	{
	case UP: {
		playerSprite.setTextureRect(sf::IntRect(countStep * 64, 0, 64, 64));
		playerSprite.setPosition(position + sf::Vector2f(0, -1 * moveSpeed));
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
}

void Goblin::attack(sf::Sprite& target)
{


}

void Goblin::reloadPosition()
{
	position = playerSprite.getPosition();
}

void Goblin::setPosition(sf::Vector2f position)
{
	this->position = position;
	this->playerSprite.setPosition(position);
}

