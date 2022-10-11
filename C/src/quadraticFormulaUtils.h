#pragma once

#include <stdbool.h>
#include <math.h> 
#include <float.h> 
#include "commonStructs.h"

float calculateDelta(Coefficients coefficients);

bool isDeltaNegative(Coefficients coefficients);

void fixRootsSignIfNecessary(Roots *roots);

void switchRootsOrder(Roots *roots);

bool areRootsEqualAndPureReal(Roots roots);

bool areRootsImaginary(Roots roots);
