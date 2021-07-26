#include "AnimatedSprite.h"
#include "AARectangle.h"
#include "Screen.h"

AnimatedSprite::AnimatedSprite():aPosition(Vec2D::Zero), aSpriteSheetPtr(nullptr)
{

}

void AnimatedSprite::Init(const std::string& animationsPath, const SpriteSheet& spriteSheet, const Color& color)
{
	aAnimationPlayer.Init(animationsPath);
	aSpriteSheetPtr = &spriteSheet;
	aColor = color;
}

void AnimatedSprite::Update(uint32_t dt)
{
	aAnimationPlayer.Update(dt);
}

void AnimatedSprite::Draw(Screen& theScreen)
{
	AnimationFrame frame = aAnimationPlayer.GetCurrentAnimationFrame();

	Color frameColor = frame.frameColor;

	if(!frame.frameColorSet)
	{
		frameColor = aColor;
	}

	theScreen.Draw(*aSpriteSheetPtr, frame.frame, aPosition + frame.offset, frameColor);

	if(frame.overlay.size() > 0)
	{
		theScreen.Draw(*aSpriteSheetPtr, frame.overlay, aPosition, frame.overlayColor);
	}
}

void AnimatedSprite::SetAnimation(const std::string& animationName, bool looped)
{
	aAnimationPlayer.Play(animationName, looped);
}

Vec2D AnimatedSprite::Size() const
{
	return aAnimationPlayer.GetCurrentAnimationFrame().size;
}

void AnimatedSprite::Stop()
{
	aAnimationPlayer.Stop();
}

const AARectangle AnimatedSprite::GetBoundingBox() const
{
	AARectangle bbox = {aPosition, static_cast<unsigned int>(Size().GetX()), static_cast<unsigned int>(Size().GetY())};
	return bbox;
}
