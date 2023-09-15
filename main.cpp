#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/VideoMode.hpp>

#include "tracer.hpp"

const uint32_t SCREEN_WIDTH  = 1024; 
const uint32_t SCREEN_HEIGHT = 740;

int main()
{
    sf::Texture texture;
    texture.create(SCREEN_WIDTH, SCREEN_HEIGHT);

    sf::Sprite sprite(texture);

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "raytracer");

    Scene scene;
    scene.setExampleScene();

    Tracer tracer(&scene, SCREEN_WIDTH, SCREEN_HEIGHT);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                int32_t x = event.mouseButton.x;
                int32_t y = event.mouseButton.y;

                printf("%d %d %d\n", x, y, tracer.getSphereId(x, y));
            }

            if (event.type == sf::Event::MouseMoved)
            {
                int32_t x = event.mouseMove.x;
                int32_t y = event.mouseMove.y;

                int8_t id = tracer.getSphereId(x, y);
                tracer.setTarget(id);

                printf("%d %d %d\n", x, y, id);
            }
        }

        texture.update(tracer.render());
        sprite.setTexture(texture);

        window.clear(sf::Color::White);
        window.draw(sprite);
        window.display();
    }

    return 0;
}
