#include "listlinier.h"
#include <stdio.h>
#include "boolean.h"
#include <stdlib.h>

int main(){
    List L;
    CreateEmpty(&L);

    int i;
    for (i=1;i<=5;i++){
        address a = Alokasi(i);
        InsertLast(&L, a);
    }

    PrintInfo(L);
    List L2 = FInversList(L);
    PrintInfo(L);
    PrintInfo(L2);
    return 0;
}