#ifndef BASE_LIGHT_H
#define BASE_LIGHT_H







#include <memory>
#include "qblinalg/qbVector.h"
#include "ray.h"
#include "objects/baseobject.hpp"






namespace RT
{
    class BaseLight
    {
        public:
            BaseLight();
            virtual ~BaseLight();


            virtual bool Computeillumination(
                const QBVD &intPoint,
                const QBVD &localNormal,
                const std::vector<std::shared_ptr<RT::BaseObject>> &objectList,
                const std::shared_ptr<RT::BaseObject> &currentObject,
                QBVD &color, double &intensity);



        public:
            QBVD m_color {3};
            QBVD m_location {3};
            double m_intensity;

    };
}








#endif
