#include <iostream>
#include <fstream>

int main() {

    const int imageWidth = 255;
    const int imageHeight = 255;

    std::ofstream imageFile("images/image.ppm", std::ios::binary);

    if (imageFile.fail()) {return -1;}

    imageFile << "P6\n" << imageWidth << " " << imageHeight << "\n255\n";

    for (int j = 0; j < imageHeight; j++) {

        std::clog << "\rScanlines remaining: " << imageHeight - j << " " << std::flush;

        for (int i = 0; i < imageWidth; i++) {

            auto r = float(i) / (imageWidth-1);
            auto g = float(j) / (imageHeight-1);
            auto b = 0.0f;

            imageFile << (unsigned char)(255.99 * r);
            imageFile << (unsigned char)(255.99 * g);
            imageFile << (unsigned char)(255.99 * b);

        }
    }

    imageFile.close();

    std::cout << "\nFloat: " << sizeof(float) << "\nDouble: " << sizeof(double) <<"\n";

    return 0;
}