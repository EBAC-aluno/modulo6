#include "rootsCalculator.h"

float calculateBhaskaraDenominator(float a){
  return 2.0f * a;
}

float extractRealPartFromRoot(float b, float denominator){
  return -b / denominator;
}

float extractComplexPartFromRoot(float sqrtAbsDelta, float denominator){
  return sqrtAbsDelta/ denominator;
}

float calculateRealPartFromfirstRoot(float b, float delta, float denominator){
  return -(b - sqrt(delta)) / denominator;
}

float calculateRealPartFromSecondRoot(float b, float delta, float denominator){
  return -(b + sqrt(delta)) / denominator;
}

Roots calculateComplexRoots(Coefficients coefficients){

  float delta = calculateDelta(coefficients);
  float denominator = calculateBhaskaraDenominator(coefficients.a);

  float absDelta = fabs(delta);
  float realPart = extractRealPartFromRoot(coefficients.b, denominator);

  float firstRootComplexPart = extractComplexPartFromRoot(sqrt(absDelta), denominator);
  float secondRootComplexPart = extractComplexPartFromRoot(-sqrt(absDelta), denominator);

  Roots roots;
  roots.firstRoot = (Number){.realPart = realPart, .imaginaryPart = firstRootComplexPart};
  roots.secondRoot = (Number){.realPart = realPart, .imaginaryPart = secondRootComplexPart};

  fixRootsSignIfNecessary(&roots);
  return roots;
}

Roots calculatePureRealRoots(Coefficients coefficients){

  Roots roots;
  float delta = calculateDelta(coefficients);
  float denominator = calculateBhaskaraDenominator(coefficients.a);

  float firstRootRealPart = calculateRealPartFromfirstRoot(coefficients.b, delta, denominator);
  float secondRootRealPart = calculateRealPartFromSecondRoot(coefficients.b, delta, denominator);

  roots.firstRoot = (Number){.realPart = firstRootRealPart, .imaginaryPart = 0.0f};
  roots.secondRoot = (Number){.realPart = secondRootRealPart, .imaginaryPart = 0.0f};

  if(roots.firstRoot.realPart > roots.secondRoot.realPart){
    switchRootsOrder(&roots);
  }

  fixRootsSignIfNecessary(&roots);
  return roots;
}

Roots calculateRoots(Coefficients coefficients){

  if(isDeltaNegative(coefficients)){
    return calculateComplexRoots(coefficients);
  }

  return calculatePureRealRoots(coefficients);
}
