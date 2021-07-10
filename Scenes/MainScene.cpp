#include "MainScene.h"
#include "Screen.h"
#include "Line2D.h"
#include "Triangle.h"
#include "AARectangle.h"
#include "Circle.h"
#include "Color.h"
#include "GameController.h"
#include <iostream>

MainScene::MainScene()
{

}

void MainScene::Init()
{
    ButtonAction action;
    action.key = GameController::ActionKey();
    action.action = [](uint32_t dt, InputState state)
    {
        if(GameController::IsPressed(state))
        {
            std::cout << "Action button was pressed!" << std::endl;
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
		std::cout << "Mouse position x: " << mousePosition.xPos << ", y: " << mousePosition.yPos << std::endl;
	});
}

void MainScene::Update(uint32_t dt)
{

}
void MainScene::Draw(Screen& screen)
{
    Line2D line = {Vec2D(0, 0), Vec2D(screen.Width(), screen.Height())};
    Triangle trngl = {Vec2D(60, 10), Vec2D(10, 60), Vec2D(110, 60)};
    AARectangle rect = {Vec2D(10, 70), Vec2D(120, 120)};
    Circle circle = {Vec2D(150, 150), 50.0f};

    screen.Draw(trngl, Color::Green(), true, Color::Green());
    screen.Draw(rect, Color::Blue(), true, Color::Blue());
    screen.Draw(circle, Color(0, 255, 0, 0), true, Color(0, 255, 0, 0));
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