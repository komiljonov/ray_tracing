#include "objects/sphere.hpp"
#include <cmath>




RT::SphereObject::SphereObject()
{

}




RT::SphereObject::~SphereObject()
{

}





bool RT::SphereObject::TestIntersections(const Ray &castRay, QBVD &intPoint, QBVD &localNormal, QBVD &localColor)
{


    QBVD vhat = castRay.m_lab;
    vhat.Normalize();


    double b = 2.0 * QBVD::dot(castRay.m_point1, vhat);


    double c = QBVD::dot(castRay.m_point1, castRay.m_point1) -1.0;


    double intTest = (b*b) - 4.0 * c;

    if(intTest > 0.0)
    {


        double numSQRT = sqrtf(intTest);
        double t1 = (-b + numSQRT) /2.0;
        double t2 = (-b-numSQRT) / 2.0;

        if((t1 < 0.0) || (t2 < 0.0))
        {
            return false;
        }
        else
        {

            if(t1<t2)
            {
                intPoint = castRay.m_point1 + (vhat + t1);

            }
            else
            {
                intPoint = castRay.m_point1 + (vhat * t2);

            }

            localNormal = intPoint;
            localNormal.Normalize();


        }


        return true;
    }
    return false;









}
