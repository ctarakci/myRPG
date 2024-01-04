#pragma once
typedef enum {
    LEFT,
    RIGHT,
    UP,
    DOWN
}DIRECTION;

class Player {
public:
    Player(std::string name);
    virtual void setPlayerStats();
    std::string getPlayerName();
    unsigned long getHealth();
    void move(DIRECTION direction);
    void attack(Player& target);
    void reloadPosition();

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
