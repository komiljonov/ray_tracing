#ifndef CAMERA_H
#define CAMERA_H


// #include "qblinalg/qbVector.h"
#include "ray.h"




namespace RT
{
    class Camera
    {
        public:
            Camera();

            void SetPosition(const QBVD &newPosition);
            void SetLookAt(const QBVD &newLookAt);
            void SetUp(const QBVD &upVector);
            void SetLength(double newLength);
            void SetHorSize(double newSize);
            void setAspect(double newAspect);
            void SetHorzSize(double newAspect);
            void SetAspect(double newAspect);


            QBVD GetPosition();
            QBVD GetLookAt();
            QBVD GetUp();
            QBVD GetU();
            QBVD GetV();
            QBVD GetScreenCentre();
            double GetLength();
            double GetHorzSize();
            double GetAspect();



            bool GenerateRay(float proScreenX,float proScreenY, RT::Ray &cameraRay);

            void UpdateCameraGeometry();


        private:
            QBVD m_cameraPosition   {3};
            QBVD m_cameraLookAt     {3};
            QBVD m_cameraUp         {3};

            double m_cameraLength;
            double m_cameraHorzSize;
            double m_cameraAspectRatio;

            QBVD m_alignmentVector          {3};
            QBVD m_projectionScreenU        {3};
            QBVD m_projectionScreenV        {3};
            QBVD m_projectionScreenCentre   {3};


    };
};



#endif
