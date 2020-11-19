#include "check.h"
#include "stdlib.h"
#include "stdio.h"
#include "../src/arraypos.h"

void IsiTabel(TabInt *T);
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T dengan 3 elemen pertama berupa 1, 2, dan 3 */

void IsiTabelElemenSama(TabInt *T);
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T dengan 3 elemen bernilai 2 */

void IsiTabelAcak(TabInt *T);
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T dengan 5 elemen acak */

void IsiTabelPenuh(TabInt *T);
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T dengan 100 elemen dari 1 hingga 100 */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
START_TEST(MakeEmpty_TC1) {
// Input: T Sembarang
// Output: Semua elemen T 
  TabInt T1;
  MakeEmpty(&T1);
  IdxType i;
  for (i = IdxMin; i <= IdxMax; i++) {
    ck_assert_int_eq(ValUndef, Elmt(T1, i));
  }
} END_TEST 

/* ********** SELEKTOR (TAMBAHAN) ********** */
START_TEST(NbElmt_TC1) {
// Input: T Kosong
// Output: 0
  TabInt T1;
  MakeEmpty(&T1);
  ck_assert_int_eq(0, NbElmt(T1));
} END_TEST

START_TEST(NbElmt_TC2) {
// Input: T berisi 3 elemen
// Output: 3
  TabInt T1;
  IsiTabel(&T1);
  ck_assert_int_eq(3, NbElmt(T1));
} END_TEST

START_TEST(MaxNbEl_TC1) {
// Input: T berisi 3 elemen
// Output: IdxMax
  TabInt T1;
  MakeEmpty(&T1);
  ck_assert_int_eq((IdxMax + 1), MaxNbEl(T1));
} END_TEST

START_TEST(GetFirstIdx_TC1) {
// Input: T berisi 3 elemen
// Output: IdxMin
  TabInt T1;
  IsiTabel(&T1);
  ck_assert_int_eq(IdxMin, GetFirstIdx(T1));
} END_TEST

START_TEST(GetLastIdx_TC1) {
// Input: T berisi 3 elemen
// Output: 2
  TabInt T1;
  IsiTabel(&T1);
  ck_assert_int_eq(2, GetLastIdx(T1));
} END_TEST

START_TEST(IsIdxValid_TC1) {
// Input: T sembarang, Index antara Idx Min ke Idx Max
// Output: true
  TabInt T1;
  ck_assert_int_eq(true, IsIdxValid(T1, IdxMin));
} END_TEST

START_TEST(IsIdxValid_TC2) {
// Input: T sembarang, Index antara Idx Min ke Idx Max
// Output: false
  TabInt T1;
  ck_assert_int_eq(false, IsIdxValid(T1, -1));
} END_TEST

START_TEST(IsIdxEff_TC1) {
// Input: T berisi 3 elemen, Index 3
// Output: true
  TabInt T1;
  IsiTabel(&T1);
  ck_assert_int_eq(true, IsIdxEff(T1, 2));
} END_TEST

START_TEST(IsIdxEff_TC2) {
// Input: T berisi 3 elemen, Index -1
// Output: false
  TabInt T1;
  IsiTabel(&T1);
  ck_assert_int_eq(false, IsIdxEff(T1, -1));
} END_TEST

START_TEST(IsEmpty_TC1) {
// Input: T kosong
// Output: true
  TabInt T1;
  MakeEmpty(&T1);
  ck_assert_int_eq(true, IsEmpty(T1));
} END_TEST

START_TEST(IsEmpty_TC2) {
// Input: T berisi 3 elemen
// Output: false
  TabInt T1;
  IsiTabel(&T1);
  ck_assert_int_eq(false, IsEmpty(T1));
} END_TEST

START_TEST(IsFull_TC1) {
// Input: T berisi 3 elemen
// Output: false
  TabInt T1;
  IsiTabel(&T1);
  ck_assert_int_eq(false, IsFull(T1));
} END_TEST

START_TEST(IsFull_TC2) {
// Input: T berisi IdxMax elemen
// Output: true
  TabInt T1;
  IsiTabelPenuh(&T1);
  ck_assert_int_eq(true, IsFull(T1));
} END_TEST

/* ********** OPERATOR ARITMATIKA ********** */
START_TEST(PlusMinusTab_TC1) {
// Input: T1 berisi tabel 3 elemen, T2 berisi tabel kosong, true
// Output: T1
  TabInt T1, T2, TResult;
  IsiTabel(&T1);
  MakeEmpty(&T2);
  TResult = PlusMinusTab(T1, T2, true);
  int i;

  for(i = GetFirstIdx(TResult); i <= GetLastIdx(TResult); i++) {
    ck_assert_int_eq(Elmt(T1, i), Elmt(TResult, i));
  }
} END_TEST

START_TEST(PlusMinusTab_TC2) {
// Input: T1 berisi tabel 3 elemen, T2 berisi tabel 3 elemen, true
// Output: Penjumlahan T1 dan T2
  TabInt T1, T2, TResult;
  IsiTabel(&T1);
  IsiTabel(&T2);
  TResult = PlusMinusTab(T1, T2, true);
  int i;
  
  for(i = GetFirstIdx(TResult); i <= GetLastIdx(TResult); i++) {
    ck_assert_int_eq(Elmt(T1, i) + Elmt(T2, i), Elmt(TResult, i));
  }
} END_TEST

START_TEST(PlusMinusTab_TC3) {
// Input: T1 berisi tabel 3 elemen, T2 berisi tabel kosong, false
// Output: T1
  TabInt T1, T2, TResult;
  IsiTabel(&T1);
  MakeEmpty(&T2);
  TResult = PlusMinusTab(T1, T2, false);
  int i;
  
  for(i = GetFirstIdx(TResult); i <= GetLastIdx(TResult); i++) {
    ck_assert_int_eq(i + 1, Elmt(TResult, i));
  }
} END_TEST

/* ********** OPERATOR RELASIONAL ********** */
START_TEST(IsEQ_TC1) {
// Input: T1 dan T2 dengan elemen sama
// Output: true
  TabInt T1, T2;
  IsiTabel(&T1);
  IsiTabel(&T2);
  ck_assert_int_eq(true, IsEQ(T1, T2));
} END_TEST

START_TEST(IsEQ_TC2) {
// Input: T1 dan T2 dengan elemen berbeda
// Output: false
  TabInt T1, T2;
  IsiTabel(&T1);
  MakeEmpty(&T2);
  ck_assert_int_eq(false, IsEQ(T1, T2));
} END_TEST

/* ********** SEARCHING ********** */
START_TEST(Search1_TC1) {
// Input: T1 dengan 3 elemen, ElType salah satu elemen di T1
// Output: Index elemen tersebut
  TabInt T1;
  IsiTabel(&T1);
  ck_assert_int_eq(0, Search1(T1, 1));
} END_TEST

START_TEST(Search1_TC2) {
// Input: T1 dengan 3 elemen, ElType bukan salah satu elemen di T1
// Output: IdxUndef
  TabInt T1;
  IsiTabel(&T1);
  ck_assert_int_eq(IdxUndef, Search1(T1, 4));
} END_TEST

START_TEST(Search1_TC3) {
// Input: T1 tabel kosong, ElType sembarang
// Output: IdxUndef
  TabInt T1;
  MakeEmpty(&T1);
  ck_assert_int_eq(IdxUndef, Search1(T1, 1));
} END_TEST

START_TEST(SearchB_TC1) {
// Input: T1 dengan 3 elemen, ElType salah satu elemen T1
// Output: true
  TabInt T1;
  IsiTabel(&T1);
  ck_assert_int_eq(true, SearchB(T1, 1));
} END_TEST

START_TEST(SearchB_TC2) {
// Input: T1 dengan 3 elemen, ElType bukan salah satu elemen T1
// Output: true
  TabInt T1;
  IsiTabel(&T1);
  ck_assert_int_eq(false, SearchB(T1, 4));
} END_TEST

/* ********** NILAI EKSTREM ********** */
START_TEST(MaxMin_TC1) {
// Input: T1 dengan 3 elemen, 2 buah ElType sembarang
// Output: 1 nilai maksimum, 1 nilai minimum
  TabInt T1;
  ElType Max, Min;
  IsiTabel(&T1);
  
  MaxMin(T1, &Max, &Min);
  ck_assert_int_eq(1, Min);
  ck_assert_int_eq(3, Max);
} END_TEST

START_TEST(MaxMin_TC2) {
// Input: T1 dengan 100 elemen, 2 buah ElType sembarang
// Output: 1 nilai maksimum, 1 nilai minimum
  TabInt T1;
  ElType Max, Min;
  IsiTabelPenuh(&T1);
  
  MaxMin(T1, &Max, &Min);
  ck_assert_int_eq(1, Min);
  ck_assert_int_eq(100, Max);
} END_TEST

/* ********** OPERASI LAIN ********** */
START_TEST(SumTab_TC1) {
// Input: T1 Kosong
// Output: 0
  TabInt T1;
  MakeEmpty(&T1);
  ck_assert_int_eq(0, SumTab(T1));
} END_TEST

START_TEST(SumTab_TC2) {
// Input: T1 berisi 3 elemen
// Output: 6
  TabInt T1;
  IsiTabel(&T1);
  ck_assert_int_eq(6, SumTab(T1));
} END_TEST

START_TEST(CountX_TC1) {
// Input: T1 kosong, ElType sembarang
// Output: 0
  TabInt T1;
  MakeEmpty(&T1);
  ck_assert_int_eq(0, CountX(T1, 2));
} END_TEST

START_TEST(CountX_TC2) {
// Input: T1 berisi 3 elemen, ElType merupakan elemen T1
// Output: Jumlah elemen tersebut
  TabInt T1;
  IsiTabelElemenSama(&T1);
  ck_assert_int_eq(3, CountX(T1, 2));
} END_TEST

START_TEST(CountX_TC3) {
// Input: T1 berisi 3 elemen, ElType bukan merupakan elemen T1
// Output: Jumlah elemen tersebut
  TabInt T1;
  IsiTabelElemenSama(&T1);
  ck_assert_int_eq(0, CountX(T1, 3));
} END_TEST

START_TEST(IsAllGenap_TC1) {
// Input: T1 berisi 3 elemen yang semuanya genap
// Output: true
  TabInt T1;
  IsiTabelElemenSama(&T1);
  ck_assert_int_eq(true, IsAllGenap(T1));
} END_TEST

START_TEST(IsAllGenap_TC2) {
// Input: T1 berisi 3 elemen yang sebagian tidak genap
// Output: false
  TabInt T1;
  IsiTabel(&T1);
  ck_assert_int_eq(false, IsAllGenap(T1));
} END_TEST

START_TEST(IsAllGenap_TC3) {
// Input: T1 kosong
// Output: true
  TabInt T1;
  MakeEmpty(&T1);
  ck_assert_int_eq(true, IsAllGenap(T1));
} END_TEST

/* ********** SORTING ********** */
START_TEST(Sort_TC1) {
// Input: T1 berisi 5 elemen acak, true
// Output: T1 terurut membesar
  TabInt T1;
  int i;
  IsiTabelAcak(&T1);
  Sort(&T1, true);
  for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++) {
    ck_assert_int_eq(i + 1, Elmt(T1, i));
  }
} END_TEST

START_TEST(Sort_TC2) {
// Input: T1 berisi 5 elemen acak, false
// Output: T1 terurut mengecil
  TabInt T1;
  int i;
  IsiTabelAcak(&T1);
  Sort(&T1, false);
  for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++) {
    ck_assert_int_eq(GetLastIdx(T1) - i + 1, Elmt(T1, i));
  }
} END_TEST

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
START_TEST(AddAsLastEl_TC1) {
// Input: T1 berisi 3 elemen, ElType sembarang
// Output: T1 dengan bertambah 1 elemen ElType
  TabInt T1;
  IsiTabel(&T1);
  int firstIdx = GetFirstIdx(T1);
  int lastIdx = GetLastIdx(T1);
  int i;

  AddAsLastEl(&T1, 4);

  ck_assert_int_eq(lastIdx + 1, GetLastIdx(T1));
  for (i = firstIdx; i <= (lastIdx + 1); i++) {
    ck_assert_int_eq(i + 1, Elmt(T1, i));
  }
} END_TEST

START_TEST(DelLastEl_TC1) {
// Input: T1 berisi 3 elemen, ElType sembarang
// Output: T1 kehilangan 1 elemen ElType, X berisi ElType elemen terakhir
  TabInt T1;
  IsiTabel(&T1);
  int firstIdx = GetFirstIdx(T1);
  int lastIdx = GetLastIdx(T1);
  int X, i;

  DelLastEl(&T1, &X);

  ck_assert_int_eq(lastIdx - 1, GetLastIdx(T1));
  for (i = firstIdx; i <= (lastIdx - 1); i++) {
    ck_assert_int_eq(i + 1, Elmt(T1, i));
  }
  ck_assert_int_eq(3, X);
} END_TEST


/* ********** SUITE DAN EKSEKUSI ********** */
Suite *arraypos_suite(void) { 
  Suite *s;
  TCase *tc_make, *tc_selektor, *tc_aritmatika,
        *tc_relasional, *tc_searching, *tc_nilaiEkstrem,
        *tc_operasiLain, *tc_sorting, *tc_operasiElemen;

  s = suite_create("ArrayPos");

  tc_make = tcase_create("Make");
  tcase_add_test(tc_make, MakeEmpty_TC1);
  suite_add_tcase(s, tc_make); 

  tc_selektor = tcase_create("Selektor");
  tcase_add_test(tc_selektor, NbElmt_TC1);
  tcase_add_test(tc_selektor, NbElmt_TC2);
  tcase_add_test(tc_selektor, MaxNbEl_TC1);
  tcase_add_test(tc_selektor, GetFirstIdx_TC1);
  tcase_add_test(tc_selektor, GetLastIdx_TC1);
  tcase_add_test(tc_selektor, IsIdxValid_TC1);
  tcase_add_test(tc_selektor, IsIdxValid_TC2);
  tcase_add_test(tc_selektor, IsIdxEff_TC1);
  tcase_add_test(tc_selektor, IsIdxEff_TC2);
  tcase_add_test(tc_selektor, IsEmpty_TC1);
  tcase_add_test(tc_selektor, IsEmpty_TC2);
  tcase_add_test(tc_selektor, IsFull_TC1);
  tcase_add_test(tc_selektor, IsFull_TC2);
  suite_add_tcase(s, tc_selektor);

  tc_aritmatika = tcase_create("Aritmatika");
  tcase_add_test(tc_aritmatika, PlusMinusTab_TC1);
  tcase_add_test(tc_aritmatika, PlusMinusTab_TC2);
  tcase_add_test(tc_aritmatika, PlusMinusTab_TC3);
  suite_add_tcase(s, tc_aritmatika);

  tc_relasional = tcase_create("Relasional");
  tcase_add_test(tc_relasional, IsEQ_TC1);
  tcase_add_test(tc_relasional, IsEQ_TC2);
  suite_add_tcase(s, tc_relasional);

  tc_searching = tcase_create("Searching");
  tcase_add_test(tc_searching, Search1_TC1);
  tcase_add_test(tc_searching, Search1_TC2);
  tcase_add_test(tc_searching, Search1_TC3);
  tcase_add_test(tc_searching, SearchB_TC1);
  tcase_add_test(tc_searching, SearchB_TC2);
  suite_add_tcase(s, tc_searching);

  tc_nilaiEkstrem = tcase_create("Nilai Ekstrem");
  tcase_add_test(tc_nilaiEkstrem, MaxMin_TC1);
  tcase_add_test(tc_nilaiEkstrem, MaxMin_TC2);
  suite_add_tcase(s, tc_nilaiEkstrem);

  tc_operasiLain = tcase_create("Operasi Lain");
  tcase_add_test(tc_operasiLain, SumTab_TC1);
  tcase_add_test(tc_operasiLain, SumTab_TC2);
  tcase_add_test(tc_operasiLain, CountX_TC1);
  tcase_add_test(tc_operasiLain, CountX_TC2);
  tcase_add_test(tc_operasiLain, CountX_TC3);
  tcase_add_test(tc_operasiLain, IsAllGenap_TC1);
  tcase_add_test(tc_operasiLain, IsAllGenap_TC2);
  tcase_add_test(tc_operasiLain, IsAllGenap_TC3);
  suite_add_tcase(s, tc_operasiLain);

  tc_sorting = tcase_create("Sorting");
  tcase_add_test(tc_sorting, Sort_TC1);
  tcase_add_test(tc_sorting, Sort_TC2);
  suite_add_tcase(s, tc_sorting);

  tc_operasiElemen = tcase_create("Operasi Elemen");
  tcase_add_test(tc_operasiElemen, AddAsLastEl_TC1);
  tcase_add_test(tc_operasiElemen, DelLastEl_TC1);
  suite_add_tcase(s, tc_operasiElemen);

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

void IsiTabel(TabInt *T) {
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T dengan 3 elemen pertama berupa 1, 2, dan 3 */
  MakeEmpty(T);
  Elmt(*T, IdxMin) = 1;
  Elmt(*T, IdxMin + 1) = 2;
  Elmt(*T, IdxMin + 2) = 3;
}

void IsiTabelElemenSama(TabInt *T) {
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T dengan 3 elemen bernilai 2 */
  MakeEmpty(T);
  Elmt(*T, IdxMin) = 2;
  Elmt(*T, IdxMin + 1) = 2;
  Elmt(*T, IdxMin + 2) = 2;
}

void IsiTabelAcak(TabInt *T) {
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T dengan 5 elemen acak */
  MakeEmpty(T);
  Elmt(*T, IdxMin) = 2;
  Elmt(*T, IdxMin + 1) = 3;
  Elmt(*T, IdxMin + 2) = 5;
  Elmt(*T, IdxMin + 3) = 1;
  Elmt(*T, IdxMin + 4) = 4;
}

void IsiTabelPenuh(TabInt *T) {
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T dengan 100 elemen dari 1 hingga 100 */
  MakeEmpty(T);
  int i;
  for (i = IdxMin; i <= IdxMax; i++) {
    Elmt(*T, i) = i + 1;
  }
}