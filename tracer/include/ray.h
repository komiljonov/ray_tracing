#ifndef RAY_H
#define RAY_H




#include "qblinalg/qbVector.h"
#include "utils.h"



namespace  RT
{
    class Ray
    {
        public:
            Ray();
            Ray(const QBVD &point1,const QBVD &point2);

            QBVD GetPoint1() const;
            QBVD GetPoint2() const;

        public:
            QBVD m_point1 {3};
            QBVD m_point2 {3};
            QBVD m_lab  {3};

    };
};



#endif
