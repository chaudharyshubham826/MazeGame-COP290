#include "App.h"
#include <SDL2/SDL.h>
#include "Line2D.h"
#include "Triangle.h"
#include "AARectangle.h"
#include "Circle.h"
#include "Color.h"


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
        aScreen.Draw(trngl, Color::Green(), true, Color::Green());
        aScreen.Draw(rect, Color::Blue(), true, Color::Blue());
        aScreen.Draw(circle, Color(0, 255, 0, 0), true, Color(0, 255, 0, 0));

        
        aScreen.SwapScreens();


        SDL_Event event;
        bool running = true;

        while(running)
        {
            while(SDL_PollEvent(&event))
            {
                switch (event.type)
                {
                case SDL_QUIT:
                    running = false;
                    break;
                }
            }
        }
    }
    
}