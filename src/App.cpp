#include "App.h"
#include <iostream>
#include "utils.h"
#include "camera.h"


App::App(const int w, const int h)
{

    wWidth = w;
    wHeight = h;

    isRunning = true;
    pWindow = NULL;
    pRenderer = NULL;
}

bool App::OnInit()
{

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return false;
    }

    pWindow = SDL_CreateWindow("Ray tracer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, wWidth, wHeight, SDL_WINDOW_SHOWN);

    if (pWindow == NULL)
    {
        PRINT_ERROR();
        return false;
    }

    pRenderer = SDL_CreateRenderer(pWindow, -1, 0);

    if (pRenderer == NULL)
    {
        PRINT_ERROR();
        return false;
    }

    m_image.Initialize(wWidth, wHeight, pRenderer);

    SDL_SetRenderDrawColor(pRenderer,255,255,255,255);
    SDL_RenderClear(pRenderer);

    m_scene.Render(m_image);

    m_image.Display();

    SDL_RenderPresent(pRenderer);

    return true;
}

int App::OnExecute()
{

    SDL_Event event;

    if (OnInit() == false)
    {
        return -1;
    }

    while (isRunning)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            OnEvent(&event);
        }

        OnLoop();
        OnRender();
    }
    return 0;
}

void App::OnEvent(SDL_Event *event)
{

    if (event->type == SDL_QUIT)
    {
        isRunning = false;
    }
}

void App::OnLoop()
{
}

void App::OnRender()
{
    // SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);

    // SDL_RenderClear(pRenderer);

    // m_scene.Render(m_image);
    // m_image.Display();


    // SDL_RenderPresent(pRenderer);
}

void App::OnExit()
{
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    pWindow = NULL;
    SDL_Quit();
}





// PRIVATE FUNCTION

void App::PrintVector(const QBVD &inputVector){
    int nRows = inputVector.GetNumDims();

    for (int row = 0; row < nRows; ++row)
    {
        std::cout << std::fixed << std::setprecision(3) << inputVector.GetElement(row) << std::endl;
    }

}
