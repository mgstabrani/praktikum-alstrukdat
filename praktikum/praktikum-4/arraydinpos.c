#include <stdio.h>
#include <stdlib.h>
#include "arraydinpos.h"
#include "boolean.h"

void MakeEmpty(TabInt *T, int maxel){
   IdxType i;
   (*T).MaxEl = maxel;
   (*T).TI = (int *) malloc(maxel * sizeof(int));
   for(i = IdxMin; i < maxel; i++) {
      Elmt(*T,i) = ValUndef;
   }
}

void Dealokasi(TabInt *T){
   (*T).MaxEl = 0;
   free((*T).TI);
}

int NbElmt(TabInt T){ 
   int i;
   int count = 0;
   for(i = IdxMin; i < T.MaxEl; i++) {
      if (T.TI[i] != ValUndef) {
         count++;
      } else {
         break;
      }
   }
   return count;
}

int MaxElement(TabInt T){ 
   return T.MaxEl;
}

IdxType GetFirstIdx(TabInt T){ 
   return IdxMin;
}

IdxType GetLastIdx(TabInt T){ 
   return (NbElmt(T)-1);
}

boolean IsIdxValid(TabInt T, IdxType i){ 
   return ((i >= 0) && (i <= T.MaxEl-1));
}

boolean IsIdxEff(TabInt T, IdxType i){
   return ((i >= 0) && (i <= NbElmt(T)-1));
}

boolean IsEmpty(TabInt T){
   return (NbElmt(T) == 0);
}

boolean IsFull(TabInt T){
   return (NbElmt(T) == T.MaxEl);
}

void BacaIsi(TabInt *T){
   int N, i;
   scanf("%d",&N);
   while ((N < 0) || (N > MaxElement(*T))) {
      scanf("%d",&N);
   }
   if (N > 0){
      for(i = IdxMin; i < N; i++) {
         scanf("%d", &(Elmt(*T,i)));
      }
   }
}

void TulisIsiTab(TabInt T){
   int i;
   printf("[");
   if (!IsEmpty(T)){
      for (i = IdxMin; i <= GetLastIdx(T)-1; i++){
         printf("%d,", T.TI[i]);
      }
      printf("%d", T.TI[GetLastIdx(T)]);
   }
   printf("]");
}

TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus){
   TabInt newT;
   MakeEmpty(&newT, T1.MaxEl);
   if (plus) {
      for(int i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++) {
         Elmt(newT,i) = Elmt(T1,i) + Elmt(T2,i);
      }
  } else {
      for(int i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++) {
         Elmt(newT,i) = Elmt(T1,i) - Elmt(T2,i);
      }
   }
   return newT;
}

boolean IsEQ(TabInt T1, TabInt T2){ 
   int i = IdxMin;
   boolean isSame = true;
   if (NbElmt(T1) == NbElmt(T2)) {
      while (i <= GetLastIdx(T1) && isSame) {
         if (Elmt(T1,i) == Elmt(T2,i)) {
            i++;
         } else {
         isSame = false;
         }
      }
   } else {
      isSame = false;
   }
   return isSame;
}

IdxType Search1(TabInt T, ElType X){
   int i = IdxMin;
   int idx = ValUndef;
   boolean isSame = false;
   if (IsEmpty(T)) {
      return idx;
   } else {
      while (i <= GetLastIdx(T) && !isSame) {
         if (Elmt(T,i) == X) {
            isSame = true;
            idx = i;
         } else {
            i++;
         }
      }
      return idx;
   }
}

boolean SearchB(TabInt T, ElType X){
   int i = IdxMin;
   boolean found = false;
   while(!found && i <= GetLastIdx(T)){
      found = ((Elmt(T,i) == X));
      i++;
   }
   return found;
}

void MaxMin(TabInt T, ElType *Max, ElType *Min){
   *Min = Elmt(T,0);
   *Max = Elmt(T,0);
   for(int i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
      if (Elmt(T,i) > *Max) {
         *Max = Elmt(T,i);
      }
      if (Elmt(T,i) < *Min) {
         *Min = Elmt(T,i);
      }
   }
}

void CopyTab(TabInt Tin, TabInt *Tout){
   TabInt newT;
   IdxType i;
   MakeEmpty(&newT,Tin.MaxEl);
   for(i = 0; i <= GetLastIdx(Tin); i++) {
      Elmt(newT,i) = Elmt(Tin,i);
   }
   *Tout = newT;
}

ElType SumTab(TabInt T){
   IdxType i;
   int sum = 0;
   for(i = 0; i <= GetLastIdx(T); i++){
      sum += Elmt(T,i);
   }
   return sum;
}

int CountX(TabInt T, ElType X)
{
   IdxType i;
   int count = 0;
   for(i = 0; i <= GetLastIdx(T); i++) {
      if(Elmt(T,i) == X) {
         count += 1;
      }
   }
   return count;
}

boolean IsAllGenap(TabInt T){
   int i = IdxMin;
   boolean allgenap = true;
   while(allgenap && i <= GetLastIdx(T)){
        allgenap = (allgenap && (Elmt(T,i)%2 == 0));
        i++;
   }
   return allgenap;
}

void Sort(TabInt *T, boolean asc){
   IdxType i, j;
   int temp;
   for (i = GetFirstIdx(*T) + 1; i <= GetLastIdx(*T); i++){
      temp = Elmt(*T, i);
      j = i-1;
      while (j >= GetFirstIdx(*T) && ((!asc && Elmt(*T,j) < temp) || (asc && Elmt(*T,j) > temp))){
         Elmt(*T,j+1) = Elmt(*T, j);
         j--;
      }
      Elmt(*T,j+1) = temp;
   }
}

void AddAsLastEl(TabInt *T, ElType X){
   if (!IsFull(*T)) {
      (*T).TI[(GetLastIdx(*T)+1)] = X;
   }
}

void DelLastEl(TabInt *T, ElType *X){
   if (!IsEmpty(*T)) {
      *X = (*T).TI[(GetLastIdx(*T))];
      (*T).TI[(GetLastIdx(*T))] = ValUndef;
   }
}

void GrowTab(TabInt *T, int num){ 
   TabInt newT;
   IdxType i;
   MakeEmpty(&newT,(*T).MaxEl+num);
   for(i = 0; i <= GetLastIdx(*T); i++) {
      Elmt(newT,i) = Elmt(*T,i);
   }
   Dealokasi(T);
   *T = newT;
}

void ShrinkTab(TabInt *T, int num){
   TabInt newT;
   IdxType i;
   MakeEmpty(&newT,(*T).MaxEl-num);
   for(i = 0; i <= GetLastIdx(*T); i++) {
      Elmt(newT,i) = Elmt(*T,i);
   }
   Dealokasi(T);
   *T = newT;
}

void CompactTab(TabInt *T){
   TabInt newT;
   IdxType i;
   MakeEmpty(&newT,NbElmt(*T));
   for(i = 0; i <= GetLastIdx(*T); i++) {
      Elmt(newT,i) = Elmt(*T,i);
   }
   Dealokasi(T);
   *T = newT;
}