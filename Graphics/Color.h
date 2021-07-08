#ifndef GRAPHICS_COLOR_H
#define GRAPHICS_COLOR_H

#include <stdint.h>
struct SDL_PixelFormat;

class Color
{
    uint32_t aColor;

public:
    static const SDL_PixelFormat* aFormat;
    static void InitColorFormat(const SDL_PixelFormat* format);

    static Color AlphaBlending(const Color& source, const Color& dest);

    static Color White() {return Color(255, 255, 255, 255);}
    static Color Black() {return Color(0, 0, 0, 255);}
    static Color Red() {return Color(255, 0, 0, 255);}
    static Color Green() {return Color(0, 255, 0, 255);}
    static Color Blue() {return Color(0, 0, 255, 255);}
    static Color Yellow() {return Color(255, 255, 0, 255);}
    static Color Magenta() {return Color(255, 0, 255, 255);}

    Color(): Color(0) {}
    Color(int32_t color): aColor(color) {}
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

    inline bool operator==(const Color& c) {return c.aColor == aColor;}
    inline bool operator!=(const Color& c) {return !(*this == c);}
    uint32_t GetPixelColor() const {return aColor;}

    void SetRGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

    void SetRed(uint8_t r);
    void SetGreen(uint8_t g);
    void SetBlue(uint8_t b);
    void SetAlpha(uint8_t a);

    uint8_t GetRed() const;
    uint8_t GetGreen() const;
    uint8_t GetBlue() const;
    uint8_t GetAlpha() const;


};



#endif