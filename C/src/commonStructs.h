#pragma once

typedef struct Coefficients {
  float a;
  float b;
  float c;
} Coefficients;

typedef struct Number{
  float realPart;
  float imaginaryPart;
} Number;

typedef struct Roots{
  Number firstRoot;
  Number secondRoot;
} Roots;
