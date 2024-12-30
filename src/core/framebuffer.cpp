#include "framebuffer.h"
#include <fstream>

FrameBuffer::FrameBuffer(const int width, const int height) {
    this->width = width;
    this->height = height;

    this->framebufer = new Pixel[width * height];
};

int FrameBuffer::writeRGB(char* filename) {

    std::ofstream imageFile(filename, std::ios::binary);

    if (imageFile.fail()) {
        return -1;
    }

    float max = 0.0f;
    float min = 0.0f;

    for (int i = 0; i < width * height; i ++) {
        if (framebufer[i].red > max) {max = framebufer[i].red;}
        if (framebufer[i].red < min) {min = framebufer[i].red;}
        if (framebufer[i].green > max) {max = framebufer[i].green;}
        if (framebufer[i].green < min) {min = framebufer[i].green;}
        if (framebufer[i].blue > max) {max = framebufer[i].blue;}
        if (framebufer[i].blue < min) {min = framebufer[i].blue;}
    };

    float diff = max - min;

    if (diff == 0) {diff = 1.0f;}

    imageFile << "P6\n";
    imageFile << width << " " << height << "\n255\n";

    for (int i = 0; i < width*height; i++) {
        imageFile << (unsigned char)(framebufer[i].red * 255.00f);
        imageFile << (unsigned char)(framebufer[i].green * 255.00f);
        imageFile << (unsigned char)(framebufer[i].blue * 255.00f);
    }

    imageFile.close();

    return 0;

};