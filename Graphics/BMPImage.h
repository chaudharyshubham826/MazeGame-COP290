#ifndef GRAPHICS_BMPIMAGE_H_
#define GRAPHICS_BMPIMAGE_H_

#include "Color.h"
#include <vector>
#include <string>
#include <stdint.h>


class BMPImage
{
public:

	BMPImage();
	bool Load(const std::string& path);

	inline const std::vector<Color>& GetPixels() const {return aPixels;}
	inline uint32_t GetWidth() const {return aWidth;}
	inline uint32_t GetHeight() const {return aHeight;}

private:

	std::vector<Color> aPixels;
	uint32_t aWidth;
	uint32_t aHeight;
};



#endif