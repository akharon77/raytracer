#ifndef VECTOR_HPP
#define VECTOR_HPP

class Vector3
{
    double m_x, m_y, m_z;

public:

    Vector3(double x = 0, double y = 0, double z = 0) :
        m_x(x),
        m_y(y),
        m_z(z)
    {}

    Vector3(const Vector3 &rhs) = default;

    Vector3& operator = (const Vector3 &rhs) = default;

    ~Vector3()
    {
        m_x = NAN;
        m_y = NAN;
        m_z = NAN;
    }

    Vector3 operator + (const Vector3 &rhs) const
    {
        return Vector3(*this) += rhs;
    }

    Vector3 operator - (const Vector3 &rhs) const
    {
        return Vector3(*this) -= rhs;
    }
    
    Vector3 operator * (const double rhs) const
    {
        return Vector3(*this) *= rhs;
    }

    Vector3 operator / (const double rhs) const
    {
        return Vector3(*this) /= rhs;
    }

    Vector3& operator += (const Vector3 &rhs)
    {
        m_x += rhs.m_x;
        m_y += rhs.m_y;
        m_z += rhs.m_z;

        return *this;
    }

    Vector3& operator -= (cont Vector3 &rhs)
    {
        m_x -= rhs.m_x;
        m_y -= rhs.m_y;
        m_z -= rhs.m_z;

        return *this;
    }

    Vector3& operator *= (const double rhs)
    {
        m_x *= rhs;
        m_y *= rhs;
        m_z *= rhs;

        return *this;
    }

    Vector3& operator /= (const double rhs)
    {
        rhs = 1.0 / rhs;

        m_x *= rhs;
        m_y *= rhs;
        m_z *= rhs;

        return *this;
    }

    Vector3 operator - () const
    {
        return (*this) * (-1);
    }

    double len2() const
    {
        return dot(*this, *this);
    }

    double len() const
    {
        return sqrt(len2());
    }

    Vector3 norm() const
    {
        return *this / len();
    }

    static double dot(const Vector3 &lhs, const Vector3 &rhs)
    {
        double res = lhs.m_x * rhs.m_x +
                     lhs.m_y * rhs.m_y +
                     lhs.m_z * rhs.m_z;

        return res;
    }

    Vector3 projection(const Vector3 &rhs) const
    {
        return dot(*this, rhs) / rhs.len();
    }

    operator sf::Color() const
    {
        m_x = max(min(m_x, 1), 0);
        m_y = max(min(m_y, 1), 0);
        m_z = max(min(m_z, 1), 0);
        
        return sf::Color((uint8_t) (m_x * 255), (uint8_t) (m_y * 255), (uint8_t) (m_z * 255));
    }
};

#endif  // VECTOR_HPP

