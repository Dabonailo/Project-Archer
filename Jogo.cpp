#include "Jogo.h"

void Jogo::executar()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

    sf::RectangleShape shape;

    shape.setSize(sf::Vector2f(100.f, 100.f));

    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}
