#include <algorithm>

#include "sphere.hpp"

RayHit Sphere::rayIntersect(const Vector3 &pos, const Vector3 &dir) const
{
    double  len_hit = 0;
    Vector3 hit_pos;
    Vector3 hit_norm;

    double rad2 = m_radius * m_radius;

    Vector3 pos_to_center = m_center - pos;
    double  len2_center   = pos_to_center.len2();
    double   len_center   = sqrt(len2_center);

    double  len_proj      = Vector3::dot(pos_to_center, dir);

    if (len_center > m_radius && len_proj < 0)
        return RayHit(false);

    double len2_proj = len_proj * len_proj;

    double len2_vec_center = len2_center - len2_proj;
    double  len_vec_center = sqrt(len2_vec_center);

    if (len_vec_center > m_radius)
        return RayHit(false);

    len_hit = sqrt(rad2 - len2_vec_center);
    if (m_radius < len_center)
        len_hit *= -1;

    len_hit += len_proj;
    hit_pos  = pos + dir * len_hit;
    hit_norm = (hit_pos - m_center).norm();

    return RayHit(true, len_hit, hit_pos, hit_norm, m_material);
}

