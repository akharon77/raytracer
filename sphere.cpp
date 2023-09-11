#include <sphere.hpp>

bool Sphere::rayIntersect(const Vector3 &pos, const Vector3 &dir, Vector3 &hit_pos, Vector3 &hit_norm) const
{
    pos_inter = Vector3();
    hit_norm  = Vector3();

    double rad2 = m_radius * m_radius;

    Vector3 pos_to_center = m_center - pos;
    double  len2_center   = pos_to_center.len2();

    Vector3 pos_to_center_proj = pos_to_center.projection();
    double  len2_proj          = pos_to_center_proj.len2();

    if (len2_center > rad2 && len2_proj < 0)
        return false;

    double len2_vec_center = len2_center - len2_proj;

    if (len2_vec_center > rad2)
        return false;

    double len_hit = sqrt(rad2 - len2_vec_center);
    if (rad2 < len2_center)
        len_hit *= -1;

    len_hit += sqrt(len2_proj);
    hit_pos = pos + dir.norm() * len_hit;

    hit_norm = (hit_pos - m_center).norm();
}

