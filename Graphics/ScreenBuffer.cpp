#include "ScreenBuffer.h"
#include <SDL2/SDL.h>
#include <cassert>

ScreenBuffer::ScreenBuffer(): aSurface(nullptr) {}
ScreenBuffer::ScreenBuffer(const ScreenBuffer& sb)
{
    aSurface = SDL_CreateRGBSurfaceWithFormat(0,sb.aSurface->w, sb.aSurface->h, 0, sb.aSurface->format->format);
    SDL_BlitSurface(sb.aSurface, nullptr, aSurface, nullptr);
}

ScreenBuffer::~ScreenBuffer()
{
    if(aSurface){
        SDL_FreeSurface(aSurface);
    }
}

ScreenBuffer& ScreenBuffer::operator=(const ScreenBuffer& sb)
{
    if(this == &sb){
        return *this;
    }

    if(aSurface != nullptr){
        SDL_FreeSurface(aSurface);
        aSurface = nullptr;
    }

    if(sb.aSurface != nullptr){
        aSurface = SDL_CreateRGBSurfaceWithFormat(0,sb.aSurface->w, sb.aSurface->h, 0, sb.aSurface->format->format);
        SDL_BlitSurface(sb.aSurface, nullptr, aSurface, nullptr);
    }

    return *this;
}

void ScreenBuffer::Init(uint32_t format, uint32_t w, int32_t h)
{
    aSurface = SDL_CreateRGBSurfaceWithFormat(0, w, h, 0, format);
    Clear();
}


void ScreenBuffer::Clear(const Color& c)
{
    assert(aSurface);
    if(aSurface){
        SDL_FillRect(aSurface, nullptr, c.GetPixelColor());
    }
}

void ScreenBuffer::SetPixel(const Color& color, int x, int y)
{
    assert(aSurface);

    if(aSurface &&(x >= 0 && y >= 0 && x < aSurface->w && y < aSurface->h)){
        SDL_LockSurface(aSurface);

        size_t i = GetIndex(y, x);

        uint32_t* pixels = (uint32_t*)aSurface->pixels;

        //pixels[i] = color.GetPixelColor();
        Color surfaceCurrentColor = Color(pixels[i]);
        pixels[i] = Color::AlphaBlending(color, surfaceCurrentColor).GetPixelColor();

        SDL_UnlockSurface(aSurface);
    }
}

int32_t ScreenBuffer::GetIndex(int r, int c)
{
    assert(aSurface);
    if(aSurface){
        return r*aSurface->w + c;
    }

    return 0; 
}

