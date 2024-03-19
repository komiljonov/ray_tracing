#ifndef C_APP_H
#define C_APP_H

#include <SDL2/SDL.h>
#include "rtImage.h"
#include <iostream>
#include "scene.h"
#include "camera.h"
#include "qblinalg/qbVector.h"




class App
{
    public:
        App(const int w, const int h);

        int OnExecute();
        bool OnInit();
        void OnEvent(SDL_Event *event);
        void OnLoop();
        void OnRender();
        void OnExit();

    private:
        void PrintVector(const QBVD &inputVector);



    private:
        RTImage m_image;

        RT::Scene m_scene;


        bool isRunning;
        SDL_Window *pWindow;
        SDL_Renderer *pRenderer;
        int wWidth;
        int wHeight;





};






#endif


