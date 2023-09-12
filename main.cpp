#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/VideoMode.hpp>

const uint32_t SCREEN_WIDTH  = 720;
const uint32_t SCREEN_HEIGHT = 480;

int main()
{
    sf::Texture texture;
    texture.create(SCREEN_WIDTH, SCREEN_HEIGHT);

    sf::Sprite sprite(texture);

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "raytracer");

    Scene scene;
    Tracer tracer(scene);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(sprite);
        window.display();
    }

return 0;
}
