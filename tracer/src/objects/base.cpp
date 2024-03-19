#include "objects/baseobject.hpp"





#include <math.h>




#define EPSILON 1e-21f




RT::BaseObject::BaseObject()
{

}



RT::BaseObject::~BaseObject()
{

}



bool RT::BaseObject::TestIntersections(const Ray &castRay, QBVD &intPoint, QBVD &localNormal, QBVD &localColor)
{
    return false;

}




bool RT::BaseObject::CloseEnough(const double f1, const double f2)
{
    return fabs(f1-f2) < EPSILON;
}
