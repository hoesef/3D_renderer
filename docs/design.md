# 3D renderer project design doccument
This project aims to implement a 3D renderer in c++ from scratch, with the ultimate aim of being able to render a screen reminissent of a Cornel Box. The program will render an image in .ppm format.

To help track the projects progression and stay motivated, bellow will list some goals and key milestones for this project.

## Project order
- [x] Creating a basic PPM image (just a simple colour gradient)
- [x] Implementing a frambuffer to easily create and modify an image
- [ ] Creating a basic line drawing function
- [ ] Parsing data from an obj file into an object class
- [ ] Producing a wire-frmae rendering of an object
- [ ] Rendering a solid object

# Framebuffer
The framebuffer is used to store pixel values while the rendering process is underway. Once the rendering has finished, the framebuffer writes its stored pixel values to a ppm file.

To acompany the framebuffer is a pixel structure that stores the rbg colour value of a pixel, along with the depth it occurs at in the scene. The depth is kept for two main reasons, first it can be used as a z-buffer in any renderings where z-fighting may occur. Seccondly it allows for the creation of a depth image to be made, which can be useful for debugging in circumstnaces when the real image is incorrect (such as cheching that the object is in the scene if nothing is showing in the real image).

The frmaebuffer should be an array of pixels width x height in size. It should have 4 main functions:
- plotPixel
    - store an rgb value corresponding to a specific pixel coordinate
- plotDepth
    - store a depth value corresponding to a specific pixel coordinate
- writeRGB
    - write the rbg values to a PPM file
- wirteDepth
    - write the depth values to a (grayscale) PPM file

# Linedrawer
I will write 2 line drawing algorithms, first using DDA, then using int only.
