


#ifndef OBJSPHERE_H
#define OBJSPHERE_H

#include "baseobject.hpp"


namespace RT
{
    class SphereObject : public BaseObject
    {
        public:
            SphereObject();

            virtual ~SphereObject() override;

            virtual bool TestIntersections(const Ray &castRay, QBVD &intPoint, QBVD &localNormal, QBVD &localColor);


            

    };
}; // namespace RT




#endif
