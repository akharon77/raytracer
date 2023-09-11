#ifndef TRACER_HPP
#define TRACER_HPP

class Tracer
{
    int32_t m_width;
    int32_t m_height;

    Scene       m_scene;
    sf::Texture m_texture;

public:

    Tracer(Scene scene) :
        m_width(width),
        m_height(height),
        m_scene(scene)
    {
        m_texture.create(width, height);
    }

    Tracer(const Tracer &rhs) = default;

    Tracer& operator = (const Tracer &rhs) = default;

    void render()
    {

    }
};

#endif  // TRACER_HPP

