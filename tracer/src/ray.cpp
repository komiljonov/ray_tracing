

#include "ray.h"

RT::Ray::Ray()
{

    m_point1 = QBVD{std::vector<double>{0.0,0.0,0.0}};
    m_point2 = QBVD{std::vector<double>{0.0,0.0,1.0}};
    m_lab = m_point2 - m_point1;

}
RT::Ray::Ray(const QBVD &point1,const QBVD &point2)
{

    m_point1 = point1;
    m_point2 = point2;

    m_lab = m_point2 - m_point1;
}

qbVector<double> RT::Ray::GetPoint1() const
{
    return m_point1;
}

qbVector<double> RT::Ray::GetPoint2() const
{
    return m_point2;
}

