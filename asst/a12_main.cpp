/* --------------------------------------------------------------------------
 * File:    a12_main.cpp
 * Created: 2021-10-28
 * --------------------------------------------------------------------------
 *
 *
 *
 * ------------------------------------------------------------------------*/

#include "Image.h"
#include "basicImageManipulation.h"
#include "npr.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void test_brush_singleScalePaint() {
  Image test("./Input/villeperdue.png");
  Image brush_("./Input/brush.png");

  Image blank_1(1000, 1000, 3);
  vector<float> red = {1.0f, 0.0f, 0.0f};
  Image brush_test = brush(blank_1, 400, 400, red, brush_);
  brush_test.write("./Output/brush_test.png");

  Image blank_2(test.width(), test.height(), test.channels());
  Image ssp_test = singleScalePaint(test, blank_2, brush_, 10, 10000);
  ssp_test.write("./Output/singleScalePaint_test.png");
}

void test_sharpnessMap_singleScalePaintImportance() {
  Image test("./Input/villeperdue.png"); // Load input images
  Image brush_("./Input/brush.png");

  Image blank_1(test.width(), test.height(), test.channels()); // Make blank image to output onto
  Image imp = sharpnessMap(test);
  Image ssp_test = singleScalePaintImportance(test, imp, blank_1, brush_);

  imp.write("./Output/sharpnessMap_test.png");
  ssp_test.write("./Output/singleScalePaintImportance_test.png");

}

// This is a way for you to test your functions.
// We will only grade the contents of npr.cpp
int main() {
  clock_t start = clock();

  // test_brush_singleScalePaint();
  test_sharpnessMap_singleScalePaintImportance();
  
  clock_t end = clock();
  double duration = (end - start) * 1.0f / CLOCKS_PER_SEC;
  cout << "a8_main.cpp runtime: " << duration << "s" << endl;
  return 0;
}
