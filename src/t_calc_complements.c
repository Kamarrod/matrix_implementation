#include "tests.h"
#include "s21_matrix.h"

START_TEST(calc_complements_1) {
  int rows = 3, columns = 3;
  matrix_t A = {0};
  matrix_t current = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &current);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  current.matrix[0][0] = 0;
  current.matrix[0][1] = 10;
  current.matrix[0][2] = -20;
  current.matrix[1][0] = 4;
  current.matrix[1][1] = -14;
  current.matrix[1][2] = 8;
  current.matrix[2][0] = -8;
  current.matrix[2][1] = -2;
  current.matrix[2][2] = 4;
  int res = s21_calc_complements(&A, &result);
  ck_assert(res == 0);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq(result.matrix[i][j], current.matrix[i][j]);
    }
  s21_remove_matrix(&A);
  s21_remove_matrix(&current);
  s21_remove_matrix(&result);

} END_TEST


START_TEST(calc_complements_2) {
  int rows = 3, columns = 3;
  matrix_t A = {0};
  matrix_t current = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &current);
  A.matrix[0][0] = 0.73;
  A.matrix[0][1] = -0.19;
  A.matrix[0][2] = -0.12;
  A.matrix[1][0] = -0.07;
  A.matrix[1][1] = 0.72;
  A.matrix[1][2] = -0.17;
  A.matrix[2][0] = -0.12;
  A.matrix[2][1] = -0.15;
  A.matrix[2][2] = 0.92;
  current.matrix[0][0] = 0.6369;
  current.matrix[0][1] = 0.0848;
  current.matrix[0][2] = 0.0969;
  current.matrix[1][0] = 0.1928;
  current.matrix[1][1] = 0.6572;
  current.matrix[1][2] = 0.1323;
  current.matrix[2][0] = 0.1187;
  current.matrix[2][1] = 0.1325;
  current.matrix[2][2] = 0.5123;
  int res = s21_calc_complements(&A, &result);
  ck_assert(res == 0);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], current.matrix[i][j], 1e-6);
    }
  s21_remove_matrix(&A);
  s21_remove_matrix(&current);
  s21_remove_matrix(&result);

} END_TEST

START_TEST(calc_complements_3) {
  matrix_t A = {0};
  matrix_t result = {0};
  int code = s21_calc_complements(&A, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(calc_complements_4) {
  matrix_t A = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(3, 4, &A);
  if (codec == 0) {
    int code = s21_calc_complements(&A, &result);
    ck_assert_int_eq(code, 2);
    s21_remove_matrix(&A);
  }
}
END_TEST

START_TEST(calc_complements_5) {
  int rows = 1, columns = 1;
  matrix_t A = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(rows, columns, &A);
  if (codec) {
    int code = s21_calc_complements(&A, &result);
    ck_assert_int_eq(code, 1);
  }
  s21_remove_matrix(&A);
}
END_TEST

Suite *suite_calc_complements(void) {
  Suite *s = suite_create("calc_complements");
  TCase *tc = tcase_create("calc_complements");

  tcase_add_test(tc, calc_complements_1);
  tcase_add_test(tc, calc_complements_2);
  tcase_add_test(tc, calc_complements_3);
  tcase_add_test(tc, calc_complements_4);
  tcase_add_test(tc, calc_complements_5);

  suite_add_tcase(s, tc);
  return s;
}
