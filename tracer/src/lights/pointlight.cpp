#include "lights/pointlight.hpp"





RT::PointLight::PointLight()
{
    m_color = QBVD { std::vector<double>{1.0,1.0,1.0}};

    m_intensity = 1.0;
}



RT::PointLight::~PointLight()
{

}




bool RT::PointLight::Computeillumination(
    const QBVD &intPoint,
                const QBVD &localNormal,
                const std::vector<std::shared_ptr<RT::BaseObject>> &objectList,
                const std::shared_ptr<RT::BaseObject> &currentObject,
                QBVD &color, double &intensity
)
{


    QBVD lightDir = (m_location - intPoint).Normalized();

    QBVD startPoint = intPoint;


    double angle = acos(QBVD::dot(localNormal, lightDir));


    if(angle > 1.5708)
    {
        color = m_color;
        intensity = 0.0;
        return false;
    }
    else
    {
        color = m_color;
        intensity = m_intensity * (1.0 - (angle/1.5708));

    }



}


