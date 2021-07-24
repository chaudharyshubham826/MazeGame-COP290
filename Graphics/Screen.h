#ifndef GRAPHICS_SCREEN_H
#define GRAPHICS_SCREEN_H

#include <stdint.h>
#include <vector>
#include "ScreenBuffer.h"
#include "Color.h"
#include <string>

class Vec2D;
class Line2D;
class Triangle;
class AARectangle;
class Circle;
class BMPImage;
struct SDL_Window;
struct SDL_Surface;
class SpriteSheet;
class Sprite;
class BitmapFont;


class Screen{
public:
    Screen();
    ~Screen();

    SDL_Window* Init(uint32_t w, uint32_t h, uint32_t mag);
    void SwapScreens();

    inline void SetClearColor(const Color& color) {aClearColor = color;}
    inline uint32_t Width() const {return aWidth;}
    inline uint32_t Height() const {return aHeight;}



    void Draw(int x, int y, const Color& color);
    void Draw(const Vec2D& vec, const Color& color);
    void Draw(const Line2D& line, const Color& color);
    void Draw(const Triangle& trngl, const Color& color, bool fill = false, const Color& fillColor = Color::White());
    void Draw(const AARectangle& rect, const Color& color, bool fill = false, const Color& fillColor = Color::White());
    void Draw(const Circle& circle, const Color& color, bool fill = false, const Color& fillColor = Color::White());

    void Draw(const BMPImage& image, const Sprite& sprite, const Vec2D& position, const Color& color = Color::White());
    void Draw(const SpriteSheet& ss, const std::string& spriteName, const Vec2D& pos, const Color& color = Color::White());
    void Draw(const BitmapFont& font, const std::string& textLine, const Vec2D& pos, const Color& color = Color::White());
        

private:
    Screen(const Screen& screen);
    Screen& operator=(const Screen& screen);

    void ClearScreen();
    void PolyFill(const std::vector<Vec2D>& points, const Color& color);

    uint32_t aWidth;
    uint32_t aHeight;

    Color aClearColor;
    ScreenBuffer aBackBuffer;

    SDL_Window* aWindow;
    SDL_Surface* aSurface;

};


#endif