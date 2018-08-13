#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* FIXME: 
   Check these declarations against the C/Fortran source code.
*/

/* .Call calls */
extern SEXP _patients_icd9RandomShort(SEXP);
extern SEXP _patients_icd9RandomShortE(SEXP);
extern SEXP _patients_icd9RandomShortN(SEXP);
extern SEXP _patients_icd9RandomShortV(SEXP);
extern SEXP _patients_randomMajorCpp(SEXP);
extern SEXP run_testthat_tests();

static const R_CallMethodDef CallEntries[] = {
    {"_patients_icd9RandomShort",  (DL_FUNC) &_patients_icd9RandomShort,  1},
    {"_patients_icd9RandomShortE", (DL_FUNC) &_patients_icd9RandomShortE, 1},
    {"_patients_icd9RandomShortN", (DL_FUNC) &_patients_icd9RandomShortN, 1},
    {"_patients_icd9RandomShortV", (DL_FUNC) &_patients_icd9RandomShortV, 1},
    {"_patients_randomMajorCpp",   (DL_FUNC) &_patients_randomMajorCpp,   1},
    {"run_testthat_tests",         (DL_FUNC) &run_testthat_tests,         0},
    {NULL, NULL, 0}
};

void R_init_patients(DllInfo *dll)
{
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
