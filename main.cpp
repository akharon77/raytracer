#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/VideoMode.hpp>

#include "tracer.hpp"

const uint32_t SCREEN_WIDTH  = 1024; 
const uint32_t SCREEN_HEIGHT = 576;

int main()
{
    sf::Texture texture;
    texture.create(SCREEN_WIDTH, SCREEN_HEIGHT);

    sf::Sprite sprite(texture);

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "raytracer");

    Scene scene;

    scene.addLight(
        {
            {5, 5, 5},
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1}
        });

    // scene.addLight(
    //     {
    //         {-9, -5, -5},
    //         {1, 1, 1},
    //         {1, 1, 1},
    //         {1, 1, 1}
    //     });
    
    scene.addSphere(
        {
            {-0.2, 0, -1},
            0.7,
            {
                {0.1, 0, 0},
                {0.7, 0, 0},
                {  1, 1, 1},
                100,
                0.8
            }
        });

    scene.addSphere(
        {
            {0.1, -0.3, 0},
            0.1,
            {
                {0.1, 0, 0.1},
                {0.7, 0, 0.7},
                {  1, 1, 1},
                100,
                0
            }
        });

    scene.addSphere(
        {
            {-0.3, 0, 0},
            0.15,
            {
                {0, 0.1, 0},
                {0, 0.6, 0},
                {1,   1, 1},
                100,
                0.6
            }
        });

    scene.addSphere(
        {
            {0.5, -0.3, -0.3},
            0.1,
            {
                {0, 0, 0.2},
                {0, 0, 0.5},
                {1, 1,   1},
                100,
                1
            }
        });

    Tracer tracer(scene, SCREEN_WIDTH, SCREEN_HEIGHT);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        texture.update(tracer.render());
        sprite.setTexture(texture);

        window.clear(sf::Color::White);
        window.draw(sprite);
        window.display();
    }

    return 0;
}
