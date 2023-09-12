#ifndef MATERIAL_HPP
#define MATERIAL_HPP

class Material
{
    Vector3 m_ambient_color;
    Vector3 m_diffuse_color;
    Vector3 m_specular_color;

    double  m_shiness;

public:

    Material(Vector3 ambient_color, Vector3 diffuse_color, Vector3 specular_color, double shiness) :
        m_ambient_color  (ambient_color),
        m_diffuse_color  (diffuse_color),
        m_specular_color (specular_color),
        m_shiness        (shiness)
    {}

    Material(const Material& rhs) = default;

    Material& operator = (const Material& rhs) = default;

    ~Material()
    {
        m_shiness = NAN;
    }
};

#endif  // MATERIAL_HPP
