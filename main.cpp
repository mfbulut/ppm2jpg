#define _CRT_SECURE_NO_WARNINGS
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

#include <iostream>

int main(int argc, char* argv[])
{
	char inputName[64];
	char outputName[64];

	if (argc > 1)
	{
		std::strcpy(inputName, argv[1]);
		if (argc > 2)
		{
			std::strcpy(outputName, argv[2]);
		}
		else
		{
			std::strcpy(outputName, "output.jpg");
		}
	}
	else
	{
		std::cout << "Usage: ppm2jpg (Input File Name) (Optional:Output File Name) (Optional:OpenFile?)" << std::endl;
		return 1;
	}


	int width, height, original_no_channels;
	int desired_no_channels = 3;
	unsigned char* pixels = stbi_load(inputName, &width, &height, &original_no_channels, desired_no_channels);
	if (pixels == NULL) {
		std::cout << "Error in loading the image" << std::endl;
		return 1;
	}

	stbi_write_jpg(outputName, width, height, desired_no_channels, pixels, 100);

	delete[] pixels;

	if (argc > 3)
	{
		char cmd[] = "start ";
		char* newArray = new char[std::strlen(cmd) + std::strlen(outputName) + 1];
		std::strcpy(newArray, cmd);
		std::strcat(newArray, outputName);
		system(newArray);
		delete[] newArray;
	}
	return 0;
}