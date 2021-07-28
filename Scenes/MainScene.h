#ifndef SCENES_MAINSCENE_H_
#define SCENES_MAINSCENE_H_

#include "ButtonOptionsScene.h"
#include <memory>

enum eGame
{
    TETRIS = 0,
    PACMAN,
    NUM_GAMES
};

class Screen;

class MainScene: public ButtonOptionsScene
{
public:
    MainScene();
    virtual void Init() override;
    virtual void Update(uint32_t dt) override;
    virtual void Draw(Screen& screen) override;
    virtual const std::string& GetSceneName() const override;

private:
    std::unique_ptr<Scene> GetScene(eGame game);
};


#endif