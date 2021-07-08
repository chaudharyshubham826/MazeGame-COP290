#include <iostream>
// #include "Utils.h"
// #include "Vec2D.h"
#include <SDL2/SDL.h>
#include "Color.h"
#include "Screen.h"
#include "Line2D.h"
#include "Triangle.h"
#include "AARectangle.h"
#include "Circle.h"

using namespace std;

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;
const int MAGNIFICATION = 3;


int main(int argc, char* argv[])
{
    Screen screen;
    screen.Init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION);

    //screen.Draw(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, Color::Red());

    Line2D line = {Vec2D(0, 0), Vec2D(SCREEN_WIDTH, SCREEN_HEIGHT)};
    Triangle trngl = {Vec2D(60, 10), Vec2D(10, 60), Vec2D(110, 60)};
    AARectangle rect = {Vec2D(10, 70), Vec2D(120, 120)};
    Circle circle = {Vec2D(150, 150), 50.0f};
    // screen.Draw(line, Color::White());
    screen.Draw(trngl, Color::Green(), true, Color::Green());
    screen.Draw(rect, Color::Blue(), true, Color::Blue());
    screen.Draw(circle, Color(0, 255, 0, 0), true, Color(0, 255, 0, 0));

    
    screen.SwapScreens();

    

    

    

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

    




    return 0;
}


