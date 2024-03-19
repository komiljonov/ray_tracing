#ifndef OBJECTBASE_H
#define OBJECTBASE_H





#include "qblinalg/qbVector.h"
#include "ray.h"




namespace RT
{
    class BaseObject
    {
        public:
            BaseObject();
            virtual ~BaseObject();

            virtual bool TestIntersections(const Ray &castRay, QBVD &intPoint, QBVD &localNormal, QBVD &localColor);

            bool CloseEnough(const double f1, const double f2);


        public:
            QBVD m_baseColor {3};

    };
};


#endif
