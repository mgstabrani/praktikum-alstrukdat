#include <stdio.h>
#include "boolean.h"
#include "arraypos.h"

int main(){
    TabInt T;
    BacaIsi(&T);
    int X = -1, maks = -1, min = -1;
    scanf("%d", &X);
    TulisIsiTab(T);printf("\n");
    if (SearchB(T, X)){
        printf("%d\n", Search1(T, X));
        MaxMin(T, &maks, &min);
        Sort(&T, true);

        // Maksimum
        if (X == maks){
            printf("maksimum\n");
        }

        // Minimum
        if (X == min){
            printf("minimum\n");
        }

        // Median
        int median = 0;
        if (NbElmt(T) % 2 == 0){
            median = ((NbElmt(T))/2)-1;
        } else {
            median = ((NbElmt(T))/2);
        }

        if (Elmt(T, median) == X && median >= 0){
            printf("median\n");
        }
    } else {
        printf("%d tidak ada\n", X);
    }
    return 0;
}