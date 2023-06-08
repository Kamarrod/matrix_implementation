#include "tests.h"
#include "s21_matrix.h"

START_TEST(equal_test_1) {
  matrix_t matrixA;
  matrix_t matrixB;
  s21_create_matrix(5, 5, &matrixA);
  s21_create_matrix(5, 5, &matrixB);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      matrixA.matrix[i][j] = i * 10 + j;
      matrixB.matrix[i][j] = i * 10 + j;
    }
  }
  int result = s21_eq_matrix(&matrixA, &matrixB);
  ck_assert(result == 1);
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
}
END_TEST

START_TEST(equal_test_2) {
  matrix_t matrixA;
  matrix_t matrixB;
  s21_create_matrix(5, 5, &matrixA);
  s21_create_matrix(5, 5, &matrixB);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      matrixA.matrix[i][j] = i * 10 + j;
      matrixB.matrix[i][j] = -1;
    }
  }
  int result = s21_eq_matrix(&matrixA, &matrixB);
  ck_assert(result == 0);
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
}
END_TEST

START_TEST(equal_test_3) {
  matrix_t matrixA;
  matrix_t matrixB;
  s21_create_matrix(2, 2, &matrixA);
  s21_create_matrix(5, 5, &matrixB);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (i < 2 && j < 2) {
        matrixA.matrix[i][j] = i * 10 + j;
      }
      matrixB.matrix[i][j] = i + j;
    }
  }
  int result = s21_eq_matrix(&matrixA, &matrixB);
  ck_assert(result == 0);
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
}
END_TEST

START_TEST(equal_test_4) {
  matrix_t matrixA;
  matrix_t matrixB;
  s21_create_matrix(1, 1, &matrixA);
  s21_create_matrix(1, 1, &matrixB);
  matrixA.matrix[0][0] = 0.0000015;
  matrixB.matrix[0][0] = 0.0000015;
  int result = s21_eq_matrix(&matrixA, &matrixB);
  ck_assert(result == 1);
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
}
END_TEST

START_TEST(equal_test_5) {
  matrix_t matrixA;
  matrix_t matrixB;
  s21_create_matrix(5, 5, &matrixA);
  s21_create_matrix(5, 5, &matrixB);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      matrixA.matrix[i][j] = (i + 1) *(j + 1) * 1e-6;
      matrixB.matrix[i][j] = (i + 1) *(j + 1) * 1e-6;
    }
  }
  int result = s21_eq_matrix(&matrixA, &matrixB);
  ck_assert(result == 1);
  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
}
END_TEST

START_TEST(equal_test_6) {
  matrix_t matrixA;
  s21_create_matrix(3, 3, &matrixA);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrixA.matrix[i][j] = 123 * (i + j + 1);
    }
  }
  int result = s21_eq_matrix(&matrixA, &matrixA);
  ck_assert(result == 1);
  s21_remove_matrix(&matrixA);
}
END_TEST


Suite *suite_eq_matrix(void) {
  Suite *s = suite_create("eq_matrix");
  TCase *tc = tcase_create("eq_matrix");

  tcase_add_test(tc, equal_test_1);
  tcase_add_test(tc, equal_test_2);
  tcase_add_test(tc, equal_test_3);
  tcase_add_test(tc, equal_test_4);
  tcase_add_test(tc, equal_test_5);
  tcase_add_test(tc, equal_test_6);

  suite_add_tcase(s, tc);
  return s;
}
