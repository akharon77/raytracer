#ifndef SCENE_HPP
#define SCENE_HPP

class Scene
{
    static const int MAX_SPHERES = 3;
    static const int MAX_LIGHTS  = 2;

    Camera m_cam;

    int8_t m_cnt_spheres;
    Sphere m_spheres[MAX_SPHERES];

    int8_t m_cnt_lights;
    Light  m_lights[MAX_LIGHTS];

public:

    Scene(Camera cam) : 
        m_cam         (cam),
        m_cnt_spheres (0),
        m_cnt_lights  (0),
        m_spheres     {},
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
};

#endif  // SCENE_HPP

