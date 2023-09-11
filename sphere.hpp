#ifndef SPHERE_HPP
#define SPHERE_HPP

class Sphere
{
    Vector3  m_center;
    double   m_radius;

    Material m_material;

public:

    Sphere(const Vector3 &center, double radius, Material material) :
        m_center   (center),
        m_radius   (radius),
        m_material (material)
    {}

    Sphere(const Sphere &rhs) = default;

    Sphere& operator = (const Sphere &rhs) = default;

    ~Sphere()
    {
        m_radius = NAN;
    }

    bool rayIntersect(const Vector3 &pos, const Vector3 &dir, Vector3 &hit_pos, Vector3 &hit_norm) const;
};

#endif  // SPHERE_HPP

