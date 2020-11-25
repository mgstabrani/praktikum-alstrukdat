#include "listrek.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>

address Alokasi (infotype X){
    address result;
    result = (address) malloc (sizeof(ElmtList));
    if (result != Nil){
        Info(result) = X;
        Next(result) = Nil;
    }
    return result;

}

void Dealokasi (address P){
    free(P);
}

int IsEmpty(List L){
    return ((L == Nil) ? 1 : 0);
}

int IsOneElmt(List L){
    return ((L != Nil && Next(L) == Nil) ? 1 : 0);
}

infotype FirstElmt (List L){
    return Info(L);
}

List Tail(List L){
    if (IsEmpty(L) == 1){
        return Nil;
    } else{
        return Next(L);
    }
}

List Konso(infotype e, List L){
    address X = Alokasi(e);
    if (X != Nil){
        Next(X) = L;
        return X;
    } else {
        return L;
    }
}

List KonsB(List L, infotype e){
    if (IsEmpty(L) == 1){
        return Alokasi(e);
    } else {
        Next(L) = KonsB(Tail(L), e);
        return L;
    }
}

List Copy (List L){
    if (IsEmpty(L) == 1){
        return Nil;
    } else {
        return Konso(FirstElmt(L), Copy(Tail(L))); 
    }
}

void MCopy (List Lin, List *Lout){
    if (IsEmpty(Lin) == 1){
        *Lout = Nil;
    } else {
        List LTemp;
        MCopy(Tail(Lin), &LTemp);
        *Lout = Konso(FirstElmt(Lin), LTemp);
    }
}

List Concat (List L1, List L2){
    if (IsEmpty(L1) == 1) {
        return Copy(L2);
    } else {
        return Konso(FirstElmt(L1), Concat(Tail(L1), L2));
    }
}

void MConcat (List L1, List L2, List *LHsl){
    if (IsEmpty(L1) == 1) {
        *LHsl = Copy(L2);
    } else {
        List LTemp;
        MConcat(Tail(L1), L2, &LTemp);
        *LHsl = Konso(FirstElmt(L1), LTemp);
    }
}

void PrintList (List L){
    if (IsEmpty(L) == 0){
        printf("%d\n", Info(L));
        PrintList(Next(L));
    }
}

int NbElmtList (List L){
    if (IsEmpty(L) == 1){
        return 0;
    } else {
        return 1+NbElmtList(Next(L));
    }
}

boolean Search (List L, infotype X){
    if (IsEmpty(L)){
        return false;
    } else {
        if (Info(L) == X) {
            return true;
        } else {
            return Search(Next(L), X);
        }
    }
}
infotype MaxList (List L){
    if (IsOneElmt(L) == 1){
        return Info(L);
    } else {
        return (Info(L) > MaxList(Tail(L)) ? Info(L) : MaxList(Tail(L)));
    }
}

infotype MinList (List L){
    if (IsOneElmt(L) == 1){
        return Info(L);
    } else {
        return (Info(L) < MinList(Tail(L)) ? Info(L) : MinList(Tail(L)));
    }
}

infotype SumList (List L){
    if (IsEmpty(L) == 1){
        return 0;
    } else {
        return Info(L) + SumList(Tail(L));
    }
}

float AverageList (List L){
    return (SumList(L)*1.0f)/(NbElmtList(L)*1.0f);
}

List InverseList (List L){
    if (IsEmpty(L)) {
        return Nil;
    } else {
        return KonsB(InverseList(Tail(L)), Info(L));
    }
}

void SplitPosNeg (List L, List *L1, List *L2){
    if (IsEmpty(L)) {
        *L1 = Nil;
        *L2 = Nil;
    } else {
        SplitPosNeg(Tail(L), L1, L2);
        if (Info(L) < 0) {
            *L2 = Konso(Info(L), *L2);
        } else {
            *L1 = Konso(Info(L), *L1);
        }
    }
}

void SplitOnX (List L, infotype X, List *L1, List *L2){
    if (IsEmpty(L)){
        *L1 = Nil;
        *L2 = Nil;
    } else {
        SplitOnX(Tail(L), X, L1, L2);
        if(Info(L) >= X){
            *L2 = Konso(Info(L), *L2);
        }else{
            *L1 = Konso(Info(L), *L1);
        }
    }
}

int ListCompare (List L1, List L2){
    if (IsEmpty(L1) && IsEmpty(L2)){
        return 0;
    } else if (IsEmpty(L1) && (!IsEmpty(L2))){
        return -1;
    } else if ((!IsEmpty(L1) && IsEmpty(L2))){
        return 1;
    } else {
        if (Info(L1) < Info(L2)) {
            return -1;
        } else if (Info(L1) > Info(L2)){
            return 1;
        } else {
            return ListCompare(Tail(L1), Tail(L2));
        }
    }
}

boolean IsAllExist (List L1, List L2){
    if (IsEmpty(L1) == 1){
        return false;
    } else if (IsOneElmt(L1) == 1){
        return Search(L2, Info(L1));
    } else {
        return Search(L2, Info(L1)) && IsAllExist(Tail(L1), L2);
    }
}