#include "lights/baselight.hpp"




RT::BaseLight::BaseLight()
{

}



RT::BaseLight::~BaseLight()
{

}



bool RT::BaseLight::Computeillumination(
    const QBVD &intPoint,
                const QBVD &localNormal,
                const std::vector<std::shared_ptr<RT::BaseObject>> &objectList,
                const std::shared_ptr<RT::BaseObject> &currentObject,
                QBVD &color, double &intensity
)
{
    return false;
}



