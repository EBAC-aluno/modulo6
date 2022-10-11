#include "inputValidator.h"

typedef struct CoefficientsFlags{
  bool aCanBeFloat;
  bool bCanBeFloat;
  bool cCanBeFloat;
} CoefficientsFlags;

void throwsDefaultError(char **argv){
  fprintf(stderr, "Usage: %s [-a a_coefficient] [-b b_coefficient] [-c c_coefficient]\n", argv[0]);
  exit(EXIT_FAILURE);
}

void throwsACoefficientError(){
  fprintf(stderr, "Error: 'a' coefficient can't be zero.\n");
  exit(EXIT_FAILURE);
}

void throwsInvalidParameterError(char **argv){
  fprintf(stderr, "Error: invalidParameter -- %c\n", optopt);
  throwsDefaultError(argv);
}

bool isValidArgument(char *input){
  char *pattern = "^(-?\\+?([0-9]+|\\.)\\.?([0-9]+)?\\b)"; // pattern for float and integers
  
  regex_t regularExpression;
  regcomp(&regularExpression, pattern, REG_EXTENDED);
  
  int isNotAMatch = regexec(&regularExpression, input, 0, NULL, 0); 
  regfree(&regularExpression);
  
  if(isNotAMatch){
    return false;
  }
  return true;
}

void checkIfInputs(CoefficientsFlags coefficientFlags, float aCoefficient, char **argv){
  if(!coefficientFlags.aCanBeFloat){
    fprintf(stderr, "Error: invalid or missing 'a' coefficient\n");
    throwsDefaultError(argv);
  }

  if(!coefficientFlags.bCanBeFloat){
    fprintf(stderr, "Error: invalid or missing 'b' coefficient\n");
    throwsDefaultError(argv);
  }

  if(!coefficientFlags.cCanBeFloat){
    fprintf(stderr, "Error: invalid or missing 'c' coefficient\n");
    throwsDefaultError(argv);
  }

  if(fabs(aCoefficient) < FLT_MIN){
    throwsACoefficientError();
  }
}

Coefficients getPolynomialCoefficients(int argc, char **argv){
  
  CoefficientsFlags coefficientFlags = {
    .aCanBeFloat = false,
    .bCanBeFloat = false,
    .cCanBeFloat = false
  };

  Coefficients coefficients;

  int opt;

  opterr = 0; // to ignore default getopt() error messages

  while ((opt = getopt(argc, argv, "a:b:c:")) != -1){
    switch (opt){
    case 'a':
      if(isValidArgument(optarg)){
        coefficients.a = atof(optarg);
        coefficientFlags.aCanBeFloat = true;
    }
    break;
    case 'b':
      if(isValidArgument(optarg)){
        coefficients.b = atof(optarg);
        coefficientFlags.bCanBeFloat = true;
    }
    break;
    case 'c':
      if(isValidArgument(optarg)){
        coefficients.c = atof(optarg);
        coefficientFlags.cCanBeFloat = true;
    }
    break;
    default:
      throwsInvalidParameterError(argv);
    }
  }

  checkIfInputs(coefficientFlags, coefficients.a, argv);

  return coefficients;
}
