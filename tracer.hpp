#ifndef TRACER_HPP
#define TRACER_HPP

class RayHit
{
    bool     m_flag;

    double   m_len_hit;
    Vector3  m_hit_pos;
    Vector3  m_hit_norm;
    Material m_material;

public:

    RayHit(bool flag, double len_hit = 0, Vector3 hit_pos = {}, Vector3 hit_norm = {}, Material material = {}) :
        m_len_hit  (len_hit),
        m_flag     (flag),
        m_hit_pos  (hit_pos),
        m_hit_norm (hit_norm),
        m_material (material)
    {}

    RayHit(const RayHit& rhs) = default;
    
    RayHit& operator = (const RayHit& rhs) = default;

    ~RayHit() = default;

    double len() const
    {
        return m_len_hit;
    }

    bool hit() const
    {
        return m_flag;
    }

    Vector3 pos() const
    {
        return m_hit_pos;
    }

    Vector3 norm() const
    {
        return m_hit_norm;
    }

    Material material() const
    {
        return m_material;
    }
};

class Tracer
{
    static const int8_t MAX_DEPTH = 3;
    static const double EPS       = 1e-5;

    int32_t   m_width;
    int32_t   m_height;

    double    m_ratio;

    double    m_left;
    double    m_top;
    double    m_right;
    double    m_bottom;

    Vector3   m_camera;
    Scene     m_scene;
    sf::Image m_image;

public:

    Tracer(Scene scene) :
        m_width  (width),
        m_height (height),

        m_scene  (scene),

        m_ratio  (width / height),

        m_left   (-1),
        m_top    ( 1 / m_ratio),
        m_right  ( 1),
        m_bottom (-1 / m_ratio)
    {}

    Tracer(const Tracer &rhs) = default;

    Tracer& operator = (const Tracer &rhs) = default;

    RayHit nearestHitSphere(const Vector3 &pos, const Vector3 &dir) const;

    void Tracer::render();
};

#endif  // TRACER_HPP

