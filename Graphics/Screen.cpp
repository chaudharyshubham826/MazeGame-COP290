#include "Screen.h"
#include "Vec2D.h"
#include "SDL2/SDL.h"
#include "Line2D.h"
#include "Triangle.h"
#include "AARectangle.h"
#include "Circle.h"
#include "Utils.h"
#include "BMPImage.h"
#include "SpriteSheet.h"
#include "BitmapFont.h"

#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

Screen::Screen(): aWidth(0), aHeight(0), aWindow(nullptr), aSurface(nullptr) {}

Screen::~Screen()
{
    if(aWindow){
        SDL_DestroyWindow(aWindow);
        aWindow = nullptr;
    }

    SDL_Quit();
}

SDL_Window* Screen::Init(uint32_t w, uint32_t h, uint32_t mag)
{
    if(SDL_Init(SDL_INIT_VIDEO)){
        cout << "SDL_Init failed!" << endl;

        return nullptr;
    }

    aWidth = w;
    aHeight = h;

    aWindow = SDL_CreateWindow("Games", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, aWidth*mag, aHeight*mag, 0);

    if(aWindow){
        // cout << "Window creation failed! Error: " << SDL_GetError() << endl;
        // return 1;

        aSurface = SDL_GetWindowSurface(aWindow);

        SDL_PixelFormat* format = aSurface->format;
        // cout << SDL_GetPixelFormatName(format->format)<<endl;
        Color::InitColorFormat(format);

        aClearColor = Color::Black();

        aBackBuffer.Init(format->format, aWidth, aHeight);

        aBackBuffer.Clear(aClearColor);
    }

    return aWindow;    
}

void Screen::SwapScreens()
{
    assert(aWindow);
    if(aWindow){
        ClearScreen();

        SDL_BlitScaled(aBackBuffer.GetSurface(), nullptr, aSurface, nullptr);

        SDL_UpdateWindowSurface(aWindow);

        aBackBuffer.Clear(aClearColor);
    }
}

void Screen::Draw(int x, int y, const Color& color)
{
    assert(aWindow);
    if(aWindow){
        aBackBuffer.SetPixel(color, x, y);
    }
}

void Screen::Draw(const Vec2D& vec, const Color& color)
{
    assert(aWindow);
    if(aWindow){
        aBackBuffer.SetPixel(color, vec.GetX(), vec.GetY());
    }
}

void Screen::Draw(const Line2D& line, const Color& color)
{
    assert(aWindow);
    if(aWindow){
        int dx, dy;

        int x1 = line.GetPoint1().GetX();
        int y1 = line.GetPoint1().GetY();
        int x2 = line.GetPoint2().GetX();
        int y2 = line.GetPoint2().GetY();

        dx = x2 - x1;
        dy = y2 - y1;

        signed const char ix((dx > 0) - (dx < 0));
        signed const char iy((dy > 0) - (dy < 0));

        dx = abs(dx) * 2;
        dy = abs(dy) * 2;

        Draw(x1, y1, color);

        if( dx >= dy){
            int d = dy - dx/2;

            while(x1 != x2){
                if(d >= 0){
                    d -= dx;
                    y1 += iy;
                }

                d += dy;
                x1 += ix;

                Draw(x1, y1, color);
            }
        }

        else{
            int d = dx - dy/2;

            while(y1 != y2){
                if(d >= 0){
                    d -= dy;
                    x1 += ix;
                }

                d += dx;
                y1 += iy;

                Draw(x1, y1, color);
            }
        }
    }
}

void Screen::Draw(const Triangle& trngl, const Color& color, bool fill, const Color& fillColor)
{
    if(fill)
    {
        PolyFill(trngl.GetPoints(), fillColor);
    }

    Line2D p1p2 = {trngl.GetP1(), trngl.GetP2()};
    Line2D p2p3 = {trngl.GetP2(), trngl.GetP3()};
    Line2D p3p1 = {trngl.GetP3(), trngl.GetP1()};

    Draw(p1p2, color);
    Draw(p2p3, color);
    Draw(p3p1, color);
}

void Screen::Draw(const AARectangle& rect, const Color& color, bool fill, const Color& fillColor)
{
    if(fill)
    {
        PolyFill(rect.GetPoints(), fillColor);
    }

    vector<Vec2D> points = rect.GetPoints();

    Line2D p0p1 = {points[0], points[1]};
    Line2D p1p2 = {points[1], points[2]};
    Line2D p2p3 = {points[2], points[3]};
    Line2D p3p0 = {points[3], points[0]};

    // std::cout<<points[0]<<endl;
    // std::cout<<points[1]<<endl;
    // std::cout<<points[2]<<endl;
    // std::cout<<points[3]<<endl;

    Draw(p0p1, color);
    Draw(p1p2, color);
    Draw(p2p3, color);
    Draw(p3p0, color);
}

void Screen::Draw(const Circle& circle, const Color& color, bool fill, const Color& fillColor)
{
    static int TOTAL_SEGMENTS = 30;

    vector<Vec2D> circlePoints;
    vector<Line2D> lines;

    float angle =  TWO_PI / float(TOTAL_SEGMENTS);

    Vec2D p1 = Vec2D(circle.GetCenterPoint().GetX() + circle.GetRadius(), circle.GetCenterPoint().GetY());
    Vec2D p2 = p1;
    Line2D nextLine;

    for(int i = 0; i < TOTAL_SEGMENTS; i++)
    {
        p2.Rotate(angle, circle.GetCenterPoint());

        nextLine.SetPoint1(p1);
        nextLine.SetPoint2(p2);

        lines.push_back(nextLine);
        //Draw(nextLine, color);
        // cout<<p1<<", "<<p2<<endl;
        p1 = p2;
        circlePoints.push_back(p1);
    }

    // Draw(circle.GetCenterPoint(), color);

    if(fill)
    {
        PolyFill(circlePoints, fillColor);
    }

    for(const Line2D& line : lines)
    {
        Draw(line,color);
    }
}

void Screen::Draw(const BMPImage& image, const Sprite& sprite, const Vec2D& position, const Color& color)
{
    float rVal = static_cast<float>(color.GetRed()) / 255.0f;
	float gVal = static_cast<float>(color.GetGreen()) / 255.0f;
	float bVal = static_cast<float>(color.GetBlue()) / 255.0f;
	float aVal = static_cast<float>(color.GetAlpha()) / 255.0f;

    uint32_t width = sprite.width;
    uint32_t height = sprite.height;

    for(int r = 0; r < height; r++){
        for(int c = 0; c < width; c++){

            Color imageColor = image.GetPixels()[GetIndex(image.GetWidth(), r + sprite.yPos, c + sprite.xPos)];

		    Color newColor = {static_cast<uint8_t>( imageColor.GetRed() * rVal), static_cast<uint8_t>(imageColor.GetGreen() * gVal), static_cast<uint8_t>(imageColor.GetBlue() * bVal), static_cast<uint8_t>(imageColor.GetAlpha() * aVal)};

            Draw(position.GetX() + c, position.GetY() + r, newColor);
        }
    }
}

void Screen::Draw(const SpriteSheet& ss, const std::string& spriteName, const Vec2D& pos, const Color& color)
{
    Draw(ss.GetBMPImage(), ss.GetSprite(spriteName), pos, color);
}

void Screen::Draw(const BitmapFont& font, const std::string& textLine, const Vec2D& pos, const Color& color)
{
    uint32_t xPos = pos.GetX();

	const SpriteSheet& ss = font.GetSpriteSheet();

	for(char c : textLine)
	{
		if(c == ' ')
		{
			xPos += font.GetFontSpacingBetweenWords();
			continue;
		}

		Sprite sprite = ss.GetSprite(std::string("") + c);

		Draw(ss.GetBMPImage(), sprite, Vec2D(xPos, pos.GetY()), color);

		xPos += sprite.width;

		xPos += font.GetFontSpacingBetweenLetters();
	}
}

void Screen::ClearScreen()
{
    assert(aWindow);
    if(aWindow){
        SDL_FillRect(aSurface, nullptr, aClearColor.GetPixelColor());
    }
}

void Screen::PolyFill(const vector<Vec2D>& points, const Color& color)
{
	if(points.size() > 0)
	{
		float top = points[0].GetY();
		float bottom = points[0].GetY();
		float right = points[0].GetX();
		float left = points[0].GetX();

		for(int i = 1; i < points.size(); i++)
		{
			if(points[i].GetY() < top)
			{
				top = points[i].GetY();
			}

			if(points[i].GetY() > bottom)
			{
				bottom = points[i].GetY();
			}

			if(points[i].GetX() < left)
			{
				left = points[i].GetX();
			}

			if(points[i].GetX() > right)
			{
				right = points[i].GetX();
			}
		}


		for(int pixelY = top; pixelY < bottom; ++pixelY)
		{
			vector<float> nodeXVec;

			size_t j = points.size() -1;

			for(size_t i = 0; i < points.size(); ++i)
			{
				float pointiY = points[i].GetY();
				float pointjY = points[j].GetY();


				if((pointiY <= (float)pixelY && pointjY > (float)pixelY) || (pointjY <= (float)pixelY && pointiY > (float)pixelY))
				{
					float denom = pointjY - pointiY;
					if(IsEqual(denom, 0))
					{
						continue;
					}

					float x = points[i].GetX() + (pixelY - pointiY)/(denom) * (points[j].GetX() - points[i].GetX());
					nodeXVec.push_back(x);
				}

				j = i;
			}

			sort(nodeXVec.begin(), nodeXVec.end(), std::less<>());

			for(size_t k = 0; k < nodeXVec.size(); k+=2)
			{
				if(nodeXVec[k] > right)
				{
					break;
				}

				if(nodeXVec[k+1] > left)
				{
					if(nodeXVec[k] < left)
					{
						nodeXVec[k] = left;
					}
					if(nodeXVec[k+1] > right)
					{
						nodeXVec[k+1] = right;
					}

					//Line2D line = {Vec2D(nodeXVec[k], pixelY), Vec2D(nodeXVec[k+1], pixelY)};
					//Draw(line, color);
					for(int pixelX = nodeXVec[k]; pixelX < nodeXVec[k+1]; ++pixelX)
					{
						Draw(pixelX, pixelY, color);
					}
				}
			}
		}
	}
}