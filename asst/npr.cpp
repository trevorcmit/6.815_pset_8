// npr.cpp
// Assignment 12

#include "npr.h"
#include "filtering.h"
#include "matrix.h"
#include <algorithm>
#include <math.h>

using namespace std;

/**************************************************************
 //                       NPR                                //
 *************************************************************/

Image brush(const Image &im, int x, int y, vector<float> color, const Image &texture) {
	// Draws a brushstroke defined by texture and color at (x,y) in im
	// // --------- HANDOUT  PS12 ------------------------------
	return Image(1,1,1);
}

Image singleScalePaint(const Image &im, const Image &out, const Image &texture, int size, int N, float noise) {
	// Create painted rendering by splatting brushstrokes at N random locations
	// in your ouptut image
	// // --------- HANDOUT  PS12 ------------------------------
	return Image(1,1,1);
}

Image singleScalePaintImportance(const Image &im, const Image &importance,
						const Image &out, const Image &texture, int size, int N, float noise) {
	// Create painted rendering but vary the density of the strokes according to
	// an importance map
	// // --------- HANDOUT  PS12 ------------------------------
	return Image(1,1,1);
}

Image sharpnessMap(const Image &im, float sigma) {
	// Calculate sharpness mask 
	// // --------- HANDOUT  PS12 ------------------------------
	return Image(1,1,1);
}

Image painterly(const Image &im, const Image &texture, int N, int size, int noise) {
	// Create painterly rendering using a first layer of coarse strokes followed
	// by smaller strokes in high detail areas
	// // --------- HANDOUT  PS12 ------------------------------
	return Image(1,1,1);
}

Image computeTensor(const Image &im, float sigmaG, float factorSigma) {
 	// Compute xx/xy/yy Tensor of an image. (stored in that order)
 	// // --------- HANDOUT  PS07 ------------------------------
 	return Image(1,1,1);
}


Image testAngle(const Image &im, float sigmaG, float factor) {
	// Extracts orientation of features in im. Angles should be mapped
	// to [0,1]
	// // --------- HANDOUT  PS12 ------------------------------
    return Image(1,1,1);

}

vector<Image> rotateBrushes(const Image &im, int nAngles) {
	// helper function
	// Returns list of nAngles images rotated by 1*2pi/nAngles
	// // --------- HANDOUT  PS12 ------------------------------
	return vector<Image>();
}

Image singleScaleOrientedPaint(const Image &im, const Image &importance,
		const Image &out, const Image &tensor, const Image &texture,int size, int N, 
		float noise, int nAngles) {
	// Similar to singleScalePaintImportant but brush strokes are oriented
	// according to tensor
	// // --------- HANDOUT  PS12 ------------------------------
	return Image(1,1,1);
}

Image orientedPaint(const Image &im, const Image &texture, int N, int size, int noise) {
	// Similar to painterly() but strokes are oriented along the directions of maximal structure
	// // --------- HANDOUT  PS12 ------------------------------
	return Image(1,1,1);

}



