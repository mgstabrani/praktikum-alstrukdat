#include <stdio.h> 
#include <math.h>
#include "bintree.h"

int main() {
    int N;
    scanf("%d", &N);

    if (N <= 0){
        printf("Jumlah masukan tidak sesuai\n");
        return 0;
    }

    int temp = N;
    while (N % 2 == 0){
        N /= 2;
    }
    if (N != 1){
        printf("Jumlah masukan tidak sesuai\n");
        return 0;
    }
    

    int batas = (temp*2)-1;
    BinTree arr[batas];
    int i, j;
    for (i = 0; i < temp; i++){
        int X;
        scanf("%d", &X);
        BinTree t = Tree(X,Nil,Nil);
        arr[i] = t;
    }

    j = 0;
    while (temp < batas){
        BinTree t1, t2, t;
        t1 = arr[j];
        t2 = arr[j+1];
        t  = Tree((Akar(t1)+Akar(t2)), t1, t2);
        arr[temp] = t;
        j += 2;
        temp += 1;
    }
    PrintTree(arr[batas-1], 2);
}