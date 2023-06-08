#include "tests.h"
#include "s21_matrix.h"

START_TEST(sum_1) {
  int rows = 5, columns = 6;
  matrix_t A;
  matrix_t B;
  matrix_t current;
  matrix_t result;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &current);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (i + j + 1);
      B.matrix[i][j] = (i + j + 1);
      current.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
    }
  int res = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(res, 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++)
    ck_assert_double_eq(current.matrix[i][j], result.matrix[i][j]);
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&current);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_2) {
  int rows = 10, columns = 10;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t current = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &current);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 12345 + i * 10 + j;
      B.matrix[i][j] = 12345 + i * 10 + j;
      current.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
    }
  int res = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(res, 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++)
    ck_assert_double_eq(current.matrix[i][j], result.matrix[i][j]);
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&current);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_3) {
  int rows = 3, columns = 3;
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows - 1, columns, &B);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 12345 + i * 10 + j;
      if (i < rows - 1)
        B.matrix[i][j] = 12345 + i * 10 + j;
    }
  int res = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_4) {
  int rows = 3, columns = 3;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, columns, &A);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 12345 + i * 10 + j;
    }
  int res = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(sum_5) {
  int rows = 3, columns = 3;
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  int res = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_6) {
  int rows = 10, columns = 10;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t current = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &current);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = rand() % 1000 + 1;
      B.matrix[i][j] = rand() % 1000 + 1;
      current.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
    }
  int res = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(res, 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++)
    ck_assert_double_eq(current.matrix[i][j], result.matrix[i][j]);
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&current);
  s21_remove_matrix(&result);
}
END_TEST

Suite *suite_sum_matrix(void) {
  Suite *s = suite_create("sum");
  TCase *tc = tcase_create("sum");

  tcase_add_test(tc, sum_1);
  tcase_add_test(tc, sum_2);
  tcase_add_test(tc, sum_3);
  tcase_add_test(tc, sum_4);
  tcase_add_test(tc, sum_5);
  tcase_add_test(tc, sum_6);

  suite_add_tcase(s, tc);
  return s;
}
