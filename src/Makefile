CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
# ADD_FLAGS = -lrt -lpthread -lm -lsubunit
# TESTS=t_eq_matrix.c t_create_matrix.c t_sum.c t_sub.c t_mult_number.c t_mult_matrix.c t_transpose.c t_determinant.c t_calc_complements.c t_inverse.c
TESTS=t_tests/t_*.c

LIBS = -lm -lsubunit
TST_LIBS = $(shell pkg-config --libs check)

ifeq ($(OS), Darwin)
	OPEN_CMD = open
	ADD_FLAGS =
endif

ifeq ($(OS), Linux)
	OPEN_CMD = xdg-open
	ADD_FLAGS = -lrt -lpthread -lm -lsubunit
endif


all: clean test

s21_matrix.a:
	$(CC) $(CFLAGS) -c s21_matrix.c
	ar -rcs s21_matrix.a ./*.o
	ranlib s21_matrix.a

test: s21_matrix.a
	$(CC) $(CFLAGS) $(TESTS) t_tests/tests.c s21_matrix.a $(ADD_FLAGS) $(TST_LIBS) -lcheck -o test
	rm -rf *.o
	./test

clang:
	cp ../materials/linters/.clang-format .
	clang-format -i *.c *.h
	clang-format -i t_tests/*.c t_tests/*.h


valgrind:
	valgrind --leak-check=full -s ./test

clean:
	rm -rf *.o
	rm -rf *.a
	rm -rf *.log
	rm -rf test
	rm -rf report
	rm -rf *.gcda *.gcno *.gcov
	rm -rf .clang-format
	rm -rf *.out
	rm -rf gcheck.info

rebuild: clean all
