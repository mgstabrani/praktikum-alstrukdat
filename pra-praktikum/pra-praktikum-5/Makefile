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

matriks.o:  $(SRC_FILES) $(addprefix $(SRC_DIR)/, matriks.h)
	$(CC) $(CFLAGS) $(PROFILE_FLAGS) $(SRC_FILES) 

check_matriks.o: $(TST_FILES)
	$(CC) $(CFLAGS) $(PROFILE_FLAGS)  $(TST_FILES) 

check_matriks_tests: matriks.o check_matriks.o
	$(CC) matriks.o check_matriks.o $(TST_LIBS) $(COV_LIBS) -o check_matriks_tests

test: check_matriks_tests
	./check_matriks_tests

coverage: test
	$(GCOV) $(GCONV_FLAGS)

coverage_report.html: test
	$(GCOV) $(GCONV_FLAGS) -o coverage_report.html

.PHONY: clean all

clean:
	-rm *.o *.html *.gcda *.gcno check_matriks_tests