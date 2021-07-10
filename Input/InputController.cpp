#include "InputController.h"
#include <SDL2/SDL.h>
#include "GameController.h"

InputController::InputController(): aQuit(nullptr), aCurrentController(nullptr)
{

}

void InputController::Init(InputAction quitAction)
{
	aQuit = quitAction;
}

void InputController::Update(uint32_t dt)
{
	SDL_Event sdlEvent;

	while(SDL_PollEvent(&sdlEvent))
	{
		switch(sdlEvent.type)
		{
		case SDL_QUIT:
		{
			aQuit(dt, SDL_PRESSED);
		}
		break;
		case SDL_MOUSEMOTION:
		{
			if(aCurrentController)
			{
				if(MouseMovedAction mouseMoved = aCurrentController->GetMouseMovedAction())
				{
					MousePosition position;
					position.xPos = sdlEvent.motion.x;
					position.yPos = sdlEvent.motion.y;
					mouseMoved(position);
				}
			}
			break;
		}
		case SDL_MOUSEBUTTONUP:
		case SDL_MOUSEBUTTONDOWN:
			if(aCurrentController)
			{
				MouseInputAction action = aCurrentController->GetMouseButtonActionForMouseButton(static_cast<MouseButton>(sdlEvent.button.button));

				MousePosition position;
				position.xPos = sdlEvent.button.x;
				position.yPos = sdlEvent.button.y;

				action(static_cast<InputState>(sdlEvent.button.state), position);
			}
			break;
		case SDL_KEYDOWN:
		case SDL_KEYUP:

			if(aCurrentController)
			{
				InputAction action = aCurrentController->GetActionForKey(sdlEvent.key.keysym.sym);

				action(dt, static_cast<InputState>(sdlEvent.key.state));
			}
			break;
		}
	}
}

void InputController::SetGameController(GameController* controller)
{
	aCurrentController = controller;
}