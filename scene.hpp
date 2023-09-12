#ifndef SCENE_HPP
#define SCENE_HPP

#include "sphere.hpp"
#include "light.hpp"

class Scene
{
    static const int MAX_SPHERES = 5;
    static const int MAX_LIGHTS  = 2;

    int8_t m_cnt_spheres;
    Sphere m_spheres[MAX_SPHERES];

    int8_t m_cnt_lights;
    Light  m_lights[MAX_LIGHTS];

public:

    Scene() : 
        m_cnt_spheres (0),
        m_spheres     {},
        m_cnt_lights  (0),
        m_lights      {}
    {}

    Scene(const Scene &rhs) = default;

    Scene& operator = (const Scene &rhs) = default;

    ~Scene()
    {
        m_cnt_spheres = 0;
        m_cnt_lights  = 0;
    }

    void addSphere(const Sphere &sphere)
    {
        if (m_cnt_spheres >= MAX_SPHERES)
            return;

        m_spheres[m_cnt_spheres++] = sphere;
    }

    void addLight(const Light &light)
    {
        if (m_cnt_lights >= MAX_LIGHTS)
            return;

        m_lights[m_cnt_lights++] = light;
    }

    int8_t cntSpheres() const
    {
        return m_cnt_spheres;
    }

    const Sphere* spheres() const
    {
        return m_spheres;
    }

    int8_t cntLights() const
    {
        return m_cnt_lights;
    }

    const Light* lights() const
    {
        return m_lights;
    }
};

#endif  // SCENE_HPP

