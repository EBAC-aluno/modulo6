#include "quadraticFormulaUtils.h"

float calculateDelta(Coefficients coefficients){
  return coefficients.b * coefficients.b - 4.0f * coefficients.a * coefficients.c;
}

bool isDeltaNegative(Coefficients coefficients){  
  return calculateDelta(coefficients) < 0.0f;
}

void fixRootsSignIfNecessary(Roots *roots){
  if(fabs(roots -> firstRoot.realPart) < FLT_MIN){
    roots -> firstRoot.realPart = 0.0f;
  }

  if(fabs(roots -> secondRoot.realPart) < FLT_MIN){
    roots -> secondRoot.realPart = 0.0f;
  }
}

void switchRootsOrder(Roots *roots){
  float temp = roots -> firstRoot.realPart;
  roots -> firstRoot.realPart = roots -> secondRoot.realPart;
  roots -> secondRoot.realPart = temp;
}

bool areRootsEqualAndPureReal(Roots roots){
  return fabs(roots.firstRoot.realPart - roots.secondRoot.realPart) < FLT_EPSILON;
}

bool areRootsImaginary(Roots roots){
  return fabs(roots.firstRoot.imaginaryPart) > 0.0f;
}
