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

stackt.o:  $(SRC_FILES) $(addprefix $(SRC_DIR)/, stackt.h)
	$(CC) $(CFLAGS) $(PROFILE_FLAGS) $(SRC_FILES) 

check_stackt.o: $(TST_FILES)
	$(CC) $(CFLAGS) $(PROFILE_FLAGS)  $(TST_FILES) 

check_stackt_tests: stackt.o check_stackt.o
	$(CC) stackt.o check_stackt.o $(TST_LIBS) $(COV_LIBS) -o check_stackt_tests

test: check_stackt_tests
	./check_stackt_tests

coverage: test
	$(GCOV) $(GCONV_FLAGS)

coverage_report.html: test
	$(GCOV) $(GCONV_FLAGS) -o coverage_report.html

.PHONY: clean all

clean:
	-rm *.o *.html *.gcda *.gcno check_stackt_tests