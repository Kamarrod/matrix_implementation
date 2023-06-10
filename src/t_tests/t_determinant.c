#include "tests.h"
#include "../s21_matrix.h"

START_TEST(determimant_1) {
  int rows = 3, columns = 3;
  double result;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  int sum = 1;
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
      A.matrix[i][j] = sum++;
  double answer = 0.0;
  int res = s21_determinant(&A, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_double_eq(result, answer);
  s21_remove_matrix(&A);

} END_TEST

START_TEST(determimant_2) {
  int rows = 3, columns = 3;
  double result;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 3.01;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 10;
  A.matrix[1][0] = -12;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 32.4;
  A.matrix[2][0] = 19;
  A.matrix[2][1] = -13.1;
  A.matrix[2][2] = 0.002;
  double answer = 3320.83648;
  int res = s21_determinant(&A, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_double_eq(result, answer);
  s21_remove_matrix(&A);
} END_TEST

START_TEST(determimant_3) {
  int rows = 3, columns = 5;
  double result;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  int res = s21_determinant(&A, &result);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
} END_TEST

START_TEST(determimant_4) {
  double result;
  matrix_t A = {0};
  int res = s21_determinant(&A, &result);
  ck_assert_int_eq(res, 1);
} END_TEST

START_TEST(determimant_5) {
  int rows = 2, columns = 2;
  double result;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = -100.1;
  A.matrix[0][1] = 200.0001;
  A.matrix[1][0] = 1e-6;
  A.matrix[1][1] = 123.56789;
  double answer = -12369.145989000099999;
  int res = s21_determinant(&A, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_double_eq(result, answer);
  s21_remove_matrix(&A);
} END_TEST

Suite *suite_determimant(void) {
  Suite *s = suite_create("determimant");
  TCase *tc = tcase_create("determimant");

  tcase_add_test(tc, determimant_1);
  tcase_add_test(tc, determimant_2);
  tcase_add_test(tc, determimant_3);
  tcase_add_test(tc, determimant_4);
  tcase_add_test(tc, determimant_5);

  suite_add_tcase(s, tc);
  return s;
}
