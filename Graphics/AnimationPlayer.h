#ifndef GRAPHICS_ANIMATIONPLAYER_H_
#define GRAPHICS_ANIMATIONPLAYER_H_


#include "Animation.h"
#include <stdint.h>
#include <vector>
#include <string>

class AnimationPlayer
{
public:

	AnimationPlayer();
	bool Init(const std::string& animationsPath);
	bool Play(const std::string& animationName, bool looped);
	void Pause();
	void Stop();
	void Update(uint32_t dt);
	AnimationFrame GetCurrentAnimationFrame() const;

	inline bool IsFinishedPlaying() const {return aIsFinishedPlaying;}
	inline uint32_t GetCurrentFrameNumber() const {return aFrame;}

private:
	uint32_t aTime;
	std::vector<Animation> aAnimations;
	size_t aCurrentAnimation;
	uint32_t aFrame;

	bool aLooped;
	bool aIsPlaying;
	bool aIsFinishedPlaying;
};




#endif