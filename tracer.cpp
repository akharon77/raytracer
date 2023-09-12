#include "tracer.hpp"

RayHit Tracer::nearestHitSphere(const Vector3 &pos, const Vector3 &dir) const
{
    assert(dir.len2() == 1);

    RayHit hit     (false);
    RayHit min_hit (false);

    for (int8_t i = 0; i < m_cnt_spheres; ++i)
    {
        RayHit hit = m_scene.spheres()[i].rayIntersect(pos, dir);

        if (hit.hit() && (!min_hit.hit() || hit.len() < min_hit.len()))
            min_hit = hit;
    }

    return min_hit;
}

void Tracer::render()
{
    double y = m_bottom;
    double step_y = (m_top - m_bottom) / height;

    double x = m_left;
    double step_x = (m_right - m_left) / width;

    for (int32_t i = 0; i < width; ++i, x += step_x)
    {
        for (int32_t j = 0; j < height; ++j, y += step_y)
        {
            Vector3 pixel  = {x, y, 0};
            Vector3 origin = m_camera;
            Vector3 dir    = (pixel - camera).norm();

            double reflection = 1;

            for (int8_t k = 0; k < MAX_DEPTH; ++k)
            {
                RayHit sphere_hit = nearestHitSphere(origin, dir);

                if (!sphere_hit.hit())
                    break;

                Vector3 shifted_hit_pos = sphere_hit.pos() + EPS * shpere_hit.norm();
                Vector3 dir_hit_light = (m_scene.light().pos() - shifted_hit_pos).norm();

                double len_hit_to_light = (m_scene.light().pos() - sphere_hit).len();

                RayHit light_hit = nearestHitSphere(shifted_hit_pos, dir_hit_light);
                if (light_hit.hit() && light_hit.len() < len_hit_to_light)
                    break;

                Vector3 illumination = {};

                illumination += sphere_hit.material().ambient() * m_scene.light().ambient();
            
                illumination += sphere_hit.material().diffuse() * m_scene.light().diffuse() * Vector3::dot(dir_hit_light, sphere_hit.norm());

                Vector3 dir_hit_camera = (m_camera - sphere_hit.pos()).norm();
                Vector3 H = (dir_hit_light + dir_hit_camera).norm();
                illumination += sphere_hit.material().specular() * m_scene.light().specular() * pow(Vector3::dot(sphere_hit.norm(), H), sphere_hit.material().shiness() / 4);

                color += reflection * illumination;
                reflection *= shpere_hit.material().reflection();
                origin = shifted_hit_pos;
                dir = reflected(dir, sphere_hit.norm());
            }

            m_image.setPixel(i, j, (sf::Color) color);
        }
    }
}

