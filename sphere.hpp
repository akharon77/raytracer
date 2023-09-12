#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "vector.hpp"
#include "material.hpp"
#include "rayhit.hpp"

class Sphere
{
    Vector3  m_center;
    double   m_radius;

    Material m_material;

public:

    Sphere(const Vector3 &center = {}, double radius = 0, Material material = {}) :
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

    RayHit rayIntersect(const Vector3 &pos, const Vector3 &dir) const;
};

#endif  // SPHERE_HPP

