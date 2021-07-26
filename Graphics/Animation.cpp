#include "Animation.h"
#include "FileCommandLoader.h"
#include <cassert>

Animation::Animation(): aSize(Vec2D::Zero), aSpriteSheetName(""), aAnimationName(""), aFPS(0)
{

}

AnimationFrame Animation::GetAnimationFrame(uint32_t frameNum) const
{
	AnimationFrame frame;

	if(frameNum > aFrames.size())
	{
		return frame;
	}

	frame.frame = aFrames[frameNum];

	if(frameNum < aFrameColors.size())
	{
		frame.frameColor = aFrameColors[frameNum];
		frame.frameColorSet = 1;
	}

	if(aOverlay.size() > 0)
	{
		frame.overlay = aOverlay;
	}

	if(frameNum < aOverlayColors.size())
	{
		frame.overlayColor = aOverlayColors[frameNum];
	}

	if(frameNum < aFrameOffsets.size())
	{
		frame.offset = aFrameOffsets[frameNum];
	}

	frame.size = aSize;

	return frame;
}

std::vector<Animation> Animation::LoadAnimations(const std::string& animationFilePath)
{
	std::vector<Animation> animations;

	FileCommandLoader fileLoader;

	Command animationCommand;
	animationCommand.command = "animation";
	animationCommand.parseFunc = [&](ParseFuncParams params)
	{
		Animation newAnimation;
		newAnimation.SetName(FileCommandLoader::ReadString(params));
		animations.push_back(newAnimation);
	};

	fileLoader.AddCommand(animationCommand);

	Command spriteSheetCommand;
	spriteSheetCommand.command = "sprite_sheet";
	spriteSheetCommand.parseFunc = [&](ParseFuncParams params)
	{
		animations.back().SetSpriteSheetName(FileCommandLoader::ReadString(params));
	};

	fileLoader.AddCommand(spriteSheetCommand);


	Command sizeCommand;
	sizeCommand.command = "size";
	sizeCommand.parseFunc = [&](ParseFuncParams params)
	{
		animations.back().SetSize(FileCommandLoader::ReadSize(params));
	};

	fileLoader.AddCommand(sizeCommand);

	Command fpsCommand;
	fpsCommand.command = "fps";
	fpsCommand.parseFunc = [&](ParseFuncParams params)
	{
		animations.back().SetFPS(FileCommandLoader::ReadInt(params));
	};

	fileLoader.AddCommand(fpsCommand);

	Command framesCommand;
	framesCommand.command = "frame_keys";
	framesCommand.commandType = COMMAND_MULTI_LINE;
	framesCommand.parseFunc = [&](ParseFuncParams params)
	{
		animations.back().AddFrame(params.line);
	};

	fileLoader.AddCommand(framesCommand);

	Command overlayCommand;
	overlayCommand.command = "overlay";
	overlayCommand.parseFunc = [&](ParseFuncParams params)
	{
		animations.back().SetOverlay(FileCommandLoader::ReadString(params));
	};

	fileLoader.AddCommand(overlayCommand);

	Command frameColorsCommand;
	frameColorsCommand.command = "frame_colors";
	frameColorsCommand.commandType = COMMAND_MULTI_LINE;
	frameColorsCommand.parseFunc = [&](ParseFuncParams params)
	{
		animations.back().AddFrameColor(FileCommandLoader::ReadColor(params));
	};

	fileLoader.AddCommand(frameColorsCommand);


	Command overlayFrameColorCommand;
	overlayFrameColorCommand.command = "overlay_colors";
	overlayFrameColorCommand.commandType = COMMAND_MULTI_LINE;
	overlayFrameColorCommand.parseFunc = [&](ParseFuncParams params)
	{
		animations.back().AddOverlayFrameColor(FileCommandLoader::ReadColor(params));
	};

	fileLoader.AddCommand(overlayFrameColorCommand);

	Command frameOffsetsCommand;
	frameOffsetsCommand.command = "frame_offsets";
	frameOffsetsCommand.commandType = COMMAND_MULTI_LINE;
	frameOffsetsCommand.parseFunc = [&](ParseFuncParams params)
	{
		animations.back().AddFrameOffset(FileCommandLoader::ReadSize(params));
	};

	fileLoader.AddCommand(frameOffsetsCommand);

	assert(fileLoader.LoadFile(animationFilePath));

	return animations;
}