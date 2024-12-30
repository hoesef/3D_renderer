#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>

#include "core\framebuffer.h"
#include "core\linedrawer.h"

int main() {

    const int imageWidth = 512;
    const int imageHeight = 512;

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

    for (float i = 0; i < M_PI * 2; i += M_PI / 32.0f) {

        float x = cos(i);
        float y = sin(i);

        drawline(fb, 256 + (int)(48.0f*x), 256 + (int)(48.0f*y), 256 + (int)(240.0f*x), 256 + (int)(240.0f*y));
    }

    
    fb.writeRGB(filename);

    return 0;
}