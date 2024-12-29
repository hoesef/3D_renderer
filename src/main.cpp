#include <iostream>
#include <fstream>

int main() {

    const int imageWidth = 255;
    const int imageHeight = 255;

    std::ofstream imageFile("image.ppm");

    imageFile << "P3\n" << imageWidth << " " << imageHeight << "\n255\n";

    for (int j = 0; j < imageHeight; j++) {

        std::clog << "\rScanlines remaining: " << imageHeight - j << " " << std::flush;

        for (int i = 0; i < imageWidth; i++) {

            auto r = double(i) / (imageWidth-1);
            auto g = double(j) / (imageHeight-1);
            auto b = 0;

            int rbyte = int(255.99 * r);
            int gbyte = int(255.99 * g);
            int bbyte = int(255.99 * b);

            imageFile << rbyte << " " << gbyte << " " << bbyte << "\n";

        }
    }

}