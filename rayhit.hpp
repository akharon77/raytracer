#ifndef RAYHIT_HPP
#define RAYHIT_HPP

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

#endif  // RAYHIT_HPP
