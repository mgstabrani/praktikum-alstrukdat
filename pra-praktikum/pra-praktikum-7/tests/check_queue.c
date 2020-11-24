#include "check.h"
#include "stdlib.h"
#include "stdio.h"
#include "../src/queue.h"

#define IdxMax 5

/* *** Kreator *** */
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
START_TEST(MakeEmpty_TC1) {
  Queue Q1;
  MakeEmpty(&Q1, IdxMax);
  ck_assert_int_eq(Nil, Head(Q1));
  ck_assert_int_eq(Nil, Tail(Q1));
  ck_assert_int_eq(IdxMax, MaxEl(Q1));
} END_TEST

/* *** Destruktor *** */
START_TEST(DeAlokasi_TC1) {
  Queue Q1;
  MakeEmpty(&Q1, IdxMax);
  DeAlokasi(&Q1);
  ck_assert_int_eq(0, MaxEl(Q1));
} END_TEST

/* ********** Prototype ********** */
START_TEST(IsEmpty_TC1) {
/* Mengirim true jika Q kosong: lihat definisi di atas */
  Queue Q1;
  MakeEmpty(&Q1, IdxMax);
  ck_assert_int_eq(1, IsEmpty(Q1));
} END_TEST

START_TEST(IsEmpty_TC2) {
/* Mengirim true jika Q kosong: lihat definisi di atas */
  Queue Q1;
  MakeEmpty(&Q1, IdxMax);
  Enqueue(&Q1, 1);
  ck_assert_int_eq(0, IsEmpty(Q1));
} END_TEST

START_TEST(IsFull_TC1) {
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
  Queue Q1;
  MakeEmpty(&Q1, IdxMax);
  ck_assert_int_eq(0, IsFull(Q1));
} END_TEST

START_TEST(IsFull_TC2) {
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
  Queue Q1;
  MakeEmpty(&Q1, IdxMax);
  Enqueue(&Q1, 1);
  Enqueue(&Q1, 1);
  Enqueue(&Q1, 1);
  Enqueue(&Q1, 1);
  Enqueue(&Q1, 1);
  ck_assert_int_eq(1, IsFull(Q1));
} END_TEST

START_TEST(IsFull_TC3) {
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
  Queue Q1;
  MakeEmpty(&Q1, IdxMax);
  Q1.T[0] = 1;
  Q1.T[1] = 1;
  ck_assert_int_eq(0, IsFull(Q1));
} END_TEST

START_TEST(NBElmt_TC1) {
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
  Queue Q1;
  MakeEmpty(&Q1, IdxMax);
  ck_assert_int_eq(0, NBElmt(Q1));
} END_TEST

/* *** Primitif Add/Delete *** */
START_TEST(Enqueue_TC1) {
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
  Queue Q1;
  MakeEmpty(&Q1, IdxMax);
  Enqueue(&Q1, 99);
  ck_assert_int_eq(1, NBElmt(Q1));
  ck_assert_int_eq(99, InfoHead(Q1));
  ck_assert_int_eq(99, InfoTail(Q1));
} END_TEST

START_TEST(Enqueue_TC2) {
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
  Queue Q1;
  MakeEmpty(&Q1, IdxMax);
  Enqueue(&Q1, 99);
  Enqueue(&Q1, 98);
  ck_assert_int_eq(2, NBElmt(Q1));
  ck_assert_int_eq(99, InfoHead(Q1));
  ck_assert_int_eq(98, InfoTail(Q1));
} END_TEST

START_TEST(Enqueue_TC3) {
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
  Queue Q1;
  MakeEmpty(&Q1, IdxMax);
  Enqueue(&Q1, 99);
  Enqueue(&Q1, 98);
  Enqueue(&Q1, 97);
  Enqueue(&Q1, 96);
  Enqueue(&Q1, 95);
  ck_assert_int_eq(5, NBElmt(Q1));
  ck_assert_int_eq(99, InfoHead(Q1));
  ck_assert_int_eq(95, InfoTail(Q1));
  ck_assert_int_eq(1, IsFull(Q1));
} END_TEST

START_TEST(Dequeue_TC1) {
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
  Queue Q1;
  MakeEmpty(&Q1, IdxMax);
  Enqueue(&Q1, 99);
  infotype X;
  Dequeue(&Q1, &X);
  ck_assert_int_eq(0, NBElmt(Q1));
  ck_assert_int_eq(99, X);
  ck_assert_int_eq(-1, Head(Q1));
  ck_assert_int_eq(-1, Tail(Q1));
  ck_assert_int_eq(1, IsEmpty(Q1));
} END_TEST

START_TEST(Dequeue_TC2) {
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
  Queue Q1;
  MakeEmpty(&Q1, IdxMax);
  Enqueue(&Q1, 99);
  Enqueue(&Q1, 98);
  infotype X;
  Dequeue(&Q1, &X);
  ck_assert_int_eq(1, NBElmt(Q1));
  ck_assert_int_eq(99, X);
  ck_assert_int_eq(98, InfoHead(Q1));
  ck_assert_int_eq(0, IsEmpty(Q1));
} END_TEST

START_TEST(Dequeue_TC3) {
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
  Queue Q1;
  MakeEmpty(&Q1, IdxMax);
  Enqueue(&Q1, 99);
  Enqueue(&Q1, 98);
  Enqueue(&Q1, 97);
  Enqueue(&Q1, 96);
  Enqueue(&Q1, 95);
  infotype X, Y, Z;
  Dequeue(&Q1, &X);
  Dequeue(&Q1, &Y);
  Dequeue(&Q1, &Z);
  ck_assert_int_eq(2, NBElmt(Q1));
  ck_assert_int_eq(99, X);
  ck_assert_int_eq(98, Y);
  ck_assert_int_eq(97, Z);
  ck_assert_int_eq(96, InfoHead(Q1));
  ck_assert_int_eq(95, InfoTail(Q1));
  ck_assert_int_eq(0, IsEmpty(Q1));
} END_TEST


/* ********** SUITE DAN EKSEKUSI ********** */
Suite *arraypos_suite(void) { 
  Suite *s;
  TCase *tc_make, *tc_free, *tc_prototype, *tc_primitif;

  s = suite_create("ArrayPos");

  tc_make = tcase_create("Make");
  tcase_add_test(tc_make, MakeEmpty_TC1);
  suite_add_tcase(s, tc_make); 

  tc_free = tcase_create("Destruktor");
  tcase_add_test(tc_free, DeAlokasi_TC1);
  suite_add_tcase(s, tc_free); 

  tc_prototype = tcase_create("Prototype");
  tcase_add_test(tc_prototype, IsEmpty_TC1);
  tcase_add_test(tc_prototype, IsEmpty_TC2);
  tcase_add_test(tc_prototype, IsFull_TC1);
  tcase_add_test(tc_prototype, IsFull_TC2);
  tcase_add_test(tc_prototype, IsFull_TC3);
  tcase_add_test(tc_prototype, NBElmt_TC1);
  suite_add_tcase(s, tc_prototype);

  tc_primitif = tcase_create("Primitif");
  tcase_add_test(tc_primitif, Enqueue_TC1);
  tcase_add_test(tc_primitif, Enqueue_TC2);
  tcase_add_test(tc_primitif, Enqueue_TC3);
  tcase_add_test(tc_primitif, Dequeue_TC1);
  tcase_add_test(tc_primitif, Dequeue_TC2);
  tcase_add_test(tc_primitif, Dequeue_TC3);
  suite_add_tcase(s, tc_primitif);

  return s;
} 

int main(void) {
  int no_failed = 0;
  Suite *s;
  SRunner *runner;

  s = arraypos_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL); 
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE; 
} 

