#ifndef S21_TESTS_H
#define S21_TESTS_H

#include "check.h"
#include "../s21_matrix.h"

Suite *suite_eq_matrix(void);
Suite *suite_create_matrix(void);
Suite *suite_sum_matrix(void);
Suite *suite_sub_matrix(void);
Suite *suite_mult_number(void);
Suite *suite_mult_matrix(void);
Suite *suite_transpose(void);
Suite *suite_determimant(void);
Suite *suite_calc_complements(void);
Suite *suite_inverse_matrix(void);

#endif  // S21_TESTS_H
