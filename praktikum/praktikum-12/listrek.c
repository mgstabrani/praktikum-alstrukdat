#include "listrek.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

address Alokasi (infotype X){
    address P;
    P = (address) malloc (sizeof(ElmtList));
    if (P != Nil){
        Info(P) = X;
        Next(P) = Nil;
    }
}

void Dealokasi (address P){
    free(P);
}

int IsEmpty(List L){
    return (L == Nil) ? 1 : 0;
}

int IsOneElmt(List L){
    return (L != Nil && Next(L) == Nil) ? 1 : 0;
}

infotype FirstElmt (List L){
    return Info(L);
}

List Tail(List L){
    if(IsEmpty(L) == 1) return Nil;
    else return Next(L);
}

List Konso(infotype e, List L){
    address P = Alokasi(e);
    if(P != Nil){
        Next(P) = L;
        return P;
    } else{
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
