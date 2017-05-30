// renderFractal.h
//
// written by Thomas CARTON
//

#ifndef __RenderFractal_h__
#define __RenderFractal_h__


// FractalMode
typedef enum
{
	FractalModeMandelbrot,
	FractalModeJulia,
} FractalMode;


// FractalParameters
typedef struct
{
	FractalMode mode;
	double cr, ci;
	
	double xMin, xMax;
	double yMin, yMax;

	int iterations;

} FractalParameters;


void RenderFractal(FractalParameters params, Image *image);


#endif // __RenderFractal_h__
