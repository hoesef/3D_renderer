#include <iostream>
#include <fstream>

#include "core\framebuffer.h"

int main() {

    const int imageWidth = 255;
    const int imageHeight = 255;

    FrameBuffer fb = FrameBuffer(imageWidth, imageHeight);
    char filename[] = "image.ppm";

    for (int j = 0; j < imageHeight; j++) {

        std::clog << "\rScanlines remaining: " << imageHeight - j << " " << std::flush;

        for (int i = 0; i < imageWidth; i++) {

            float r = float(i) / (imageWidth-1);
            float g = float(j) / (imageHeight-1);
            float b = 0.0f;

            fb.plotPixel(i, j, r, g, b);

        }
    }

    fb.writeRGB(filename);

    return 0;
}