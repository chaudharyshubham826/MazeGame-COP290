#include "App.h"
#include <SDL2/SDL.h>
#include "iostream"
#include "Line2D.h"
#include "Triangle.h"
#include "AARectangle.h"
#include "Circle.h"
#include "Color.h"

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
        Line2D line = {Vec2D(0, 0), Vec2D(aScreen.Width(), aScreen.Height())};
        Triangle trngl = {Vec2D(60, 10), Vec2D(10, 60), Vec2D(110, 60)};
        AARectangle rect = {Vec2D(10, 70), Vec2D(120, 120)};
        Circle circle = {Vec2D(150, 150), 50.0f};
        // screen.Draw(line, Color::White());


        


        SDL_Event event;
        bool running = true;

        uint32_t lastTick = SDL_GetTicks();
        uint32_t currentTick = lastTick;

        uint32_t dt = 10;
        uint32_t accumulator = 0;

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
                cout << "Delta time step: " <<dt << endl;
                accumulator -= dt;
            }

            // Render
            aScreen.Draw(trngl, Color::Green(), true, Color::Green());
            aScreen.Draw(rect, Color::Blue(), true, Color::Blue());
            aScreen.Draw(circle, Color(0, 255, 0, 0), true, Color(0, 255, 0, 0));

            aScreen.SwapScreens();
            
        }
    }
    
}