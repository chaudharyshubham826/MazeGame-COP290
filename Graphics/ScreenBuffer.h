#ifndef GRAPHICS_SCREENBUFFER_H
#define GRAPHICS_SCREENBUFFER_H

#include <stdint.h>
#include "Color.h"

struct SDL_Surface;

class ScreenBuffer
{
public:
    ScreenBuffer();
    ScreenBuffer(const ScreenBuffer& sb);
    ~ScreenBuffer();

    ScreenBuffer& operator=(const ScreenBuffer& sb);

    void Init(uint32_t format, uint32_t w, int32_t h);

    inline SDL_Surface* GetSurface() {return aSurface;}

    void Clear(const Color& c = Color::Black());

    void SetPixel(const Color& color, int x, int y);

private:
    SDL_Surface* aSurface;
    int32_t GetIndex(int r, int c);


};


#endif