#ifndef TRACER_HPP
#define TRACER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

#include "vector.hpp"
#include "material.hpp"
#include "scene.hpp"
#include "rayhit.hpp"

class Tracer
{
    static constexpr int8_t MAX_DEPTH = 3;
    static constexpr double EPS       = 1e-5;

    int32_t   m_width;
    int32_t   m_height;

    double    m_ratio;

    double    m_left;
    double    m_top;
    double    m_right;
    double    m_bottom;

    Vector3   m_camera;
    Scene     m_scene;
    sf::Image m_image;

public:

    Tracer(Scene scene, int32_t width, int32_t height) :
        m_width  (width),
        m_height (height),

        m_scene  (scene),

        m_ratio  ((double) width / height),

        m_left   (-1),
        m_top    ( 1 / m_ratio),
        m_right  ( 1),
        m_bottom (-1 / m_ratio),

        m_camera (0, 0, 1)
    {
        m_image.create(width, height);
    }

    Tracer(const Tracer &rhs) = default;

    Tracer& operator = (const Tracer &rhs) = default;

    RayHit nearestHitSphere(const Vector3 &pos, const Vector3 &dir) const;

    const sf::Image& render();
};

#endif  // TRACER_HPP

