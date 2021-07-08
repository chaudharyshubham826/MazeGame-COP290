#include "Color.h"
#include <SDL2/SDL.h>


const SDL_PixelFormat* Color::aFormat = nullptr;

void Color::InitColorFormat(const SDL_PixelFormat* format)
{
    aFormat = format;
}

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SetRGBA(r, g, b, a);
}

void Color::SetRGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    aColor = SDL_MapRGBA(aFormat, r, g, b, a);
}

void Color::SetRed(uint8_t r)
{
    uint8_t red;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    SDL_GetRGBA(aColor, aFormat, &red, &g, &b, &a);
    SetRGBA(r, g, b, a);
}

void Color::SetGreen(uint8_t g)
{
    uint8_t r;
    uint8_t green;
    uint8_t b;
    uint8_t a;

    SDL_GetRGBA(aColor, aFormat, &r, &green, &b, &a);
    SetRGBA(r, g, b, a);
}

void Color::SetBlue(uint8_t b)
{
    uint8_t r;
    uint8_t g;
    uint8_t blue;
    uint8_t a;

    SDL_GetRGBA(aColor, aFormat, &r, &g, &blue, &a);
    SetRGBA(r, g, b, a);
}

void Color::SetAlpha(uint8_t a)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t alpha;

    SDL_GetRGBA(aColor, aFormat, &r, &g, &b, &alpha);
    SetRGBA(r, g, b, a);
}

uint8_t Color::GetRed() const
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    SDL_GetRGBA(aColor, aFormat, &r, &g, &b, &a);
    return r;
}

uint8_t Color::GetGreen() const
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    SDL_GetRGBA(aColor, aFormat, &r, &g, &b, &a);
    return g;
}

uint8_t Color::GetBlue() const
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    SDL_GetRGBA(aColor, aFormat, &r, &g, &b, &a);
    return b;
}

uint8_t Color::GetAlpha() const
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    SDL_GetRGBA(aColor, aFormat, &r, &g, &b, &a);
    return a;
}

Color Color::AlphaBlending(const Color& source, const Color& dest)
{
    uint8_t alpha = source.GetAlpha();

    float srcAlpha = float(alpha) / 255.0f;
    float destAlpha = 1.0f - srcAlpha;

    Color output;

    output.SetAlpha(255);
    output.SetRed(float(source.GetRed()*srcAlpha + dest.GetRed()*destAlpha));
    output.SetGreen(float(source.GetGreen()*srcAlpha + dest.GetGreen()*destAlpha));
    output.SetBlue(float(source.GetBlue()*srcAlpha + dest.GetBlue()*destAlpha));

    return output;
}
