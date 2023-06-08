#include "tests.h"
#include "s21_matrix.h"

START_TEST(transpose_1) {
  int rows = 1, columns = 1;
  matrix_t A = {0}, result = {0}, current = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(columns, rows, &current);
  A.matrix[0][0] = 1;
  current.matrix[0][0] = 1;

  int res = s21_transpose(&A, &result);
  ck_assert(res == 0);
  for (int i = 0; i < columns; i++)
    for (int j = 0; j < rows; j++)
      ck_assert_double_eq(current.matrix[i][j], result.matrix[i][j]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&current);
  s21_remove_matrix(&result);
} END_TEST

START_TEST(transpose_2) {
  int rows = 3, columns = 3;
  matrix_t A = {0}, result = {0}, current = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(columns, rows, &current);
  
  int sum = 0;
  for (int i = 0; i < rows; i++)
    for(int j = 0; j < columns; j++)
      A.matrix[i][j] = sum++;

  current.matrix[0][0] = 0;
  current.matrix[0][1] = 3;
  current.matrix[0][2] = 6;
  current.matrix[1][0] = 1;
  current.matrix[1][1] = 4;
  current.matrix[1][2] = 7;
  current.matrix[2][0] = 2;
  current.matrix[2][1] = 5;
  current.matrix[2][2] = 8;

  int res = s21_transpose(&A, &result);
  ck_assert(res == 0);
  for (int i = 0; i < columns; i++)
    for (int j = 0; j < rows; j++)
      ck_assert_double_eq(current.matrix[i][j], result.matrix[i][j]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&current);
  s21_remove_matrix(&result);
} END_TEST

START_TEST(transpose_3) {
  int rows = 2, columns = 3;
  matrix_t A = {0}, result = {0}, current = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(columns, rows, &current);
  
  int sum = 0;
  for (int i = 0; i < rows; i++)
    for(int j = 0; j < columns; j++)
      A.matrix[i][j] = sum++;

  current.matrix[0][0] = 0;
  current.matrix[0][1] = 3;
  current.matrix[1][0] = 1;
  current.matrix[1][1] = 4;
  current.matrix[2][0] = 2;
  current.matrix[2][1] = 5;

  int res = s21_transpose(&A, &result);
  ck_assert(res == 0);
  for (int i = 0; i < columns; i++)
    for (int j = 0; j < rows; j++)
      ck_assert_double_eq(current.matrix[i][j], result.matrix[i][j]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&current);
  s21_remove_matrix(&result);
} END_TEST

START_TEST(transpose_4) {
  int rows = 1, columns = 3;
  matrix_t A = {0}, result = {0}, current = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(columns, rows, &current);
  
  int sum = 0;
  for (int i = 0; i < rows; i++)
    for(int j = 0; j < columns; j++)
      A.matrix[i][j] = 100 + sum++;

  current.matrix[0][0] = 100;
  current.matrix[1][0] = 101;
  current.matrix[2][0] = 102;

  int res = s21_transpose(&A, &result);
  ck_assert(res == 0);
  for (int i = 0; i < columns; i++)
    for (int j = 0; j < rows; j++)
      ck_assert_double_eq(current.matrix[i][j], result.matrix[i][j]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&current);
  s21_remove_matrix(&result);
} END_TEST

START_TEST(transpose_5) {
  int rows = 3, columns = 1;
  matrix_t A = {0}, result = {0}, current = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(columns, rows, &current);
  
  int sum = 0;
  for (int i = 0; i < rows; i++)
    for(int j = 0; j < columns; j++)
      A.matrix[i][j] = 100 + sum++;

  current.matrix[0][0] = 100;
  current.matrix[0][1] = 101;
  current.matrix[0][2] = 102;

  int res = s21_transpose(&A, &result);
  ck_assert(res == 0);
  for (int i = 0; i < columns; i++)
    for (int j = 0; j < rows; j++)
      ck_assert_double_eq(current.matrix[i][j], result.matrix[i][j]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&current);
  s21_remove_matrix(&result);
} END_TEST


Suite *suite_transpose(void) {
  Suite *s = suite_create("transpose");
  TCase *tc = tcase_create("transpose");

  tcase_add_test(tc, transpose_1);
  tcase_add_test(tc, transpose_2);
  tcase_add_test(tc, transpose_3);
  tcase_add_test(tc, transpose_4);
  tcase_add_test(tc, transpose_5);

  suite_add_tcase(s, tc);
  return s;
}
