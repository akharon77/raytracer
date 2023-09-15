#include "tracer.hpp"

RayHit Tracer::nearestHitSphere(const Vector3 &pos, const Vector3 &dir) const
{
    RayHit min_hit (false);

    int8_t min_id = -1;

    for (int8_t i = 0; i < m_scene->cntSpheres(); ++i)
    {
        RayHit hit = m_scene->spheres()[i].rayIntersect(pos, dir);

        if (hit.hit() && (!min_hit.hit() || hit.len() < min_hit.len()))
        {
            min_id  = i;
            min_hit = hit;
        }
    }

    min_hit.setId(min_id);
    return min_hit;
}

Vector3 Tracer::getIllumination(const RayHit &sphere_hit, const Light &light, const Vector3 &dir_hit_light) const
{
    Vector3 illumination = {};

    illumination += sphere_hit.material().ambient() * light.ambient();

    illumination += sphere_hit.material().diffuse() * light.diffuse() * Vector3::dot(dir_hit_light, sphere_hit.norm());

    Vector3 dir_hit_camera = (m_camera - sphere_hit.pos()).norm();
    Vector3 dir_cam_light = (dir_hit_light + dir_hit_camera).norm();
    illumination += sphere_hit.material().specular() * light.specular() * pow(Vector3::dot(sphere_hit.norm(), dir_cam_light), sphere_hit.material().shiness() / 4);

    return illumination;
}

int8_t Tracer::getSphereId(int32_t i, int32_t j)
{
    double step_y = (m_top - m_bottom) / m_height;
    double step_x = (m_right - m_left) / m_width;

    double x = m_left + i * step_x;
    double y = m_top - j * step_y;

    Vector3 pixel  = {x, y, 0};
    Vector3 origin = m_camera;
    Vector3 dir    = (pixel - origin).norm();

    RayHit sphere_hit = nearestHitSphere(origin, dir);

    return sphere_hit.id();
}

const sf::Image& Tracer::render()
{
    double step_y = (m_top - m_bottom) / m_height;
    double step_x = (m_right - m_left) / m_width;

    double x = m_left;
    for (int32_t i = 0; i < m_width; ++i, x += step_x)
    {
        double y = m_top;
        for (int32_t j = 0; j < m_height; ++j, y -= step_y)
        {
            Vector3 pixel  = {x, y, 0};
            Vector3 origin = m_camera;
            Vector3 dir    = (pixel - origin).norm();

            m_image.setPixel(i, j, (sf::Color) rayHit(origin, dir));
        }
    }

    return m_image;
}

Vector3 Tracer::rayHit(Vector3 &origin, Vector3 &dir) const
{
    double reflection = 1;
    Vector3 color = {};

    for (int8_t k = 0; k < MAX_DEPTH; ++k)
    {
        RayHit sphere_hit = nearestHitSphere(origin, dir);

        if (!sphere_hit.hit())
            break;

        if (sphere_hit.id() == m_target && m_target != -1)
        {
            color = {1, 0, 0};
            break;
        }

        Vector3 shifted_hit_pos = sphere_hit.pos() + sphere_hit.norm() * EPS;

        Vector3 illumination = {};

        for (int8_t l = 0; l < m_scene->cntLights(); ++l)
        {
            Light light = m_scene->lights()[l];

            Vector3 dir_hit_light = (light.pos() - shifted_hit_pos).norm();

            double len_hit_to_light = (light.pos() - sphere_hit.pos()).len();

            RayHit light_hit = nearestHitSphere(shifted_hit_pos, dir_hit_light);
            if (light_hit.hit() && light_hit.len() < len_hit_to_light)
                continue;

            illumination += getIllumination(sphere_hit, light, dir_hit_light);
        }

        color +=  illumination * reflection;
        reflection *= sphere_hit.material().reflection();
        origin = shifted_hit_pos;

        dir = (dir - sphere_hit.norm() * 2 * Vector3::dot(dir, sphere_hit.norm())).norm();
    }

    return color;
}

