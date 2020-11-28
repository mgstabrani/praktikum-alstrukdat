#include "check.h"
#include "stdlib.h"
#include "stdio.h"
#include "../src/stackt.h"

void makeStackFull (Stack *stack);
void makeStackHalfFull (Stack *stack);

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
START_TEST(CreateEmpty_TC1) {
  Stack stack;
  CreateEmpty(&stack);
  ck_assert_int_eq(-1, stack.TOP);
} END_TEST 

/* ********** PROTOTYPE ********** */
/* IsEmpty: Mengirim true jika Stack kosong: lihat definisi di atas */
START_TEST(IsEmpty_TC1) {
  Stack stack;
  CreateEmpty(&stack);
  ck_assert_int_eq(1, IsEmpty(stack));
} END_TEST 

START_TEST(IsEmpty_TC2) {
  Stack stack;
  CreateEmpty(&stack);
  Push(&stack, 1);
  ck_assert_int_eq(0, IsEmpty(stack));
} END_TEST

START_TEST(IsEmpty_TC3) {
  Stack stack;
  makeStackFull(&stack);
  ck_assert_int_eq(0, IsEmpty(stack));
} END_TEST

/* IsFull: Mengirim true jika tabel penampung nilai elemen stack penuh */
START_TEST(IsFull_TC1) {
  Stack stack;
  CreateEmpty(&stack);
  ck_assert_int_eq(0, IsFull(stack));
} END_TEST 

START_TEST(IsFull_TC2) {
  Stack stack;
  CreateEmpty(&stack);
  Push(&stack, 1);
  ck_assert_int_eq(0, IsFull(stack));
} END_TEST

START_TEST(IsFull_TC3) {
  Stack stack;
  makeStackFull(&stack);
  ck_assert_int_eq(1, IsFull(stack));
} END_TEST

/* *** PRIMITIF : PUSH/POP *** */
/* Push */
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
START_TEST(Push_TC1) {
  Stack stack;
  CreateEmpty(&stack);
  Push(&stack, 10);
  ck_assert_int_eq(10, InfoTop(stack));
  ck_assert_int_eq(0, stack.TOP);
} END_TEST 

START_TEST(Push_TC2) {
  Stack stack;
  makeStackHalfFull(&stack);
  ck_assert_int_eq(4, InfoTop(stack));
  ck_assert_int_eq(4, stack.TOP);
} END_TEST 

START_TEST(Push_TC3) {
  Stack stack;
  makeStackFull(&stack);
  ck_assert_int_eq(9, InfoTop(stack));
  ck_assert_int_eq(MaxEl - 1, stack.TOP);
} END_TEST 

/* Pop */
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
START_TEST(Pop_TC1) {
  Stack stack;
  int dump;
  CreateEmpty(&stack);
  Push(&stack, 10);
  Pop(&stack, &dump);
  ck_assert_int_eq(10, dump);
  ck_assert_int_eq(-1, stack.TOP);
} END_TEST 

START_TEST(Pop_TC2) {
  Stack stack;
  int dump;
  makeStackHalfFull(&stack);
  Pop(&stack, &dump);
  ck_assert_int_eq(4, dump);
  ck_assert_int_eq(3, InfoTop(stack));
  ck_assert_int_eq(3, stack.TOP);
} END_TEST 

START_TEST(Pop_TC3) {
  Stack stack;
  int dump;
  makeStackFull(&stack);
  Pop(&stack, &dump);
  ck_assert_int_eq(9, dump);
  ck_assert_int_eq(8, InfoTop(stack));
  ck_assert_int_eq(MaxEl - 2, stack.TOP);
} END_TEST 

/* ********** SUITE DAN EKSEKUSI ********** */
Suite *stack_suite(void) { 
  Suite *s;
  TCase *tc_make, *tc_prototype, *tc_primitif;
  s = suite_create("Stack");

  tc_make = tcase_create("CreateEmpty");
  tcase_add_test(tc_make, CreateEmpty_TC1);
  suite_add_tcase(s, tc_make); 

  tc_prototype = tcase_create("Prototype");
  tcase_add_test(tc_prototype, IsEmpty_TC1);
  tcase_add_test(tc_prototype, IsEmpty_TC2);
  tcase_add_test(tc_prototype, IsEmpty_TC3);
  tcase_add_test(tc_prototype, IsFull_TC1);
  tcase_add_test(tc_prototype, IsFull_TC2);
  tcase_add_test(tc_prototype, IsFull_TC3);
  suite_add_tcase(s, tc_prototype);

  tc_primitif = tcase_create("Primitif");
  tcase_add_test(tc_primitif, Push_TC1);
  tcase_add_test(tc_primitif, Push_TC2);
  tcase_add_test(tc_primitif, Push_TC3);
  tcase_add_test(tc_primitif, Pop_TC1);
  tcase_add_test(tc_primitif, Pop_TC2);
  tcase_add_test(tc_primitif, Pop_TC3);
  suite_add_tcase(s, tc_primitif);

  return s;
} 

int main(void) {
  int no_failed = 0;
  Suite *s;
  SRunner *runner;

  s = stack_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL); 
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE; 
} 

void makeStackFull(Stack *stack) {
    CreateEmpty(stack);
    int i;
    for (i = 0; i < MaxEl; i++) {
        Push(stack, i);
    }
}

void makeStackHalfFull(Stack *stack) {
    CreateEmpty(stack);
    int i;
    for (i = 0; i < MaxEl/2; i++) {
        Push(stack, i);
    }
}