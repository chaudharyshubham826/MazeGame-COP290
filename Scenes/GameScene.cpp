#include "GameScene.h"

GameScene::GameScene(std::unique_ptr<Game> optrGame):aGame(std::move(optrGame))
{

}

void GameScene::Init()
{
	aGame->Init(aGameController);
}

void GameScene::Update(uint32_t dt)
{
	aGame->Update(dt);
}

void GameScene::Draw(Screen& screen)
{
	aGame->Draw(screen);
}

const std::string& GameScene::GetSceneName() const
{
	static std::string name = "";
	return name;
}
