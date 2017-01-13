// main.c

#include <stdlib.h>
#include <stdio.h>

#include "../libraries/Imaging/include/imaging.h"

#include "fractal.h"


static const unsigned int kWidth = 800;
static const unsigned int kHeight = 600;


int main(int argc, char *argv[])
{
    unsigned char *image = malloc(kWidth * kHeight * 4 * 3);
    unsigned char *reducedImage = NULL;


    // Fractals
    FractalParameters params;
    params.iterations = 500;

    // Mandelbrot set
    params.mode = FractalModeMandelbrot;
    params.xMin = -2.2; params.xMax = 1.03;
    params.yMin = -1.33; params.yMax = 1.33;

    RenderFractal(params, image, kWidth << 1, kHeight << 1);
    reducedImage = ImageDownsize(image, kWidth << 1, kHeight << 1);
    ImageSavePNG("result/mandelbrot.png", reducedImage, kWidth, kHeight);
    free(reducedImage);

    // Julia set
    params.mode = FractalModeJulia;
    params.xMin = -1.54; params.xMax = 1.54;
    params.yMin = -1.17; params.yMax = 1.17;
    params.cr = -0.7; params.ci = 0.27;

    RenderFractal(params, image, kWidth << 1, kHeight << 1);
    reducedImage = ImageDownsize(image, kWidth << 1, kHeight << 1);
    ImageSavePNG("result/julia.png", reducedImage, kWidth, kHeight);
    free(reducedImage);

    params.xMin = -1.44; params.xMax = 1.44;
    params.cr = -0.4; params.ci = 0.6;

    RenderFractal(params, image, kWidth << 1, kHeight << 1);
    reducedImage = ImageDownsize(image, kWidth << 1, kHeight << 1);
    ImageSavePNG("result/julia2.png", reducedImage, kWidth, kHeight);
    free(reducedImage);


    free(image);

    return 0;
}
