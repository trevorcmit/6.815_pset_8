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

  Image blank(test.width(), test.height(), test.channels());
  vector<float> red = {1.0, 0.0, 0.0};
  Image brush_test = brush(blank, 300, 300, red, brush_);
  brush_test.write("./Output/brush_test.png");

  Image ssp_test = singleScalePaint(test, test, brush_, 10000);
  ssp_test.write("./Output/singleScalePaint_test.png");
}

// This is a way for you to test your functions.
// We will only grade the contents of npr.cpp
int main() {
  clock_t start = clock();

  test_brush_singleScalePaint();
  
  clock_t end = clock();
  double duration = (end - start) * 1.0f / CLOCKS_PER_SEC;
  cout << "a8_main.cpp runtime: " << duration << "s" << endl;
  return 0;
}
