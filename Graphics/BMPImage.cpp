#include "BMPImage.h"
#include <SDL2/SDL.h>

BMPImage::BMPImage():aWidth(0), aHeight(0)
{

}

bool BMPImage::Load(const std::string& path)
{
	SDL_Surface * bmpSurface = SDL_LoadBMP(path.c_str());

	if(bmpSurface == nullptr)
	{
		return false;
	}

	aWidth = bmpSurface->w;
	aHeight = bmpSurface->h;

	uint32_t noOfPixels = aWidth * aHeight;

	aPixels.reserve(noOfPixels);

	SDL_LockSurface(bmpSurface);

	uint32_t * pixels = static_cast<uint32_t*>(bmpSurface->pixels);

	for(uint32_t i = 0; i < noOfPixels; ++i)
	{
		aPixels.push_back(Color(pixels[i]));
	}
	SDL_UnlockSurface(bmpSurface);
	SDL_FreeSurface(bmpSurface);

	return true;
}
