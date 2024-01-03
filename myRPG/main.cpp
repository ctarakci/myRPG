#include <SFML/Graphics.hpp>

int main()
{
    sf::Vector2f mov(0.0f, 10.0f);

    sf::RenderWindow window(sf::VideoMode(1000, 600), "myRPG");
    sf::RectangleShape rec(sf::Vector2f(10.0f, 5.0f));
    rec.setPosition(sf::Vector2f(0.0f, 10.0f));
    rec.setFillColor(sf::Color::Magenta);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(mov.x < 990)
        {
            mov.x += 1.0f;
        }
        else
        {
            mov.y += 1.0f;
        }

        rec.setPosition(mov);
        window.clear();
        window.draw(rec);
        window.display();
    }

    return 0;
}