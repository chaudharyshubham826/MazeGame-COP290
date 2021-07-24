#include "MainScene.h"
#include "Screen.h"
#include "Line2D.h"
#include "Triangle.h"
#include "AARectangle.h"
#include "Circle.h"
#include "Color.h"
#include "GameController.h"
#include "App.h"

#include <iostream>

using namespace std;

MainScene::MainScene()
{

}

void MainScene::Init()
{
    
    // cout << temp << endl;

    ButtonAction action;
    action.key = GameController::ActionKey();
    action.action = [](uint32_t dt, InputState state)
    {
        if(GameController::IsPressed(state))
        {
            std::cout << "Action button was pressed!" << std::endl;
            std::cout << "it works" << std::endl;
        }
    };

    aGameController.AddInputActionForKey(action);

    MouseButtonAction mouseAction;
    mouseAction.mouseButton = GameController::LeftMouseButton();

    mouseAction.mouseInputAction = [](InputState state, const MousePosition& position)
    {
        if(GameController::IsPressed(state))
        {
            std::cout << "Left mouse button pressed!" <<std::endl;
        }
    };

    aGameController.AddMouseButtonAction(mouseAction);

    aGameController.SetMouseMovedAction([](const MousePosition& mousePosition){
		// std::cout << "Mouse position x: " << mousePosition.xPos << ", y: " << mousePosition.yPos << std::endl;
	});
}

void MainScene::Update(uint32_t dt)
{

}
void MainScene::Draw(Screen& screen)
{
    const BitmapFont& font = App::Singleton().GetFont();

	AARectangle rect = {Vec2D::Zero, App::Singleton().Width(), App::Singleton().Height()};

	Vec2D textDrawPosition;

	textDrawPosition = font.GetDrawPosition(GetSceneName(), rect, BFXA_CENTER, BFYA_CENTER);

	screen.Draw(font, GetSceneName(), textDrawPosition, Color::Blue());
}

const std::string& MainScene::GetSceneName() const
{
    static std::string sceneName = "Games";
    return sceneName;
}

std::unique_ptr<Scene> MainScene::GetScene(eGame game)
{
    switch(game)
    {
        case TETRIS:
        {

        }
        break;
        
        case PACMAN:
        {

        }
        break;
        default:
        {

        }
        break;
    }

    return nullptr;

}