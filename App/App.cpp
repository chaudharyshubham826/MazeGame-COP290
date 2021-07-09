#include "App.h"
#include <SDL2/SDL.h>
#include "iostream"
#include "MainScene.h"

#include <memory>

using namespace std;


App& App::Singleton()
{
    static App app;
    return app;
}

bool App::Init(uint32_t width, uint32_t height, uint32_t mag)
{
    aWindow = aScreen.Init(width, height, mag);
    return aWindow != nullptr;
}

void App::Run()
{
    if(aWindow){
        
        // screen.Draw(line, Color::White());


        


        SDL_Event event;
        bool running = true;

        uint32_t lastTick = SDL_GetTicks();
        uint32_t currentTick = lastTick;

        uint32_t dt = 10;
        uint32_t accumulator = 0;

        std::unique_ptr<MainScene> mainScene = std::make_unique<MainScene>();

        mainScene->Init();

        while(running)
        {

            currentTick = SDL_GetTicks();
            uint32_t frameTime = currentTick - lastTick;

            if(frameTime > 300){
                frameTime = 300;
            }

            lastTick = currentTick;

            accumulator += frameTime;

            // Input
            while(SDL_PollEvent(&event))
            {
                switch (event.type)
                {
                case SDL_QUIT:
                    running = false;
                    break;
                }
            }

            // Update state
            while(accumulator >= dt)
            {
                // update current scene by dt
                mainScene->Update(dt);
                cout << "Delta time step: " <<dt << endl;
                accumulator -= dt;
            }

            // Render
            mainScene->Draw(aScreen);

            aScreen.SwapScreens();
            
        }
    }
    
}