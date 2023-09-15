#ifndef RAYHIT_HPP
#define RAYHIT_HPP

class RayHit
{
    bool     m_flag;

    double   m_len_hit;
    Vector3  m_hit_pos;
    Vector3  m_hit_norm;
    Material m_material;

    int8_t   m_id;

public:

    RayHit(bool flag, double len_hit = 0, Vector3 hit_pos = {}, Vector3 hit_norm = {}, Material material = {}, int8_t id = -1) :
        m_flag     (flag),
        m_len_hit  (len_hit),
        m_hit_pos  (hit_pos),
        m_hit_norm (hit_norm),
        m_material (material),
        m_id       (id)
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

    void setMaterial(const Material& material)
    {
        m_material = material;
    }

    Material material() const
    {
        return m_material;
    }

    void setId(int8_t id)
    {
        m_id = id;
    }

    int8_t id() const
    {
        return m_id;
    }
};

#endif  // RAYHIT_HPP

