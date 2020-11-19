#include "check.h"
#include "stdio.h"
#include "stdlib.h"
#include "../src/listrek.h"

address AlokasiCheck (infotype X) {
  address P = (address) malloc (sizeof(ElmtList));
  if (P != NULL) {
    Info(P) = X;
    Next(P) = Nil;
  }

  return P;
}

void CreateEmptyCheck (List *L) {
     *L = Nil;
}

List KonsBCheck(List L, infotype e)
/* Mengirimkan list L dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */ 
{
     if (IsEmpty(L)) {
          return AlokasiCheck(e);
     }
     else {
          Next(L) = KonsB(Next(L),e);
          return L;
     }
}

// Check ALokasi
START_TEST(Alokasi_TC1) {
  infotype X = 2;
  address P = Alokasi(X);
  ck_assert_int_eq(Info(P), X);
  ck_assert_ptr_eq(Next(P), Nil);
} END_TEST

//  Check Dealokasi
START_TEST(Dealokasi_TC1) {
  infotype X = 2;
  address P = AlokasiCheck(X);
  // Dealokasi, seems impossible to be tested, so just check if no runtime error
  Dealokasi(P);
} END_TEST

// Check IsEmpty
START_TEST(IsEmpty_TC1) {
  List L;
  CreateEmptyCheck(&L);
  ck_assert_int_eq(1, IsEmpty(L));
  L = KonsBCheck(L, 100);
  ck_assert_int_eq(0, IsEmpty(L));
} END_TEST

// Check IsOneElmt
START_TEST(IsOneElmt_TC1) {
     List L;
     CreateEmptyCheck(&L);
     ck_assert_int_eq(0, IsOneElmt(L));
     L = KonsBCheck(L,100);
     ck_assert_int_eq(1, IsOneElmt(L));
} END_TEST

// Check FirstElmt
START_TEST(FirstElmt_TC1) {
     List L;
     CreateEmptyCheck(&L);
     L = KonsBCheck(L,100);
     ck_assert_int_eq(100, FirstElmt(L));
} END_TEST

// Check Tail
START_TEST(Tail_TC1) {
     List L, LCheck, P;
     CreateEmptyCheck(&L);
     CreateEmptyCheck(&LCheck);
     L = KonsBCheck(L,1);
     L = KonsBCheck(L,2);
     L = KonsBCheck(L,3);
     LCheck = KonsBCheck(LCheck,2);
     LCheck = KonsBCheck(LCheck,3);
     P = Tail(L);
     while (!IsEmpty(P)) {
          ck_assert_int_eq(Info(P),Info(LCheck));
          P = Next(P);
          LCheck = Next(LCheck);
     }
} END_TEST

// Check Konso
START_TEST(Konso_TC1) {
     List L, LCheck;
     CreateEmptyCheck(&L);
     CreateEmptyCheck(&LCheck);
     L = KonsBCheck(L,1);
     L = KonsBCheck(L,2);
     L = KonsBCheck(L,3);
     LCheck = KonsBCheck(LCheck,2);
     LCheck = KonsBCheck(LCheck,3);
     LCheck = Konso(1,LCheck);
     while (!IsEmpty(L)) {
          ck_assert_int_eq(Info(L),Info(LCheck));
          L = Next(L);
          LCheck = Next(LCheck);
     }
} END_TEST

// Check KonsB
START_TEST(KonsB_TC1) {
     List L, LCheck;
     CreateEmptyCheck(&L);
     CreateEmptyCheck(&LCheck);
     L = KonsBCheck(L,1);
     L = KonsBCheck(L,2);
     L = KonsBCheck(L,3);
     LCheck = KonsBCheck(LCheck,1);
     LCheck = KonsBCheck(LCheck,2);
     LCheck = KonsB(LCheck,3);
     while (!IsEmpty(L)) {
          ck_assert_int_eq(Info(L),Info(LCheck));
          L = Next(L);
          LCheck = Next(LCheck);
     }
} END_TEST

// Check Copy
START_TEST(Copy_TC1) {
     List L,LCheck;
     CreateEmptyCheck(&L);
     L = KonsBCheck(L,1);
     L = KonsBCheck(L,2);
     L = KonsBCheck(L,3);
     LCheck = Copy(L);
     while (!IsEmpty(L)) {
          ck_assert_int_eq(Info(L),Info(LCheck));
          L = Next(L);
          LCheck = Next(LCheck);
     }
} END_TEST

// Check MCopy

START_TEST(MCopy_TC1) {
     List L,LCheck;
     CreateEmptyCheck(&L);
     CreateEmptyCheck(&LCheck);
     L = KonsBCheck(L,1);
     L = KonsBCheck(L,2);
     L = KonsBCheck(L,3);
     MCopy(L,&LCheck);
     while (!IsEmpty(L)) {
          ck_assert_int_eq(Info(L),Info(LCheck));
          L = Next(L);
          LCheck = Next(LCheck);
     }
} END_TEST

// Check Concat
START_TEST(Concat_TC1) {
     List L,LCheck, LConcat;
     CreateEmptyCheck(&L);
     CreateEmptyCheck(&LCheck);
     L = KonsBCheck(L,1);
     L = KonsBCheck(L,2);
     L = KonsBCheck(L,3);
     LCheck = KonsBCheck(LCheck,4);
     LCheck = KonsBCheck(LCheck,5);
     LConcat = Concat(L,LCheck);
     int i = 1;
     while (!IsEmpty(LConcat)) {
          ck_assert_int_eq(Info(LConcat),i);
          LConcat = Next(LConcat);
          i++;
     }
} END_TEST

// Check MConcat
START_TEST(MConcat_TC1) {
     List L,LCheck, LConcat;
     CreateEmptyCheck(&L);
     CreateEmptyCheck(&LCheck);
     CreateEmptyCheck(&LConcat);
     L = KonsBCheck(L,1);
     L = KonsBCheck(L,2);
     L = KonsBCheck(L,3);
     LCheck = KonsBCheck(LCheck,4);
     LCheck = KonsBCheck(LCheck,5);
     MConcat(L,LCheck,&LConcat);
     int i = 1;
     while (!IsEmpty(LConcat)) {
          ck_assert_int_eq(Info(LConcat),i);
          LConcat = Next(LConcat);
          i++;
     }
} END_TEST

// Check PrintList
START_TEST(PrintList_T1) {
     List L;
     int i;
     CreateEmptyCheck(&L);
     for (i = 1; i <= 8; i++) {
          L = KonsBCheck(L, i);
     }
     PrintList(L);
} END_TEST

// Check NbElmtList
START_TEST(NbElmtList_TC1) {
     List L;
     int i = 2;
     CreateEmptyCheck(&L);
     L = KonsBCheck(L,1);
     L = KonsBCheck(L,2);
     ck_assert_int_eq(i, NbElmtList(L));
     L = KonsBCheck(L,3);
     i++;
     ck_assert_int_eq(i, NbElmtList(L));
} END_TEST

// Check Search
START_TEST(Search_TC1) {
     List L;
     CreateEmptyCheck(&L);
     L = KonsBCheck(L,1);
     L = KonsBCheck(L,2);
     L = KonsBCheck(L,3);
     ck_assert_int_eq(1, Search(L,2));
     ck_assert_int_eq(0, Search(L,4));
} END_TEST


/* ********** SUITE DAN EKSEKUSI ********** */
Suite *listrek_suite(void) { 
  Suite *s;
  TCase *tc_prototype, *tc_memory, *tc_search, *tc_primitif, *tc_proses;
  s = suite_create("List Rekursif");

  tc_prototype = tcase_create("Prototype");
  tcase_add_test(tc_prototype, IsEmpty_TC1);
  tcase_add_test(tc_prototype, IsOneElmt_TC1);
  tcase_add_test(tc_prototype, FirstElmt_TC1);
  tcase_add_test(tc_prototype, Tail_TC1);
  tcase_add_test(tc_prototype, NbElmtList_TC1);
  suite_add_tcase(s, tc_prototype);

  tc_memory = tcase_create("Memory");
  tcase_add_test(tc_memory, Alokasi_TC1);
  tcase_add_test(tc_memory, Dealokasi_TC1);
  suite_add_tcase(s, tc_memory);

  tc_search = tcase_create("Search");
  tcase_add_test(tc_search, Search_TC1);
  suite_add_tcase(s, tc_search);

  tc_primitif = tcase_create("Primitif");
  tcase_add_test(tc_primitif, Konso_TC1);
  tcase_add_test(tc_primitif, KonsB_TC1);
  tcase_add_test(tc_primitif, Copy_TC1);
  tcase_add_test(tc_primitif, MCopy_TC1);
  tcase_add_test(tc_primitif, Concat_TC1);
  tcase_add_test(tc_primitif, MConcat_TC1);
  suite_add_tcase(s, tc_primitif);

  tc_proses = tcase_create("Proses");
  tcase_add_test(tc_proses, PrintList_T1);
  suite_add_tcase(s, tc_proses);

  return s;
} 

int main(void) {
  int no_failed = 0;
  Suite *s;
  SRunner *runner;

  s = listrek_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL); 
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}