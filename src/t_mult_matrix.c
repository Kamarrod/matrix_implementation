#include "tests.h"
#include "s21_matrix.h"

START_TEST(mult_matrix_1) {
  int rows = 3, columns = 2;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  matrix_t current = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(columns, rows, &B);
  s21_create_matrix(rows, rows, &current);

  int sum = 0;
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      sum++;
      A.matrix[i][j] = sum;
    }
  sum = 0;
  for (int i = 0; i < columns; i++)
    for (int j = 0; j < rows; j++) {
      sum++;
      B.matrix[i][j] = sum;
    }
  current.matrix[0][0] = 9;
  current.matrix[0][1] = 12;
  current.matrix[0][2] = 15;
  current.matrix[1][0] = 19;
  current.matrix[1][1] = 26;
  current.matrix[1][2] = 33;
  current.matrix[2][0] = 29;
  current.matrix[2][1] = 40;
  current.matrix[2][2] = 51;

  int res = s21_mult_matrix(&A, &B, &result);
  ck_assert(res == 0);
  ck_assert_int_eq(s21_eq_matrix(&current, & result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&current);
  s21_remove_matrix(&result);

}END_TEST

START_TEST(mult_matrix_2) {
  int rowsA = 3, columnsA = 3, rowsB = 2, columnsB = 2;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(rowsA, columnsA, &A);
  s21_create_matrix(rowsB, columnsB, &B);

  for (int i = 0; i < rowsA; i++)
    for (int j = 0; j < columnsA; j++) {
      A.matrix[i][j] = 1;
      if (i < rowsB && j < columnsB) 
        B.matrix[i][j] = 1;
    }
  int res = s21_mult_matrix(&A,&B, &result);
  ck_assert(res == 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

}END_TEST

START_TEST(mult_matrix_3) {
  int rows = 1, columns = 1;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  matrix_t current = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(columns, rows, &B);
  s21_create_matrix(rows, rows, &current);

  A.matrix[0][0] = 1;
  B.matrix[0][0] = 1;
  current.matrix[0][0] = 1;

  int res = s21_mult_matrix(&A, &B, &result);
  ck_assert(res == 0);
  ck_assert_int_eq(s21_eq_matrix(&current, & result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&current);
  s21_remove_matrix(&result);

}END_TEST

START_TEST(mult_matrix_4) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  rows = -rows;
  cols = -cols;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  s21_create_matrix(cols, rows, &mtx);

  matrix_t check = {0};
  s21_create_matrix(m.rows, mtx.columns, &check);

  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_matrix(&m, &mtx, &res), 1);

  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST


Suite *suite_mult_matrix(void) {
  Suite *s = suite_create("mult_matrix");
  TCase *tc = tcase_create("mult_matrix");

  tcase_add_test(tc, mult_matrix_1);
  tcase_add_test(tc, mult_matrix_2);
  tcase_add_test(tc, mult_matrix_3);
  tcase_add_test(tc, mult_matrix_4);

  suite_add_tcase(s, tc);
  return s;
}
