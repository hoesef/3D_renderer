@echo off
cd C:\Users\joelu\Documents\Coding\3D_renderer
g++ -Wall -Werror -o build\debug\main src\main.cpp src\core\framebuffer.cpp src\core\linedrawer.cpp
build\debug\main
code image.ppm