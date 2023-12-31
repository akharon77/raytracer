#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "vector.hpp"

class Material
{
    Vector3 m_ambient_color;
    Vector3 m_diffuse_color;
    Vector3 m_specular_color;

    double  m_shiness;
    double  m_reflection;

public:

    Material(Vector3 ambient_color = {}, Vector3 diffuse_color = {}, Vector3 specular_color = {}, double shiness = 0, double reflection = 0) :
        m_ambient_color  (ambient_color),
        m_diffuse_color  (diffuse_color),
        m_specular_color (specular_color),
        m_shiness        (shiness),
        m_reflection     (reflection)
    {}

    Material(const Material& rhs) = default;

    Material& operator = (const Material& rhs) = default;

    ~Material()
    {
        m_shiness = NAN;
    }

    Vector3 getAmbient() const
    {
        return m_ambient_color;
    }

    Vector3 getDiffuse() const
    {
        return m_diffuse_color;
    }

    Vector3 getSpecular() const
    {
        return m_specular_color;
    }

    double getShiness() const
    {
        return m_shiness;
    }

    void setShiness(double shiness)
    {
        m_shiness = shiness;
    }

    double getReflection() const
    {
        return m_reflection;
    }
};

#endif  // MATERIAL_HPP

