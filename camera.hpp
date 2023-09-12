#ifndef CAMERA_HPP
#define CAMERA_HPP

class Camera
{
    Vector3 m_pos;
    Vector3 m_dir;

public:

    Camera(Vector3 pos, Vector3 dir) :
        m_pos (pos),
        m_dir (dir)
    {}
    
    Camera(const Camera &rhs) = default;

    Camera& operator = (const Camera &rhs) = default;

    ~Camera()
    {
        m_width  = 0;
        m_height = 0;
        m_fov    = NAN;
    }
};

#endif  // CAMERA_HPP

