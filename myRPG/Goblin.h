#pragma once
#include "definitions.h"

class Goblin
{
public:
    Goblin(std::string name);
    void setPlayerStats();
    std::string getPlayerName();
    unsigned long getHealth();
    void move(DIRECTION direction);
    void attack(sf::Sprite& target);
    void reloadPosition();
    void setPosition(sf::Vector2f position);


    sf::Sprite      playerSprite;
private:
    sf::Vector2f    position;
    sf::Texture     playerTexture;
    std::string     name;
    unsigned long   health;
    unsigned long   damage;
    float           attackSpeed;
    unsigned char   moveSpeed;
    unsigned char   countStep;
};

