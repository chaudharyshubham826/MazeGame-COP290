#ifndef APP_APP_H
#define APP_APP_H

#include "Screen.h"
#include <stdint.h>

struct SDL_Window;

class App
{
public:
    static App& Singleton();
    bool Init(uint32_t width, uint32_t height, uint32_t mag);
    void Run();

    inline uint32_t Width() const {return aScreen.Width();}
    inline uint32_t Height() const {return aScreen.Height();}

private:
    Screen aScreen;
    SDL_Window* aWindow;
};


#endif