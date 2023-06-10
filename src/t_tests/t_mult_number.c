#include "tests.h"
#include "../s21_matrix.h"

START_TEST(mult_number_1) {
  int rows = 3, columns = 5;
  double number = 11324;
  matrix_t A = {0};
  matrix_t current = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &result);
  s21_create_matrix(rows, columns, &current);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = rand() % 100 + 123;
      current.matrix[i][j] = A.matrix[i][j] * number;
      result.matrix[i][j] = 2;// вдруг проинецелизированна 
    }
  }
  int res = s21_mult_number(&A, number, &result);
  ck_assert(res == 0);
   for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++)
    ck_assert_double_eq(current.matrix[i][j], result.matrix[i][j]);
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&current);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_2) {
  int rows = 3, columns = 5;
  double number = 11324;
  matrix_t A = {0};
  matrix_t current = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &result);
  s21_create_matrix(rows, columns, &current);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = rand() % 100 - 123;
      current.matrix[i][j] = A.matrix[i][j] * number;
      result.matrix[i][j] = 2;// вдруг проинецелизированна 
    }
  }
  int res = s21_mult_number(&A, number, &result);
  ck_assert(res == 0);
   for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++)
    ck_assert_double_eq(current.matrix[i][j], result.matrix[i][j]);
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&current);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_3) {
  int rows = 3, columns = 5;
  double number = 11324.000123;
  matrix_t A = {0};
  matrix_t current = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &result);
  s21_create_matrix(rows, columns, &current);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = rand() % 100 + (i + j) * 0.001;
      current.matrix[i][j] = A.matrix[i][j] * number;
    }
  }
  int res = s21_mult_number(&A, number, &result);
  ck_assert(res == 0);
   for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++)
    ck_assert_double_eq(current.matrix[i][j], result.matrix[i][j]);
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&current);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_4) {
  int rows = 10, columns = 5;
  double number = -0.000123;
  matrix_t A = {0};
  matrix_t current = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &result);
  s21_create_matrix(rows, columns, &current);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (i + j + 100) * 1.4124;
      current.matrix[i][j] = (i + j + 100) * 1.4124 * number;
    }
  }
  int res = s21_mult_number(&A, number, &result);
  ck_assert(res == 0);
   for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++)
    ck_assert_double_eq(current.matrix[i][j], result.matrix[i][j]);
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&current);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_5) {
  int rows = 1, columns = 1;
  double number = -0.000123;
  matrix_t A = {0};
  matrix_t current = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &result);
  s21_create_matrix(rows, columns, &current);
  A.matrix[0][0] = 123.142;
  current.matrix[0][0] = 123.142 * number;
  int res = s21_mult_number(&A, number, &result);
  ck_assert(res == 0);
   for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++)
    ck_assert_double_eq(current.matrix[i][j], result.matrix[i][j]);
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&current);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_6) {
  int rows = 1, columns = -1;
  double number = -0.000123;
  matrix_t A = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, 1, &result);
  int res = s21_mult_number(&A, number, &result);
  ck_assert(res == 1);
  s21_remove_matrix(&result);
}
END_TEST

Suite *suite_mult_number(void) {
  Suite *s = suite_create("mult_number");
  TCase *tc = tcase_create("mult_number");

  tcase_add_test(tc, mult_number_1);
  tcase_add_test(tc, mult_number_2);
  tcase_add_test(tc, mult_number_3);
  tcase_add_test(tc, mult_number_4);
  tcase_add_test(tc, mult_number_5);
  tcase_add_test(tc, mult_number_6);


  suite_add_tcase(s, tc);
  return s;
}
