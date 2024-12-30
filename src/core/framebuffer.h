#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

typedef struct {
    float red = 0.0f;
    float green = 0.0f;
    float blue = 0.0f;
    float depth = 0.0f;
} Pixel;

class FrameBuffer {

    private:
        Pixel* framebufer;

    public:
        int width;
        int height;
        FrameBuffer(const int width, const int height);
        inline int plotPixel(int x, int y, float red, float green, float blue) {
            if ((x < 0) || (x >= width) || (y < 0) || (y >= height)) {
                return -1;
            }

            framebufer[y * width + x].red = red;
            framebufer[y * width + x].green = green;
            framebufer[y * width + x].blue = blue;

            return 0;
        };
        inline int plotDepth(int x, int y, float depth) {
            if ((x < 0) || (x >= width) || (y < 0) || (y >= height)) {
                return -1;
            }

            framebufer[y * width + x].depth = depth;

            return 0;
        };
        int writeRGB(char* filename);
        int writeDepth(char* filename);

};

#endif