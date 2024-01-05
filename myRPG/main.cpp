#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Player.h"
#include "Goblin.h"
#include <Windows.h>


int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    
    sf::RenderWindow window(sf::VideoMode(1000, 600), "myRPG", sf::Style::Default, settings);

    Player* skeleton = new Player("Barnie");
    Goblin* goblin = new Goblin("Hunica");
    goblin->setPosition(sf::Vector2f(150, 200));
    goblin->move(DOWN);



    //sf::Texture playerTexture;
    //sf::Sprite playerSprite;

    //if (playerTexture.loadFromFile("Assets\\Player\\Textures\\spritesheet.png"))
    //{
    //    std::cout << "Player image Loaded !!" << std::endl;
    //    playerSprite.setTexture(playerTexture);
    //    playerSprite.setTextureRect(sf::IntRect(256, 128, 64, 64));
    //}
    //else
    //{
    //    std::cout << "Failed to Load" << std::endl;
    //}

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        skeleton->reloadPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            skeleton->move(UP);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            skeleton->move(LEFT);
               
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            skeleton->move(RIGHT);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            skeleton->move(DOWN);


        window.clear();
        window.draw(skeleton->playerSprite);
        window.draw(goblin->playerSprite);
        window.display();
        Sleep(5);
    }

    return 0;
}