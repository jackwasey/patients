#include "patients_types.h"
#include "random.h"
#include <testthat.h>
using namespace Rcpp;

context("random data") {
  test_that("random numeric vector of major codes is ok") {
    Rcpp::NumericVector nv = randomMajorCpp(1);
    // minimal test:
    expect_true(nv.size() == 1);
    nv = randomMajorCpp(10);
    expect_true(nv.size() == 10);
    nv = randomMajorCpp(10000);
    expect_true(nv.size() == 10000);
    Rcpp::NumericVector v = randomMajorCpp(10);
    expect_true(v.size() == 10);
    bool gt_zero = is_true(Rcpp::all(v > 0));
    bool lt_thousand = Rcpp::is_true(Rcpp::all(v < 1000));
    expect_true(gt_zero);
    expect_true(lt_thousand);
  }
  test_that("random N codes") {
    VecStr n = icd9RandomShortN(1);
    expect_true(n.size() == 1);
    expect_true(n[0].substr(0, 1) != "E");
    expect_true(n[0].substr(0, 1) != "V");
    n = icd9RandomShortN(999);
    expect_true(n.size() == 999);
  }
  test_that("random V codes") {
    VecStr v = icd9RandomShortV(1);
    expect_true(v.size() == 1);
    expect_true(v[0].substr(0, 1) == "V");
    v = icd9RandomShortV(999);
    expect_true(v.size() == 999);
    expect_true(v[998].substr(0, 1) == "V");
    expect_true(v[0].size() >= 3);
    expect_true(v[0].size() <= 5);
  }
  test_that("random E codes") {
    VecStr e = icd9RandomShortE(1);
    expect_true(e.size() == 1);
    expect_true(e[0].substr(0, 1) == "E");
    e = icd9RandomShortE(999);
    expect_true(e.size() == 999);
    expect_true(e[998].substr(0, 1) == "E");
    expect_true(e[0].size() >= 4);
    expect_true(e[0].size() <= 5);
  }
  test_that("random any code") {
    auto c = icd9RandomShort(1);
    expect_true(c.size() == 1);
    expect_true(c[0].size() >= 3);
    expect_true(c[0].size() <= 5);
  }
}
