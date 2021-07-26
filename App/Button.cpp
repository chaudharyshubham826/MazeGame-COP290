#include "Button.h"
#include "Screen.h"
#include <iostream>

Button::Button(const BitmapFont& bitmapFont, const Color& textColor, const Color& highlightColor):
	aBitmapFont(bitmapFont), aTitle(""), aTextColor(textColor), aHighlightColor(highlightColor), aAction(nullptr), aHighlighted(false)
{

}

void Button::Init(Vec2D topLeft, unsigned int width, unsigned height)
{
	aBBox = AARectangle(topLeft, width, height);
}

void Button::Draw(Screen& theScreen)
{
	theScreen.Draw(aBitmapFont, aTitle, aBitmapFont.GetDrawPosition(aTitle, aBBox, BFXA_CENTER, BFYA_CENTER), aTextColor);

	if(aHighlighted)
	{
		theScreen.Draw(aBBox, aHighlightColor);
	}
}

void Button::ExecuteAction()
{
	aAction();
}