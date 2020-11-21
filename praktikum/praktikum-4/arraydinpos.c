#include <stdio.h>
#include <stdlib.h>
#include "arraydinpos.h"
#include "boolean.h"

void MakeEmpty(TabInt *T, int maxel){
    T->MaxEl = maxel;
    T->TI = (int *) malloc(maxel * sizeof(int));
    IdxType i;
    for(i=IdxMin; i < maxel; i++){
        T->TI[i] = ValUndef;
    }
    return;
}

void Dealokasi(TabInt *T){
    T->MaxEl = 0;
    free((T->TI));
}

int NbElmt(TabInt T){
    int i=IdxMin;
    while(i<T.MaxEl && T.TI[i]!=ValUndef){
        i++;
    }
    return i;
}

int MaxElement(TabInt T){
    return T.MaxEl;
}

IdxType GetFirstIdx(TabInt T){
    return IdxMin;
}

IdxType GetLastIdx(TabInt T){
    return NbElmt(T)-1;
}

boolean IsIdxValid(TabInt T, IdxType i){
    return (i >= 0 && i < T.MaxEl);
}

boolean IsIdxEff(TabInt T, IdxType i){
    return (i >= GetFirstIdx(T) && i <= GetLastIdx(T));
}

boolean IsEmpty(TabInt T){
    return (NbElmt(T) == 0);
}

boolean IsFull(TabInt T){
    return (NbElmt(T) == T.MaxEl);
}

void BacaIsi(TabInt *T){
    
    int N;
    while (true){
        scanf("%d\n", &N);
        if (N >= 0 && N <= MaxElement(*T)){
            break;
        }
    }

    if (N > 0){
        IdxType i;
        for(i=GetFirstIdx(*T); i <= GetLastIdx(*T); i++){
            scanf("%d\n", &(T->TI[i]));
        }
    }

    return;
}

void TulisIsiTab(TabInt T){
    printf("[");
    if (!IsEmpty(T)){
        int i;
        for (i=GetFirstIdx(T); i <= GetLastIdx(T); i++){
            printf("%d", T.TI[i]);
            
            if (i != GetLastIdx(T)){
                printf(",");
            }
        }
    }
    printf("]");
    return;
}

TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus){
    if (NbElmt(T1) < NbElmt(T2)){
        return PlusMinusTab(T2, T1, plus);
    }
    TabInt T3;
    MakeEmpty(&T3, T1.MaxEl);
    
    IdxType i;
    for(i=GetFirstIdx(T3); i <=GetLastIdx(T3); i++){
        T3.TI[i] = T1.TI[i] + (T2.TI[i] * (plus ? 1 : -1));
        if ((!plus) && T3.TI[i] <= 0){
            T3.TI[i] = T1.TI[i];
        }
    }
    return T3;
}

boolean IsEQ(TabInt T1, TabInt T2){
    boolean equal = (NbElmt(T1) == NbElmt(T2));

    IdxType i;
    for(i=GetFirstIdx(T1); i <=GetLastIdx(T1); i++){
        if (i > GetLastIdx(T2) || !equal){
            break;
        }

        equal = (equal && (T1.TI[i] == T2.TI[i]));
    }
    return equal;
}

IdxType Search1(TabInt T, ElType X){
    if (IsEmpty(T)){
        return IdxUndef;
    }

    int i,result=IdxUndef;
    for(i=GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if (Elmt(T, i) == X){
            result = i;
            break;
        } 
    }
    return result;
}

boolean SearchB(TabInt T, ElType X){
    if (IsEmpty(T)){
        return false;
    }
    boolean found = false;
    int i;
    for(i=GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if (Elmt(T, i) == X){
            found = true;
            break;
        } 
    }
    return found;
}

void MaxMin(TabInt T, ElType *Max, ElType *Min){
    
    int i;
    *Min = Elmt(T, GetFirstIdx(T));
    *Max = Elmt(T, GetFirstIdx(T));

    for(i=GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if (Elmt(T,i) > *Max){
            *Max = Elmt(T,i);
        } else if (Elmt(T,i) < *Min) {
            *Min = Elmt(T,i);
        }
    }
    return;
}

void CopyTab(TabInt Tin, TabInt *Tout){
    TabInt TResult;
    MakeEmpty(&TResult, Tin.MaxEl);

    IdxType i;
    for(i=GetFirstIdx(Tin); i <= GetLastIdx(Tin); i++){
        Elmt(TResult, i) = Elmt(Tin, i);
    }
    *Tout = TResult;
}

ElType SumTab(TabInt T){
    if (IsEmpty(T)){
        return 0;
    }

    int i,sum = 0;
    for(i=GetFirstIdx(T); i <= GetLastIdx(T); i++){
        sum += Elmt(T,i);
    }
    return sum;
}

int CountX(TabInt T, ElType X){
    if (IsEmpty(T)){
        return 0;
    }
    int i,count=0;
    for(i=GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if(Elmt(T,i) == X){
            count += 1; 
        }
    };
    return count;
}

boolean IsAllGenap(TabInt T){
    boolean genap = true;
    int i = GetFirstIdx(T);
    while(genap && i <= GetLastIdx(T)){
        genap = (genap && (Elmt(T,i)%2 == 0));
        i++;
    }
    return genap;
}

void Sort(TabInt *T, boolean asc){
    int i, j;
    IdxType key;

    for (i = GetFirstIdx(*T) + 1; i <= GetLastIdx(*T); i++){
        key = Elmt(*T, i);
        j = i-1;
        while (j >= GetFirstIdx(*T) && ((!asc && Elmt(*T,j) < key) || (asc && Elmt(*T,j) > key))){
            Elmt(*T,j+1) = Elmt(*T, j);
            j--;
        }
        Elmt(*T,j+1) = key;
    }
    return;
}

void AddAsLastEl(TabInt *T, ElType X){
    if (!IsFull(*T)) {
        T->TI[(GetLastIdx(*T)+1)] = X;
    }
    return;
}

void DelLastEl(TabInt *T, ElType *X){
    if (IsEmpty(*T)) return;

    *X = T->TI[GetLastIdx(*T)];
    T->TI[GetLastIdx(*T)] = ValUndef;
    return;
}

void GrowTab(TabInt *T, int num){
    TabInt TNew;
    MakeEmpty(&TNew, ((T->MaxEl)+num));

    IdxType i;
    for(i=GetFirstIdx(*T); i <= GetLastIdx(*T); i++){
        Elmt(TNew, i) = Elmt((*T), i);
    }
    Dealokasi(T);
    *T = TNew;
}

void ShrinkTab(TabInt *T, int num){
    TabInt TNew;
    MakeEmpty(&TNew, ((T->MaxEl)-num));

    IdxType i;
    for(i=GetFirstIdx(TNew); i <= GetLastIdx(TNew); i++){
        Elmt(TNew, i) = Elmt((*T), i);
    }
    Dealokasi(T);
    *T = TNew;
}

void CompactTab(TabInt *T){
    TabInt TNew;
    MakeEmpty(&TNew, NbElmt(*T));

    IdxType i;
    for(i=GetFirstIdx(TNew); i <= GetLastIdx(TNew); i++){
        Elmt(TNew, i) = Elmt((*T), i);
    }
    Dealokasi(T);
    *T = TNew;
}