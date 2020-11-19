#include "check.h"
#include "stdlib.h"
#include "../src/point.h"
#include "math.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
START_TEST(MakePOINT_TC1) {
/* Mengecek MakePOINT berhasil membentuk sebuah POINT */
  POINT P;
  
  P = MakePOINT(1, 2);
  ck_assert_float_eq(1.00, Absis(P));
  ck_assert_float_eq(2.00, Ordinat(P));
  ck_assert_float_ne  (1.01, Absis(P));

} END_TEST 

/* *** Kelompok operasi relasional terhadap POINT *** */
/* Test 1 EQ */
START_TEST(EQ_TC1) {
/* Mengecek EQ bernilai true apabila kedua POINT sama */
  POINT P1 = MakePOINT(1, 2);
  POINT P2 = MakePOINT(1, 2);

  boolean result = EQ(P1, P2);
  ck_assert_int_eq(result, true);
} END_TEST

/* Test 2 EQ */
START_TEST(EQ_TC2) {
/* Mengecek EQ bernilai false apabila kedua POINT berbeda */
  POINT P1 = MakePOINT(1, 2);
  POINT P2 = MakePOINT(1, 3);

  boolean result = EQ(P1, P2);
  ck_assert_int_eq(result, false);
} END_TEST

/* Test 1 NEQ */
START_TEST(NEQ_TC1) {
/* Mengecek NEQ bernilai false apabila kedua POINT sama */
  POINT P1 = MakePOINT(-1, -2);
  POINT P2 = MakePOINT(-1, -2);

  boolean result = NEQ(P1, P2);
  ck_assert_int_eq(result, false);
} END_TEST

/* Test 2 NEQ */
START_TEST(NEQ_TC2) {
/* Mengecek NEQ bernilai true apabila kedua POINT berbeda */
  POINT P1 = MakePOINT(1, 2);
  POINT P2 = MakePOINT(1, -3);

  boolean result = NEQ(P1, P2);
  ck_assert_int_eq(result, true);
} END_TEST

/* Test 1 IsOrigin */
START_TEST(IsOrigin_TC1) {
/* Mengecek IsOrigin bernilai true apabila POINT berada di (0, 0) */
  POINT P = MakePOINT(0, 0);

  boolean result = IsOrigin(P);
  ck_assert_int_eq(result, true);
} END_TEST

/* Test 2 IsOrigin */
START_TEST(IsOrigin_TC2) {
/* Mengecek IsOrigin bernilai false apabila POINT tidak berada di (0, 0) */
  POINT P = MakePOINT(-1, 2);

  boolean result = IsOrigin(P);
  ck_assert_int_eq(result, false);
} END_TEST

/* Test 1 IsOnSbX */
START_TEST(IsOnSbX_TC1) {
/* Mengecek IsOnSbX bernilai True apabila Ordinat(P) == 0 */
  POINT P = MakePOINT(3, 0);

  boolean result = IsOnSbX(P);
  ck_assert_int_eq(result, true);
} END_TEST

/* Test 2 IsOnSbX */
START_TEST(IsOnSbX_TC2) {
/* Mengecek IsOnSbX bernilai False apabila Ordinat(P) != 0 */
  POINT P = MakePOINT(0, 2);

  boolean result = IsOnSbX(P);
  ck_assert_int_eq(result, false);
} END_TEST

/* Test 2 IsOnSbY */
START_TEST(IsOnSbY_TC1) {
/* Mengecek IsOnSbY bernilai True apabila Absis(P) == 0 */
  POINT P = MakePOINT(0, -2);

  boolean result = IsOnSbY(P);
  ck_assert_int_eq(result, true);
} END_TEST

/* Test 2 IsOnSbY */
START_TEST(IsOnSbY_TC2) {
/* Mengecek IsOnSbY bernilai False apabila Absis(P) != 0 */
  POINT P = MakePOINT(-3, 0);

  boolean result = IsOnSbY(P);
  ck_assert_int_eq(result, false);
} END_TEST

/* Test 1 Kuadran */
START_TEST(Kuadran_TC1) {
/* Mengecek Kuadran bernilai -1 apabila absis atau ordinat bernilai 0 */
  POINT P = MakePOINT(-3, 0);

  int result = Kuadran(P);
  ck_assert_int_eq(result, -1);
} END_TEST

/* Test 2 Kuadran */
START_TEST(Kuadran_TC2) {
/* Mengecek Kuadran bernilai 1 apabila absis dan ordinat bernilai positif */
  POINT P = MakePOINT(1, 1);

  int result = Kuadran(P);
  ck_assert_int_eq(result, 1);
} END_TEST

/* Test 3 Kuadran */
START_TEST(Kuadran_TC3) {
/* Mengecek Kuadran bernilai 2 apabila absis negatif dan ordinat positif */
  POINT P = MakePOINT(-1, 2);

  int result = Kuadran(P);
  ck_assert_int_eq(result, 2);
} END_TEST

/* Test 4 Kuadran */
START_TEST(Kuadran_TC4) {
/* Mengecek Kuadran bernilai 3 apabila absis dan ordinat bernilai negatif */
  POINT P = MakePOINT(-3, -4);

  int result = Kuadran(P);
  ck_assert_int_eq(result, 3);
} END_TEST

/* Test 5 Kuadran */
START_TEST(Kuadran_TC5) {
/* Mengecek Kuadran bernilai 4 apabila absis positif dan ordinat negatif */
  POINT P = MakePOINT(4, -3);

  int result = Kuadran(P);
  ck_assert_int_eq(result, 4);
} END_TEST

/* Test 1 NextX */
START_TEST(NextX_TC1) {
/* Mengecek NextX mengembalikan point dari argumen dengan nilai absis bertambah 1 */
  POINT P = MakePOINT(4, -3);
  ck_assert_float_eq(Absis(P), 4);
  ck_assert_float_eq(Ordinat(P), -3);

  POINT result = NextX(P);
  ck_assert_float_eq(Absis(result), 5);
  ck_assert_float_eq(Ordinat(result), -3);
} END_TEST

/* Test 1 NextY */
START_TEST(NextY_TC1) {
/* Mengecek NextY mengembalikan point dari argumen dengan nilai ordinat bertambah 1 */
  POINT P = MakePOINT(4, -3);
  ck_assert_float_eq(Absis(P), 4);
  ck_assert_float_eq(Ordinat(P), -3);

  POINT result = NextY(P);
  ck_assert_float_eq(Absis(result), 4);
  ck_assert_float_eq(Ordinat(result), -2);
} END_TEST

/* Test 1 PlusDelta */
START_TEST(PlusDelta_TC1) {
/* Mengecek PlusDelta mengembalikan point yang berubah sesuai dengan argumen kedua dan ketiga */
  POINT P = MakePOINT(4, -3);
  ck_assert_float_eq(Absis(P), 4);
  ck_assert_float_eq(Ordinat(P), -3);

  POINT result = PlusDelta(P, 1, 2);
  ck_assert_float_eq(Absis(result), 5);
  ck_assert_float_eq(Ordinat(result), -1);

  result = PlusDelta(P, -0.5, -0.25);
  ck_assert_float_eq(Absis(result), 3.5);
  ck_assert_float_eq(Ordinat(result), -3.25);
} END_TEST

/* Test 1 MirrorOf */
START_TEST(MirrorOf_TC1) {
/* Mengecek MirrorOf ketika sumbu sbX bernilai true
   Mengembalikan Point dengan nilai ordinat dikalikan -1 */
  POINT P = MakePOINT(1, 1);
  POINT result = MirrorOf(P, true);

  ck_assert_float_eq(Absis(result), 1);
  ck_assert_float_eq(Ordinat(result), -1);
} END_TEST

/* Test 2 MirrorOf */
START_TEST(MirrorOf_TC2) {
/* Mengecek MirrorOf ketika sumbu sbX bernilai false
   Mengembalikan Point dengan nilai absis dikalikan -1 */
  POINT P = MakePOINT(1, 1);
  POINT result = MirrorOf(P, false);

  ck_assert_float_eq(Absis(result), -1);
  ck_assert_float_eq(Ordinat(result), 1);
} END_TEST

/* Test 1 Jarak0 */
START_TEST(Jarak0_TC1) {
/* Mengecek Jarak0 mengembalikan jarak pythagoras dari P ke (0, 0) */
  POINT P = MakePOINT(1, 1);
  float result = Jarak0(P);

  ck_assert_float_eq(result, sqrt(2));
} END_TEST

/* Test 1 Panjang */
START_TEST(Panjang_TC1) {
/* Mengecek Jarak0 mengembalikan jarak pythagoras dari P1 ke P2 */
  POINT P1 = MakePOINT(1, 1);
  POINT P2 = MakePOINT(2, 2);
  float result = Panjang(P1, P2);

  ck_assert_float_eq(result, sqrt(2));
} END_TEST

/* Test 1 Geser */
START_TEST(Geser_TC1) {
/* Mengecek Geser mengubah Point P sesuai dengan argumen delta X dan delta Y */
  POINT P = MakePOINT(1, 1);
  Geser(&P, 1, -1);

  ck_assert_float_eq(Absis(P), 2);
  ck_assert_float_eq(Ordinat(P), 0);
} END_TEST

/* Test 1 GeserKeSbX */
START_TEST(GeserKeSbX_TC1) {
/* Mengecek GeserKeSbX mengubah Ordinat(P) ke 0 */
  POINT P = MakePOINT(1, 1);
  GeserKeSbX(&P);

  ck_assert_float_eq(Absis(P), 1);
  ck_assert_float_eq(Ordinat(P), 0);
} END_TEST

/* Test 1 GeserKeSbY */
START_TEST(GeserKeSbY_TC1) {
/* Mengecek GeserKeSbY mengubah Absis(P) ke 0 */
  POINT P = MakePOINT(1, 1);
  GeserKeSbY(&P);

  ck_assert_float_eq(Absis(P), 0);
  ck_assert_float_eq(Ordinat(P), 1);
} END_TEST

/* Test 1 Mirror */
START_TEST(Mirror_TC1) {
/* Mengecek Mirror apabila SbX = true dengan mengalikan Ordinat(P) dengan -1 */
  POINT P = MakePOINT(1, 1);
  Mirror(&P, true);

  ck_assert_float_eq(Absis(P), 1);
  ck_assert_float_eq(Ordinat(P), -1);
} END_TEST

/* Test 2 Mirror */
START_TEST(Mirror_TC2) {
/* Mengecek Mirror apabila SbX = false dengan mengalikan Absis(P) dengan -1 */
  POINT P = MakePOINT(1, 1);
  Mirror(&P, false);

  ck_assert_float_eq(Absis(P), -1);
  ck_assert_float_eq(Ordinat(P), 1);
} END_TEST

/* Test 1 Putar */
START_TEST(Putar_TC1) {
/* Mengecek apabila POINT diputar menghasilkan hasil putaran searah jarum jam  */
  float epsilon = 1e-6f;

  POINT P = MakePOINT(1, 1);
  Putar(&P, 90);

  float deltaX = Absis(P) - 1;
  float deltaY = Ordinat(P) - (-1);

  ck_assert_float_lt(deltaX, epsilon);
  ck_assert_float_lt(deltaY, epsilon);
} END_TEST


Suite *point_suite(void) { 
  Suite *s;
  TCase *tc_make, *tc_relational, *tc_posisi, *tc_operasi;

  s = suite_create("Point");

  tc_make = tcase_create("Make");
  tcase_add_test(tc_make, MakePOINT_TC1);
  suite_add_tcase(s, tc_make); 

  tc_relational = tcase_create("Relational");
  tcase_add_test(tc_relational, EQ_TC1);
  tcase_add_test(tc_relational, EQ_TC2);
  tcase_add_test(tc_relational, NEQ_TC1);
  tcase_add_test(tc_relational, NEQ_TC2);
  suite_add_tcase(s, tc_relational);

  tc_posisi = tcase_create("Posisi");
  tcase_add_test(tc_posisi, IsOrigin_TC1);
  tcase_add_test(tc_posisi, IsOrigin_TC2);
  tcase_add_test(tc_posisi, IsOnSbX_TC1);
  tcase_add_test(tc_posisi, IsOnSbX_TC2);
  tcase_add_test(tc_posisi, IsOnSbY_TC1);
  tcase_add_test(tc_posisi, IsOnSbY_TC2);
  tcase_add_test(tc_posisi, Kuadran_TC1);
  tcase_add_test(tc_posisi, Kuadran_TC2);
  tcase_add_test(tc_posisi, Kuadran_TC3);
  tcase_add_test(tc_posisi, Kuadran_TC4);
  tcase_add_test(tc_posisi, Kuadran_TC5);
  suite_add_tcase(s, tc_posisi);

  tc_operasi = tcase_create("Operasi");
  tcase_add_test(tc_operasi, NextX_TC1);
  tcase_add_test(tc_operasi, NextY_TC1);
  tcase_add_test(tc_operasi, PlusDelta_TC1);
  tcase_add_test(tc_operasi, MirrorOf_TC1);
  tcase_add_test(tc_operasi, MirrorOf_TC2);
  tcase_add_test(tc_operasi, Jarak0_TC1);
  tcase_add_test(tc_operasi, Panjang_TC1);
  tcase_add_test(tc_operasi, Geser_TC1);
  tcase_add_test(tc_operasi, GeserKeSbX_TC1);
  tcase_add_test(tc_operasi, GeserKeSbY_TC1);
  tcase_add_test(tc_operasi, Mirror_TC1);
  tcase_add_test(tc_operasi, Mirror_TC2);
  tcase_add_test(tc_operasi, Putar_TC1);
  suite_add_tcase(s, tc_operasi);

  return s;
} 

int main(void) {
  int no_failed = 0;
  Suite *s;
  SRunner *runner;

  s = point_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL); 
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE; 
} 