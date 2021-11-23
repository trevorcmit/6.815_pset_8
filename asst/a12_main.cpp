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


void test_painterly() {
  Image test("./Input/villeperdue.png"); // Load input images
  Image brush_("./Input/brush.png");
  Image paint_test = painterly(test, brush_);
  paint_test.write("./Output/painterly_test.png");

  // Image output(test.width(), test.height(), test.channels());
	// Image first_pass = singleScalePaint(test, output, brush_);
	// Image importance = sharpnessMap(test);
	// Image second_pass = singleScalePaintImportance(test, importance, first_pass, brush_);
  // Image test_sp = singleScalePaintImportance(test, importance, output, brush_);

  // first_pass.write("./Output/first_pass.png");
  // second_pass.write("./Output/second_pass.png");
  // test_sp.write("./Output/test_sp.png");
}


void test_testAngle() {
  Image round("./Input/round.png");
  Image angles = testAngle(round);
  angles.write("./Output/testAngle_test.png");
}


void test_rotateBrushes() {
  Image brush_("./Input/longBrush2.png");

  Image blank_1(900, 900, 3);
  vector<float> red = {1.0f, 1.0f, 0.0f};
  // Image brush_test = brush(blank_1, 400, 400, red, brush_);

  vector<Image> rotations = rotateBrushes(brush_, 10);

  // for (int n = 0; n < 12; n++) {
  rotations.at(0).write("./Output/rotateBrushes_test0.png");
  rotations.at(1).write("./Output/rotateBrushes_test1.png");
  rotations.at(2).write("./Output/rotateBrushes_test2.png");
  rotations.at(3).write("./Output/rotateBrushes_test3.png");
  rotations.at(4).write("./Output/rotateBrushes_test4.png");
  rotations.at(5).write("./Output/rotateBrushes_test5.png");
  rotations.at(6).write("./Output/rotateBrushes_test6.png");
  rotations.at(7).write("./Output/rotateBrushes_test7.png");
  rotations.at(8).write("./Output/rotateBrushes_test8.png");
  rotations.at(9).write("./Output/rotateBrushes_test9.png");
  // }

  // brush_test.write("./Output/rotateBrushes_test.png");
}


void test_singleScaleOrientedPaint() {
  Image test("./Input/villeperdue.png"); // Load input images
  Image brush_("./Input/brush.png");

  Image blank_1(test.width(), test.height(), test.channels()); // Make blank image to output onto
  Image imp = sharpnessMap(test);
  Image tensor = computeTensor(test);

  Image ssop_test = singleScaleOrientedPaint(test, imp, blank_1, tensor, brush_, 50, 10000, 0.0f);
  ssop_test.write("./Output/singleScaleOrientedPaint_test.png");
}


void test_orientedPaint() {
  Image china("./Input/china.png");
  Image round("./Input/round.png");
  Image archie("./Input/archie.png");
  Image liz("./Input/liz.png");

  Image brush_("./Input/brush.png");
  Image longbrush_("./Input/longBrush2.png");

  Image china_out = orientedPaint(china, brush_, 15000, 40);
  Image round_out = orientedPaint(round, brush_, 15000, 40);
  Image archie_out = orientedPaint(archie, brush_, 15000, 40);
  Image liz_out = orientedPaint(liz, longbrush_, 15000, 40);

  china_out.write("./Output/orientedPaint_china.png");
  round_out.write("./Output/orientedPaint_round.png");
  archie_out.write("./Output/orientedPaint_archie.png");
  liz_out.write("./Output/orientedPaint_liz.png");
}


// This is a way for you to test your functions.
// We will only grade the contents of npr.cpp
int main() {
  clock_t start = clock();

  // test_brush_singleScalePaint();
  // test_sharpnessMap_singleScalePaintImportance();
  // test_painterly();
  // test_testAngle();
  // test_rotateBrushes();
  // test_singleScaleOrientedPaint();
  test_orientedPaint();
  
  clock_t end = clock();
  double duration = (end - start) * 1.0f / CLOCKS_PER_SEC;
  cout << "a8_main.cpp runtime: " << duration << "s" << endl;
  return 0;
}
