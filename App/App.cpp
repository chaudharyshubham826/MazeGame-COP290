#include "App.h"
#include <SDL2/SDL.h>
#include "iostream"
#include "MainScene.h"
#include <cassert>
#include "GameScene.h"

using namespace std;


App& App::Singleton()
{
    static App app;
    return app;
}

bool App::Init(uint32_t width, uint32_t height, uint32_t mag)
{
    if(!aFont.Load("MainFont"))
    {
        cout << "Could not load Main Font!" << endl;
        return false;
    }

    aWindow = aScreen.Init(width, height, mag);

    std::unique_ptr<MainScene> mainScene = std::make_unique<MainScene>();

    PushScene(std::move(mainScene));

    return aWindow != nullptr;
}

void App::Run()
{
    if(aWindow){
        
        // screen.Draw(line, Color::White());

        bool running = true;

        uint32_t lastTick = SDL_GetTicks();
        uint32_t currentTick = lastTick;

        uint32_t dt = 10;
        uint32_t accumulator = 0;

        aInputController.Init([&running](uint32_t dt, InputState state){
            running = false;
        });

        while(running)
        {

            currentTick = SDL_GetTicks();
            uint32_t frameTime = currentTick - lastTick;

            if(frameTime > 300){
                frameTime = 300;
            }

            lastTick = currentTick;

            accumulator += frameTime;

            // Input
            aInputController.Update(dt);

            Scene* topScene = App::TopScene();
            assert(topScene && "where is the scene? what the heck did u do?");
            if(topScene){
                // Update state
                while(accumulator >= dt)
                {
                    // update current scene by dt
                    topScene->Update(dt);
                    // cout << "Delta time step: " <<dt << endl;
                    accumulator -= dt;
                }

                // Render
                topScene->Draw(aScreen);
            }

            
            

            

            aScreen.SwapScreens();
            
        }
    }
    
}

void App::PushScene(std::unique_ptr<Scene> scene)
{
    assert(scene && "don't push nullptr");
    if(scene){
        scene->Init();
        aInputController.SetGameController(scene->GetGameController());
        aSceneStack.emplace_back(std::move(scene));////////////L value R value
        SDL_SetWindowTitle(aWindow, TopScene()->GetSceneName().c_str());
    }
}

void App::PopScene()
{
    if(aSceneStack.size() >= 1)/////////////
    {
        aSceneStack.pop_back();
    }

    if(TopScene())
    {
        aInputController.SetGameController(TopScene()->GetGameController());
        SDL_SetWindowTitle(aWindow, TopScene()->GetSceneName().c_str());
    }
}

Scene* App::TopScene()
{
    if(aSceneStack.empty()){
        return nullptr;
    }

    return aSceneStack.back().get();
}

const std::string& App::GetBasePath()
{
	static std::string basePath = SDL_GetBasePath();
    cout << basePath << endl;

	return basePath;
}