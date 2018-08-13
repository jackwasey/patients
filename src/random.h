#include "patients_types.h"
#include <string>
#include <vector>
using Rcpp::runif;
using Rcpp::as;

Rcpp::NumericVector randomMajorCpp(int	n);
VecStr icd9RandomShortN(VecStr::size_type n = 5);
VecStr icd9RandomShortV(VecStr::size_type n = 5);
VecStr icd9RandomShortE(VecStr::size_type n = 5);
CV icd9RandomShort(unsigned int n = 5);
