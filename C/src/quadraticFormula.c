#include "commonStructs.h"
#include "inputValidator.h"
#include "rootsCalculator.h"
#include "printer.h"

int main(int argc, char* argv[]){

  Roots roots = calculateRoots(getPolynomialCoefficients(argc, argv));
  printRoots(roots);

  return 0;
}
