.PHONY: all clean test s21_string.a gcov_report

COVERAGE= #--coverage
ASAN= #-fsanitize=address
CC= gcc
CFLAGS= -Wall -Wextra -Werror -std=c11 $(ASAN)
LDFLAGS= ASAN
EXEC= a.out

LIBSOURCES= $(wildcard s21_*.c) $(wildcard s21_sscanf/s21_*.c) $(wildcard s21_sprintf/s21_*.c)
LIBOBJECTS= $(LIBSOURCES:.c=.o)

all:
	make -j test --no-print-directory
	make gcov_report --no-print-directory

test: s21_string.a
	$(CC) $(CFLAGS) $(COVERAGE) tests/check_s21_string.c s21_string.a `pkg-config --cflags --libs check` -o $(EXEC)
	exec ./$(EXEC)

s21_string.a: $(LIBOBJECTS)
	ar rc s21_string.a $^
	ranlib s21_string.a

%.o: %.c
	$(CC) -c $(COVERAGE) $(CFLAGS) $< -o $@

gcov_report: s21_string.a test
	lcov -t "test" -o test.info -c -d . --rc lcov_branch_coverage=1
	genhtml -o report test.info --rc lcov_branch_coverage=1

clean:
	find . -name '*.gcno' -type f -delete
	find . -name '*.gcda' -type f -delete
	find . -name '*.a' -type f -delete
	find . -name '*.o' -type f -delete
	find . -name '*.info' -type f -delete
	rm -f $(EXEC)
	rm -rf report
