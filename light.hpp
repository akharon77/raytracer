#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "vector.hpp"

class Light
{
    Vector3 m_pos;

    Vector3 m_ambient_color;
    Vector3 m_diffuse_color;
    Vector3 m_specular_color;

public:

    Light(Vector3 pos = {}, Vector3 ambient_color = {}, Vector3 diffuse_color = {}, Vector3 specular_color = {}) :
        m_pos            (pos),
        m_ambient_color  (ambient_color),
        m_diffuse_color  (diffuse_color),
        m_specular_color (specular_color)
    {}

    Light(const Light& rhs) = default;

    Light& operator = (const Light& rhs) = default;

    ~Light() = default;

    Vector3 ambient() const
    {
        return m_ambient_color;
    }

    Vector3 diffuse() const
    {
        return m_diffuse_color;
    }

    Vector3 specular() const
    {
        return m_specular_color;
    }

    Vector3 pos() const
    {
        return m_pos;
    }
};

#endif  // LIGHT_HPP
