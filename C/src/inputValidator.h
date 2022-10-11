#pragma once

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h>
#include <float.h> 
#include <math.h>
#include "commonStructs.h"

Coefficients getPolynomialCoefficients(int argc, char **argv);
