#ifndef GRAPHICS_ANIMATION_H_
#define GRAPHICS_ANIMATION_H_

#include "Vec2D.h"
#include "Color.h"
#include <string>
#include <vector>

struct AnimationFrame
{
	std::string frame = "";
	std::string overlay = "";
	Color frameColor = Color::White();
	Color overlayColor = Color::White();
	Vec2D size;
	Vec2D offset = Vec2D::Zero;
	int frameColorSet = 0;
};

class Animation
{
public:
	Animation();

	AnimationFrame GetAnimationFrame(uint32_t frameNum) const;

	void AddFrame(const std::string& frame) {aFrames.push_back(frame);}
	void AddFrameColor(const Color& color) {aFrameColors.push_back(color);}
	void AddOverlayFrameColor(const Color& color) {aOverlayColors.push_back(color);}
	void AddFrameOffset(const Vec2D& offset) {aFrameOffsets.push_back(offset);}

	void SetSpriteSheetName(const std::string& spriteSheetName) {aSpriteSheetName = spriteSheetName;}
	const std::string& GetSpriteSheetName() const {return aSpriteSheetName;}

	void SetName(const std::string& animationName) {aAnimationName = animationName;}
	const std::string& GetName() const {return aAnimationName;}

	Vec2D Size() const {return aSize;}

	void SetSize(const Vec2D & size) {aSize = size;}

	void SetFPS(int fps) {aFPS = fps;}
	int FPS() const {return aFPS;}

	void SetOverlay(const std::string& overlayName) {aOverlay = overlayName;}
	const std::string& OverlayName() const {return aOverlay;}

	size_t NumFrames() const {return aFrames.size();}
	size_t NumFrameColors() const {return aFrameColors.size();}
	size_t NumOverlayColors() const {return aOverlayColors.size();}
	size_t NumFrameOffsets() const {return aFrameOffsets.size();}

	static std::vector<Animation> LoadAnimations(const std::string& animationFilePath);

private:
	std::string aAnimationName;
	std::string aSpriteSheetName;
	std::string aOverlay;
	std::vector<std::string> aFrames;
	std::vector<Color> aFrameColors;
	std::vector<Color> aOverlayColors;
	std::vector<Vec2D> aFrameOffsets;
	Vec2D aSize;
	int aFPS;
};

#endif