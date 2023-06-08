#include "tests.h"

#include <limits.h>
#include <math.h>

int main() {
  int nf;
  SRunner *sr;
  sr = srunner_create(suite_eq_matrix());

  srunner_add_suite(sr, suite_create_matrix());
  srunner_add_suite(sr, suite_sum_matrix());
  srunner_add_suite(sr, suite_sub_matrix());
  srunner_add_suite(sr, suite_mult_number());
  srunner_add_suite(sr, suite_mult_matrix());
  srunner_add_suite(sr, suite_transpose());
  srunner_add_suite(sr, suite_determimant());
  srunner_add_suite(sr, suite_calc_complements());

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  nf = srunner_ntests_failed(sr);
  srunner_free(sr);
  return nf == 0 ? 0 : 1;
}
