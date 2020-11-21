#include "check.h"
#include "stdlib.h"
#include "stdio.h"
#include "../src/matriks.h"

void IsiMatriks(MATRIKS *M);
/* I.S. M sembarang */
/* F.S. Terbentuk matriks M berukurang 3*3 dengan elemen pada Elmt(M,i,j) = i*3+j */

void IsiMatriksCustom(MATRIKS *M, int NB, int NK);
/* I.S. M sembarang */
/* F.S. Terbentuk matriks M berukurang NB*NK dengan elemen pada Elmt(M,i,j) = i*3+j */

void IsiMatriksSama(MATRIKS *M);
/* I.S. M sembarang */
/* F.S. Terbentuk matriks M berukurang 3*3 dengan seluruh elemen bernilai 1*/

void IsiMatriksAcak(MATRIKS *M);
/* I.S. M sembarang */
/* F.S. Terbentuk matriks M berukurang 3*3 dengan elemen acak */

void IsiMatriksPenuh(MATRIKS *M);
/* I.S. M sembarang */
/* F.S. Terbentuk matriks M penuh dengan elemen pada Elmt(M,i,j) = i*3+j */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create MATRIKS kosong  */
START_TEST(MakeMATRIKS_TC1) {
// Input: M Sembarang
// Output: M Terinisialisasi dengan ukuran 3
  MATRIKS M;
  MakeMATRIKS(3, 3, &M);
  ck_assert_int_eq(NBrsEff(M), 3);
  ck_assert_int_eq(NKolEff(M), 3);
} END_TEST 

/* ********** SELEKTOR ********** */
START_TEST(IsIdxValid_TC1) {
// Input: (0 0)
// Output: 1
  ck_assert_int_eq(IsIdxValid(0, 0), 1);
} END_TEST

START_TEST(IsIdxValid_TC2) {
// Input: (-1 0)
// Output: 0
  ck_assert_int_eq(IsIdxValid(-1, 0), 0);
} END_TEST


START_TEST(GetFirstIdxBrs_TC1) {
// Input: M sembarang
// Output: BrsMin
  MATRIKS M;
  IsiMatriks(&M);
  ck_assert_int_eq(GetFirstIdxBrs(M), BrsMin);
} END_TEST

START_TEST(GetFirstIdxKol_TC1) {
// Input: M sembarang
// Output: KolMin
  MATRIKS M;
  IsiMatriks(&M);
  ck_assert_int_eq(GetFirstIdxKol(M), KolMin);
} END_TEST

START_TEST(GetLastIdxBrs_TC1) {
// Input: M sembarang
// Output: 2 (NBrsEff(M) - 1)
  MATRIKS M;
  IsiMatriks(&M);
  ck_assert_int_eq(GetLastIdxBrs(M), 2);
} END_TEST

START_TEST(GetLastIdxKol_TC1) {
// Input: M sembarang
// Output: 2 (NKolEff(M) - 1)
  MATRIKS M;
  IsiMatriks(&M);
  ck_assert_int_eq(GetLastIdxKol(M), 2);
} END_TEST

START_TEST(IsIdxEff_TC1) {
// Input: M sembarang
// Output: 1
  MATRIKS M;
  IsiMatriks(&M);
  ck_assert_int_eq(IsIdxEff(M, 0, 0), 1);
} END_TEST

START_TEST(IsIdxEff_TC2) {
// Input: M sembarang
// Output: 0
  MATRIKS M;
  IsiMatriks(&M);
  ck_assert_int_eq(IsIdxEff(M, 3, 3), 0);
} END_TEST

START_TEST(GetElmtDiagonal_TC1) {
// Input: M sembarang
// Output: 8
  MATRIKS M;
  IsiMatriks(&M);
  ck_assert_int_eq(GetElmtDiagonal(M, 2), 8);
} END_TEST

/* ********** Assignment MATRIKS ********** */
START_TEST(CopyMATRIKS_TC1) {
// Input: M1, M2 sembarang
// Output: M1 = M2
  MATRIKS M1, M2;
  indeks i, j;
  IsiMatriksAcak(&M1);
  CopyMATRIKS(M1, &M2);
  for(i = BrsMin; i < BrsMin+3; i++){
    for(j = KolMin; j < KolMin+3; j++){
      ck_assert_int_eq(Elmt(M1, i, j), Elmt(M2, i, j));
    }
  }
} END_TEST

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
START_TEST(TambahMATRIKS_TC1) {
// Input: M1, M2, M3 sembarang
// Output: M3 = M1 + M2
  MATRIKS M1, M2, M3;
  IsiMatriks(&M1);
  IsiMatriks(&M2);
  M3 = TambahMATRIKS(M1, M2);
  ck_assert_int_eq(Elmt(M3, 0, 0), 0);
  ck_assert_int_eq(Elmt(M3, 2, 2), 16);
} END_TEST

START_TEST(KurangMATRIKS_TC1) {
// Input: M1, M2, M3 sembarang
// Output: -8, 8
  MATRIKS M1, M2, M3;
  IsiMatriks(&M1);
  IsiMatriks(&M2);
  Elmt(M2, 0, 0) = 8;
  Elmt(M2, 2, 2) = 0;
  M3 = KurangMATRIKS(M1, M2);
  ck_assert_int_eq(Elmt(M3, 0, 0), -8);
  ck_assert_int_eq(Elmt(M3, 2, 2), 8);
} END_TEST

START_TEST(KaliMATRIKS_TC1) {
// Input: M1, M2, M3 sembarang
// Output: 69, 21
  MATRIKS M1, M2, M3;
  IsiMatriks(&M1);
  IsiMatriks(&M2);
  M3 = KaliMATRIKS(M1, M2);
  ck_assert_int_eq(Elmt(M3, 2, 0), 69);
  ck_assert_int_eq(Elmt(M3, 0, 2), 21);
} END_TEST

START_TEST(KaliMATRIKS_TC2) {
// Input: M1, M2, M3 sembarang
// Output: 42, 262
  MATRIKS M1, M2, M3;
  IsiMatriksCustom(&M1, 3, 4);
  IsiMatriksCustom(&M2, 4, 3);
  M3 = KaliMATRIKS(M1, M2);
  ck_assert_int_eq(Elmt(M3, 0, 0), 42);
  ck_assert_int_eq(Elmt(M3, 2, 2), 262);
} END_TEST

START_TEST(KaliKons_TC1) {
// Input: M1, M2 sembarang
// Output: 0, 15
  MATRIKS M1, M2;
  IsiMatriks(&M1);
  M2 = KaliKons(M1, 3);
  ck_assert_int_eq(Elmt(M2, 0, 0), 0);
  ck_assert_int_eq(Elmt(M2, 1, 2), 15);
} END_TEST

START_TEST(PKaliKons_TC1) {
// Input: M1 sembarang
// Output: 0, 15
  MATRIKS M1;
  IsiMatriks(&M1);
  PKaliKons(&M1, 3);
  ck_assert_int_eq(Elmt(M1, 0, 0), 0);
  ck_assert_int_eq(Elmt(M1, 1, 2), 15);
} END_TEST

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
START_TEST(EQ_TC1) {
// Input: M1, M2 sembarang
// Output: 1
  MATRIKS M1, M2;
  IsiMatriks(&M1);
  IsiMatriks(&M2);
  ck_assert_int_eq(EQ(M1, M2), 1);
} END_TEST

START_TEST(EQ_TC2) {
// Input: M1, M2 sembarang
// Output: 0
  MATRIKS M1, M2;
  IsiMatriks(&M1);
  IsiMatriks(&M2);
  Elmt(M2, BrsMin+2, KolMin+2) -= 1;
  ck_assert_int_eq(EQ(M1, M2), 0);
} END_TEST

START_TEST(NEQ_TC1) {
// Input: M1, M2 sembarang
// Output: 1
  MATRIKS M1, M2;
  IsiMatriksCustom(&M1, 3, 4);
  IsiMatriks(&M2);
  ck_assert_int_eq(NEQ(M1, M2), 1);
} END_TEST

START_TEST(NEQ_TC2) {
// Input: M1, M2 sembarang
// Output: 1
  MATRIKS M1, M2;
  IsiMatriks(&M1);
  IsiMatriks(&M2);
  Elmt(M1, 0, 0) = 10;
  ck_assert_int_eq(NEQ(M1, M2), 1);
} END_TEST

START_TEST(EQSize_TC1) {
// Input: M1, M2 sembarang
// Output: 0
  MATRIKS M1, M2;
  IsiMatriksCustom(&M1, 3, 4);
  IsiMatriks(&M2);
  ck_assert_int_eq(EQSize(M1, M2), 0);
} END_TEST

/* ********** Operasi lain ********** */
START_TEST(NBElmt_TC1) {
// Input: M1 sembarang
// Output: 12
  MATRIKS M1;
  IsiMatriksCustom(&M1, 3, 4);
  ck_assert_int_eq(NBElmt(M1), 12);
} END_TEST

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
START_TEST(IsBujurSangkar_TC1) {
// Input: M sembarang
// Output: 0
  MATRIKS M;
  IsiMatriksCustom(&M, 3, 4);
  ck_assert_int_eq(IsBujurSangkar(M), 0);
} END_TEST

START_TEST(IsBujurSangkar_TC2) {
// Input: M sembarang
// Output: 1
  MATRIKS M;
  IsiMatriks(&M);
  ck_assert_int_eq(IsBujurSangkar(M), 1);
} END_TEST

START_TEST(IsSimetri_TC1) {
// Input: M sembarang
// Output: 0
  MATRIKS M;
  IsiMatriks(&M);
  ck_assert_int_eq(IsSimetri(M), 0);
} END_TEST

START_TEST(IsSimetri_TC2) {
// Input: M sembarang
// Output: 1
  MATRIKS M;
  IsiMatriksSama(&M);
  ck_assert_int_eq(IsSimetri(M), 1);
} END_TEST

START_TEST(IsSatuan_TC1) {
// Input: M sembarang
// Output: 1
  MATRIKS M;
  indeks i,j;
  IsiMatriks(&M);

  for(i = BrsMin; i < BrsMin+3; i++){
    for(j = KolMin; j < KolMin+3; j++){
      Elmt(M, i , j) = (i == j);
    }
  }
  ck_assert_int_eq(IsSatuan(M), 1);
} END_TEST

START_TEST(IsSatuan_TC2) {
// Input: M sembarang
// Output: 0
  MATRIKS M;
  IsiMatriksSama(&M);
  ck_assert_int_eq(IsSatuan(M), 0);
} END_TEST

START_TEST(IsSparse_TC1) {
// Input: M sembarang
// Output: 1
  MATRIKS M;
  indeks i,j;
  IsiMatriksPenuh(&M);

  for(i = BrsMin; i <= BrsMax; i++){
    for(j = KolMin; j <= KolMax; j++){
      Elmt(M, i , j) = (i == BrsMin);
    }
  }
  ck_assert_int_eq(IsSparse(M), 1);
} END_TEST

START_TEST(IsSparse_TC2) {
// Input: M sembarang
// Output: 0
  MATRIKS M;
  IsiMatriksPenuh(&M);
  ck_assert_int_eq(IsSparse(M), 0);
} END_TEST

START_TEST(Inverse1_TC1) {
// Input: M1, M2 sembarang
// Output: 0, -8
  MATRIKS M1, M2;
  IsiMatriks(&M1);
  M2 = Inverse1(M1);
  ck_assert_int_eq(Elmt(M2, 0, 0), 0);
  ck_assert_int_eq(Elmt(M2, 2, 2), -8);
} END_TEST

START_TEST(Determinan_TC1) {
// Input: M sembarang
// Output: -216
  MATRIKS M;
  indeks i,j;
  int val = 1;
  IsiMatriks(&M);
  for(i = BrsMin; i < BrsMin+3; i++){
    for(j = KolMin; j < KolMin+3; j++){
      Elmt(M, i, j) = val*val;
      val++;
    }
  }
  ck_assert_int_eq(Determinan(M), -216);
} END_TEST

START_TEST(PInverse1_TC1) {
// Input: M sembarang
// Output: -8, -6
  MATRIKS M;
  IsiMatriks(&M);
  PInverse1(&M);
  ck_assert_int_eq(Elmt(M, 2, 2), -8);
  ck_assert_int_eq(Elmt(M, 2, 0), -6);
} END_TEST

START_TEST(Transpose_TC1) {
// Input: M1 sembarang
// Output: 7, 6
  MATRIKS M;
  IsiMatriks(&M);
  Transpose(&M);
  ck_assert_int_eq(Elmt(M, 1, 2), 7);
  ck_assert_int_eq(Elmt(M, 0, 2), 6);
} END_TEST


/* ********** SUITE DAN EKSEKUSI ********** */
Suite *arraypos_suite(void) { 
  Suite *s;
  TCase *tc_make, *tc_selektor, *tc_assignment, *tc_aritmatika, *tc_relasional,
        *tc_operasiLain, *tc_testMatriks;

  s = suite_create("MATRIKS");

  tc_make = tcase_create("Make");
  tcase_add_test(tc_make, MakeMATRIKS_TC1);
  suite_add_tcase(s, tc_make); 

  tc_selektor = tcase_create("Selektor");
  tcase_add_test(tc_selektor, IsIdxValid_TC1);
  tcase_add_test(tc_selektor, IsIdxValid_TC2);
  tcase_add_test(tc_selektor, GetFirstIdxBrs_TC1);
  tcase_add_test(tc_selektor, GetFirstIdxKol_TC1);
  tcase_add_test(tc_selektor, GetLastIdxBrs_TC1);
  tcase_add_test(tc_selektor, GetLastIdxKol_TC1);
  tcase_add_test(tc_selektor, IsIdxEff_TC1);
  tcase_add_test(tc_selektor, IsIdxEff_TC2);
  tcase_add_test(tc_selektor, GetElmtDiagonal_TC1);
  suite_add_tcase(s, tc_selektor);

  tc_assignment = tcase_create("Assignment");
  tcase_add_test(tc_assignment, CopyMATRIKS_TC1);
  suite_add_tcase(s, tc_assignment);

  tc_aritmatika = tcase_create("Aritmatika");
  tcase_add_test(tc_aritmatika, TambahMATRIKS_TC1);
  tcase_add_test(tc_aritmatika, KurangMATRIKS_TC1);
  tcase_add_test(tc_aritmatika, KaliMATRIKS_TC1);
  tcase_add_test(tc_aritmatika, KaliMATRIKS_TC2);
  tcase_add_test(tc_aritmatika, KaliKons_TC1);
  tcase_add_test(tc_aritmatika, PKaliKons_TC1);
  suite_add_tcase(s, tc_aritmatika);

  tc_relasional = tcase_create("Relasional");
  tcase_add_test(tc_relasional, EQ_TC1);
  tcase_add_test(tc_relasional, EQ_TC2);
  tcase_add_test(tc_relasional, NEQ_TC1);
  tcase_add_test(tc_relasional, NEQ_TC2);
  tcase_add_test(tc_relasional, EQSize_TC1);
  suite_add_tcase(s, tc_relasional);

  tc_operasiLain = tcase_create("Operasi Lain");
  tcase_add_test(tc_operasiLain, NBElmt_TC1);
  suite_add_tcase(s, tc_operasiLain);

  tc_testMatriks = tcase_create("Test Matriks");
  tcase_add_test(tc_testMatriks, IsBujurSangkar_TC1);
  tcase_add_test(tc_testMatriks, IsBujurSangkar_TC2);
  tcase_add_test(tc_testMatriks, IsSimetri_TC1);
  tcase_add_test(tc_testMatriks, IsSimetri_TC2);
  tcase_add_test(tc_testMatriks, IsSatuan_TC1);
  tcase_add_test(tc_testMatriks, IsSatuan_TC2);
  tcase_add_test(tc_testMatriks, IsSparse_TC1);
  tcase_add_test(tc_testMatriks, IsSparse_TC2);
  tcase_add_test(tc_testMatriks, Inverse1_TC1);
  tcase_add_test(tc_testMatriks, Determinan_TC1);
  tcase_add_test(tc_testMatriks, PInverse1_TC1);
  tcase_add_test(tc_testMatriks, Transpose_TC1);
  suite_add_tcase(s, tc_testMatriks);

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

void IsiMatriks(MATRIKS *M){
/* I.S. M sembarang */
/* F.S. Terbentuk matriks M berukurang 3*3 dengan elemen pada Elmt(M,i,j) = i*3+j */
  int i,j;

  MakeMATRIKS(3, 3, M);
  for(i = BrsMin; i < BrsMin+3; i++){
    for(j = KolMin; j < KolMin+3; j++){
      Elmt(*M, i, j) = i*3 + j;
    }
  }
}

void IsiMatriksCustom(MATRIKS *M, int NB, int NK){
/* I.S. M sembarang */
/* F.S. Terbentuk matriks M berukurang NB*NK dengan elemen pada Elmt(M,i,j) = i*NK +j */
  int i,j;

  MakeMATRIKS(NB, NK, M);
  for(i = BrsMin; i < BrsMin+NB; i++){
    for(j = KolMin; j < KolMin+NK; j++){
      Elmt(*M, i, j) = i*NK + j;
    }
  }
}

void IsiMatriksSama(MATRIKS *M){
/* I.S. M sembarang */
/* F.S. Terbentuk matriks M berukurang 3*3 dengan seluruh elemen bernilai 1*/
  int i,j;

  MakeMATRIKS(3, 3, M);
  for(i = BrsMin; i < BrsMin+3; i++){
    for(j = KolMin; j < KolMin+3; j++){
      Elmt(*M, i, j) = 1;
    }
  }
}

void IsiMatriksAcak(MATRIKS *M){
/* I.S. M sembarang */
/* F.S. Terbentuk matriks M berukurang 3*3 dengan elemen acak */
  int i,j;

  MakeMATRIKS(3, 3, M);
  for(i = BrsMin; i < BrsMin+3; i++){
    for(j = KolMin; j < KolMin+3; j++){
      Elmt(*M, i, j) = i*i - j;
    }
  }
  Elmt(*M, 1, 1) = 10;
  Elmt(*M, 2, 1) = 9;
}

void IsiMatriksPenuh(MATRIKS *M){
/* I.S. M sembarang */
/* F.S. Terbentuk matriks M penuh dengan elemen pada Elmt(M,i,j) = i*3+j */
  int i,j;

  MakeMATRIKS(BrsMax-BrsMin+1, KolMax-KolMin+1, M);
  for(i = BrsMin; i <= BrsMax; i++){
    for(j = KolMin; j <= KolMax; j++){
      Elmt(*M, i, j) = i*3+j;
    }
  }
}