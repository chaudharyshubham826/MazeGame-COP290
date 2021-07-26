#include "AnimationPlayer.h"


AnimationPlayer::AnimationPlayer():aTime(0), aCurrentAnimation(0), aFrame(0), aLooped(false), aIsPlaying(false), aIsFinishedPlaying(false)
{

}

bool AnimationPlayer::Init(const std::string& animationsPath)
{
	aAnimations = Animation::LoadAnimations(animationsPath);
	return aAnimations.size() > 0;
}

bool AnimationPlayer::Play(const std::string& animationName, bool looped)
{
	bool found = false;

	for(size_t i = 0; i < aAnimations.size(); ++i)
	{
		if(aAnimations[i].GetName() == animationName)
		{
			aCurrentAnimation = i;
			found = true;
			break;
		}
	}

	if(found)
	{
		aIsPlaying = true;
		aFrame = 0;
		aTime = 0;
		aLooped = looped;
		aIsFinishedPlaying = false;
	}

	return found;
}

void AnimationPlayer::Pause()
{
	if(aIsFinishedPlaying)
	{
		aIsPlaying = !aIsPlaying;
	}
}

void AnimationPlayer::Stop()
{
	aIsPlaying = false;
	aTime = 0;
	aFrame = 0;
	aIsFinishedPlaying = true;
}

void AnimationPlayer::Update(uint32_t dt)
{
	if(aIsPlaying)
	{
		aTime += dt;

		int fps = aAnimations[aCurrentAnimation].FPS();

		float millisecondsPerFrame = static_cast<float>(1000) / static_cast<float>(fps);

		if(static_cast<float>(aTime) > millisecondsPerFrame)
		{
			aTime -= static_cast<uint32_t>(millisecondsPerFrame);

			if(aFrame + 1 < aAnimations[aCurrentAnimation].NumFrames())
			{
				++aFrame;
			}
			else if((aFrame + 1 >= aAnimations[aCurrentAnimation].NumFrames()) && aLooped)
			{
				aFrame = 0;
			}
			else
			{
				aIsFinishedPlaying = true;
			}
		}
	}
}

AnimationFrame AnimationPlayer::GetCurrentAnimationFrame() const
{
	if(aAnimations.empty())
	{
		return AnimationFrame();
	}

	return aAnimations[aCurrentAnimation].GetAnimationFrame(GetCurrentFrameNumber());
}
