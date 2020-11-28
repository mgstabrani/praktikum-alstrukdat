#include "listlinier.h"
#include <stdio.h>
#include "boolean.h"
#include <stdlib.h>

int main(){
    List L;
    CreateEmpty(&L);

    int N,i;
    scanf("%d", &N);
    for (i=1;i<=N;i++){
        address a = Alokasi(i);
        InsertLast(&L, a);
    }
    
    int O,X;
    scanf("%d", &O);
    for (i=0;i<O;i++){
        scanf("%d", &X);
        address find = Search(L, X);
        if (find != Nil){
            DelP(&L, X);
            InsVFirst(&L, X);
            printf("hit ");
            PrintInfo(L);
            printf("\n");
        } else {
            address dummy;
            DelLast(&L, &dummy);
            InsVFirst(&L, X);
            printf("miss ");
            PrintInfo(L);
            printf("\n");
        }
    }
    return 0;
}