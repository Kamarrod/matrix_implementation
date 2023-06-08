#include "tests.h"
#include "s21_matrix.h"

START_TEST(calc_complements_1) {
  matrix_t A = {0};
} END_TEST

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
