#include "printer.h"

void printImaginaryRoots(Roots roots){
  printf("The roots are: (%0.3f -/+ %0.3fi).\n", 
    roots.firstRoot.realPart, 
    fabs(roots.firstRoot.imaginaryPart)
  );
}

void printPureRealEqualRoots(Roots roots){
  printf("The roots are the same: %0.4f.\n", roots.firstRoot.realPart);
}

void printPureDifferentRoots(Roots roots){
  printf("The first root is: %0.4f, and the second one is: %0.4f.\n", roots.firstRoot.realPart, roots.secondRoot.realPart);
}

void printRoots(Roots roots){

  if(areRootsImaginary(roots)){
    printImaginaryRoots(roots);
    return;
  } 
  
  if(areRootsEqualAndPureReal(roots)){
    printPureRealEqualRoots(roots);
    return;
  }

  printPureDifferentRoots(roots);
}
