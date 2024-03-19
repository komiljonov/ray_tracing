#ifndef SCENE_H
#define SCENE




#include <memory>
#include <vector>
#include <SDL2/SDL.h>
#include <rtImage.h>
#include "camera.h"
#include "objects/sphere.hpp"
#include "lights/pointlight.hpp"




namespace RT
{
    class Scene
    {
        public:
            Scene();


            bool Render(RTImage &outputImage);

        private:
            RT::Camera m_camera;

            // RT::SphereObject m_testSphere;

            std::vector<std::shared_ptr<RT::BaseObject>> m_objectList;

            std::vector<std::shared_ptr<RT::BaseLight>> m_lightList;





    };
};


#endif
