#ifndef APP_BUTTON_H_
#define APP_BUTTON_H_

#include <string>
#include "AARectangle.h"
#include <functional>
#include "Color.h"

#include "BitmapFont.h"


class Screen;

class Button
{
public:
	using ButtonAction = std::function<void(void)>;

	Button(const BitmapFont& bitmapFont, const Color& textColor, const Color& highlightColor = Color::White());
	void Init(Vec2D topLeft, unsigned int width, unsigned height);
	void Draw(Screen& theScreen);
	void ExecuteAction();

	inline void SetButtonText(const std::string& text) {aTitle = text;}
	inline const std::string& GetButtonText() const {return aTitle;}
	inline void SetHighlighted(bool highlighted) {aHighlighted = highlighted;}
	inline bool IsHighlighted() const {return aHighlighted;}
	inline void SetButtonAction(Button::ButtonAction action) {aAction = action;}

private:
	const BitmapFont& aBitmapFont;
	std::string aTitle;
	AARectangle aBBox;
	Color aTextColor;
	Color aHighlightColor;
	ButtonAction aAction;
	bool aHighlighted;
};



#endif