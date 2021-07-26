#include "ButtonOptionsScene.h"
#include "App.h"
#include "BitmapFont.h"
#include "Utils.h"
#include <iostream>

ButtonOptionsScene::ButtonOptionsScene(const std::vector<std::string>& optionNames, const Color& textColor):
	aHighlightedOption(0)
{
	const BitmapFont & font = App::Singleton().GetFont();

	for(size_t i = 0; i < optionNames.size(); ++i)
	{
		Button b = {font, textColor};
		aButtons.push_back(b);
		aButtons.back().SetButtonText(optionNames[i]);
	}

	if(optionNames.size() > 0)
	{
		aButtons[aHighlightedOption].SetHighlighted(true);
	}
}

void ButtonOptionsScene::Init()
{
	ButtonAction upAction;
	upAction.key = GameController::UpKey();
	upAction.action = [this](uint32_t dt, InputState state)
		{
			if(GameController::IsPressed(state))
			{
				SetPreviousButtonHighlighted();
			}
		};

	aGameController.AddInputActionForKey(upAction);


	ButtonAction downAction;
	downAction.key = GameController::DownKey();
	downAction.action = [this](uint32_t dt, InputState state)
		{
			if(GameController::IsPressed(state))
			{
				SetNextButtonHighlighted();
			}
		};

	aGameController.AddInputActionForKey(downAction);

	ButtonAction acceptAction;
	acceptAction.key = GameController::ActionKey();
	acceptAction.action = [this](uint32_t dt, InputState state)
		{
			if(GameController::IsPressed(state))
			{
				ExecuteCurrentButtonAction();
			}
		};

	aGameController.AddInputActionForKey(acceptAction);


	uint32_t height = App::Singleton().Height();
	uint32_t width = App::Singleton().Width();

	const BitmapFont& font = App::Singleton().GetFont();

	Size fontSize = font.GetSizeOf(aButtons[0].GetButtonText());

	const int BUTTON_PAD = 10;

	unsigned int buttonHeight = fontSize.height + BUTTON_PAD * 2;

	uint32_t maxButtonWidth = fontSize.width;

	for(const auto & button: aButtons)
	{
		Size s = font.GetSizeOf(button.GetButtonText());

		if(s.width > maxButtonWidth)
		{
			maxButtonWidth = s.width;
		}
	}

	maxButtonWidth += BUTTON_PAD * 2;

	const uint32_t Y_PAD = 1;

	uint32_t yOffset = height/2 - ((buttonHeight+Y_PAD) * static_cast<uint32_t>(aButtons.size()))/2;

	for(auto& button : aButtons)
	{
		button.Init(Vec2D(width/2 - maxButtonWidth/2, yOffset), maxButtonWidth, buttonHeight);

		yOffset += buttonHeight + Y_PAD;
	}

	aButtons[aHighlightedOption].SetHighlighted(true);
}

void ButtonOptionsScene::Update(uint32_t dt)
{

}

void ButtonOptionsScene::Draw(Screen& theScreen)
{
	for(auto& button: aButtons)
	{
		button.Draw(theScreen);
	}
}

void ButtonOptionsScene::SetButtonActions(const std::vector<Button::ButtonAction>& buttonActions)
{
	for(size_t i = 0; i < aButtons.size(); ++i)
	{
		aButtons[i].SetButtonAction(buttonActions[i]);
	}
}

void ButtonOptionsScene::SetNextButtonHighlighted()
{
	aHighlightedOption = (aHighlightedOption + 1)% aButtons.size();

	HighlightCurrentButton();
}

void ButtonOptionsScene::SetPreviousButtonHighlighted()
{
	--aHighlightedOption;

	if(aHighlightedOption < 0)
	{
		aHighlightedOption = static_cast<int>(aButtons.size()) - 1;
	}

	HighlightCurrentButton();
}

void ButtonOptionsScene::ExecuteCurrentButtonAction()
{
	aButtons[aHighlightedOption].ExecuteAction();
}

void ButtonOptionsScene::HighlightCurrentButton()
{
	for(auto& button: aButtons)
	{
		button.SetHighlighted(false);
	}

	aButtons[aHighlightedOption].SetHighlighted(true);
}