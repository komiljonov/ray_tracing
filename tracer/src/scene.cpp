#include "scene.h"

RT::Scene::Scene()
{

    m_camera.SetPosition(QBVD{std::vector<double>{0.0, -10.0, 0.0}});
    m_camera.SetLookAt(QBVD{std::vector<double>{0.0, 0.0, 0.0}});
    m_camera.SetUp(QBVD{std::vector<double>{0.0, 0.0, 1.0}});

    m_camera.SetHorzSize(0.25);
    m_camera.SetAspect(1);
    m_camera.UpdateCameraGeometry();

    m_objectList.push_back(std::make_shared<RT::SphereObject>(RT::SphereObject()));



    m_lightList.push_back(std::make_shared<RT::PointLight>(RT::PointLight()));

    std::cout << m_lightList.size() << std::endl;


    m_lightList.at(0) -> m_location = QBVD {std::vector<double>{5.0,-10.0,-5.0}};
    m_lightList.at(0) -> m_color = QBVD {std::vector<double>{255,255,255}};
    std::cout << m_lightList.size() << std::endl;



}

bool RT::Scene::Render(RTImage &outputImage)
{
        // std::cout << "Render --------- START" << std::endl;


    int xSize = outputImage.GetXSize();
    int ySize = outputImage.GetYSize();

    RT::Ray cameraRay;

    QBVD intPoint{3};
    QBVD localNormal{3};
    QBVD localColor{3};

    double xFact = 1.0 / (static_cast<double>(xSize) / 2.0);
    double yFact = 1.0 / (static_cast<double>(ySize) / 2.0);
    double minDist = 1e6;
    double maxDist = 0.0;

    for (int x = 0; x < xSize; ++x)
    {
        for (int y = 0; y < ySize; ++y)
        {

            double normX = (static_cast<double>(x) * xFact) - 1.0;
            double normY = (static_cast<double>(y) * yFact) - 1.0;

            m_camera.GenerateRay(normX, normY, cameraRay);

            for (auto currentObject : m_objectList)
            {

                bool validInt = currentObject->TestIntersections(cameraRay, intPoint, localNormal, localColor);

                if (validInt)
                {


                    double intensity;
                    QBVD color {3};
                    bool validIlum = false;
                    for (auto light : m_lightList)
                    {
                        validIlum = light -> Computeillumination(intPoint,localNormal, m_objectList, currentObject, color,intensity);

                    }


                    double dist = (intPoint - cameraRay.m_point1).norm();
                    if (dist > maxDist)
                        maxDist = dist;

                    if (dist < minDist)
                        minDist = dist;

                    // outputImage.SetPixel(x, y, 255 - ((dist - 9.0) / 0.94605) * 255, 0, 0);

                    if(validIlum)
                    {
                        outputImage.SetPixel(x,y,255 * intensity, 0.0,0.0);

                    }
                    else
                    {
                        outputImage.SetPixel(x,y,0.0,0.0,0.0);

                    }
                }
                else
                {
                    outputImage.SetPixel(x, y, 0, 0, 0);
                }
            }

            // bool validInt = m_testSphere.TestIntersections(cameraRay, intPoint,localNormal, localColor);
        }
        // std::cout << "Render --------- End" << std::endl;
    }

    // std::cout << "Minimum distance: " << minDist << std::endl;
    // std::cout << "maximum distance: " << maxDist << std::endl;

    return true;
}
