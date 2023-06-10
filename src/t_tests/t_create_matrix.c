#include "tests.h"
#include "../s21_matrix.h"

START_TEST(matrix_create_1) {
  matrix_t A = {0};
  int rows = 0;
  int columns = 0;
  int res = s21_create_matrix(rows, columns, &A);
  ck_assert(res == 1);
}
END_TEST

START_TEST(matrix_create_2) {
  matrix_t A = {0};
  int rows = -12;
  int columns = 100;
  int res = s21_create_matrix(rows, columns, &A);
  ck_assert(res == 1);
}
END_TEST

START_TEST(matrix_create_3) {
  matrix_t A;
  int rows = 1;
  int columns = 1;
  int res = s21_create_matrix(rows, columns, &A);
  ck_assert(res == 0);
  ck_assert(A.rows == rows && A.columns == columns);
  ck_assert(sizeof(A.matrix) / sizeof(A.matrix[0][0]) == 1);
  if (A.matrix)
    s21_remove_matrix(&A);
}
END_TEST

START_TEST(matrix_create_4) {
  matrix_t A;
  int rows = 10;
  int columns = 5;
  int res = s21_create_matrix(rows, columns, &A);
  ck_assert(res == 0);
  ck_assert(A.rows == rows && A.columns == columns);
  if (A.matrix)
    s21_remove_matrix(&A);
}
END_TEST

Suite *suite_create_matrix(void) {
  Suite *s = suite_create("create");
  TCase *tc = tcase_create("create");

  tcase_add_test(tc, matrix_create_1);
  tcase_add_test(tc, matrix_create_2);
  tcase_add_test(tc, matrix_create_3);
  tcase_add_test(tc, matrix_create_4);

  suite_add_tcase(s, tc);
  return s;
}
