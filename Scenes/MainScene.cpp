#include "MainScene.h"
#include "Screen.h"
#include "Line2D.h"
#include "Triangle.h"
#include "AARectangle.h"
#include "Circle.h"
#include "Color.h"
#include "GameController.h"
#include "App.h"

#include "NotImplementedScene.h"
#include "PacmanStartScene.h"

// #include ""

#include <iostream>

using namespace std;

MainScene::MainScene(): ButtonOptionsScene({"Tetris", "Pac-man"}, Color::Yellow())
{

}

void MainScene::Init()
{
    
    std::vector<Button::ButtonAction> actions;

	actions.push_back([this]{
		App::Singleton().PushScene(GetScene(TETRIS));
	});

	actions.push_back([this]{
		App::Singleton().PushScene(GetScene(PACMAN));
	});

	SetButtonActions(actions);

	ButtonOptionsScene::Init();

    // temp
    
}

void MainScene::Update(uint32_t dt)
{
    
}
void MainScene::Draw(Screen& screen)
{
    ButtonOptionsScene::Draw(screen);

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
            return std::make_unique<PacmanStartScene>();
        }
        break;
    }

    std::unique_ptr<Scene> notImplementedScene = std::make_unique<NotImplementedScene>();

	return notImplementedScene;
}