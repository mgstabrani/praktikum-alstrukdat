CC = gcc
CFLAGS = -c -Wall
PROFILE_FLAGS = -fprofile-arcs -ftest-coverage
TST_LIBS = -lcheck -lm -lpthread -lrt -lsubunit
COV_LIBS = -lgcov -coverage
SRC_DIR= src
TST_DIR= tests
SRC_FILES = $(addprefix $(SRC_DIR)/, *.c) 
TST_FILES = $(addprefix $(TST_DIR)/, *.c)
GCOV = gcovr 
GCONV_FLAGS = -s -d


all: coverage

point.o:  $(SRC_FILES) $(addprefix $(SRC_DIR)/, point.h)
	$(CC) $(CFLAGS) $(PROFILE_FLAGS) $(SRC_FILES) 

check_point.o: $(TST_FILES)
	$(CC) $(CFLAGS) $(PROFILE_FLAGS)  $(TST_FILES) 

check_point_tests: point.o check_point.o
	$(CC) point.o check_point.o $(TST_LIBS) $(COV_LIBS) -o check_point_tests

test: check_point_tests
	./check_point_tests

coverage: test
	$(GCOV) $(GCONV_FLAGS)

coverage_report.html: test
	$(GCOV) $(GCONV_FLAGS) -o coverage_report.html

.PHONY: clean all

clean:
	-rm -rf *.o *.html *.gcda *.gcno check_point_tests
