context("random icd9")

test_that("good random ICD-9 codes are made", {
  rs <- icd9RandomShort(1000)
  expect_true(all(nchar(rs) >= 2))
  expect_true(all(nchar(rs) <= 5))
  # basic regex checks here, not full vaildation
  expect_true(any(grepl(pattern = "^[0-9]{1,5}", rs)))
  expect_true(any(grepl(pattern = "^V.+", rs)))
  expect_true(any(grepl(pattern = "^E.+", rs)))
})

test_that("valid short n", {
  x <- icd9RandomShortN(100)
  expect_true(all(icd::is_valid(x)))
})

test_that("valid short v", {
  x <- icd9RandomShortV(100)
  expect_true(all(icd::is_valid(x)))
})

test_that("valid short e", {
  x <- icd9RandomShortE(100)
  expect_true(all(icd::is_valid(x)))
})
