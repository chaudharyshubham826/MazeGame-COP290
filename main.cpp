#include <iostream>

#include "App.h"

using namespace std;

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;
const int MAGNIFICATION = 3;


int main(int argc, char* argv[])
{
    if(App::Singleton().Init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION))
    {
        App::Singleton().Run();
    }

    //screen.Draw(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, Color::Red());
    return 0;
}


