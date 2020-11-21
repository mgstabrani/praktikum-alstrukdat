#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "arraydin.h"

// Prosedur yang dipakai pada program ini
void lakukanOperasi(TabInt *T);
void tampilkan(TabInt T);
boolean operasi1(TabInt *T, int X);
boolean operasi2(TabInt *T, int X);
boolean operasi3(TabInt *T, int X);
boolean operasi4(TabInt *T);

int main(){
    TabInt T;
    int maxel, Q;
    
    //Membuat TabInt dengan ukuran maxel
    scanf("%d", &maxel);
    MakeEmpty(&T, maxel);

    //Mengisi TabInt
    BacaIsi(&T);

    //Melakukan Operasi
    scanf("%d", &Q);
    int i;
    for (i = 0; i < Q; i++){
        lakukanOperasi(&T);
    }
    return 0;
}

// Prosedur melakukan operasi
void lakukanOperasi(TabInt *T){
    int op, X;
    scanf("%d", &op);
    boolean r = false;
    switch (op){
        case 1:
            scanf("%d", &X);
            r = operasi1(T, X);
            break;
        case 2:
            scanf("%d", &X);
            r = operasi2(T, X);
            break;
        case 3:
            scanf("%d", &X);
            r = operasi3(T, X);
            break;
        case 4:
            r = operasi4(T);
            break;
        default:
            break;
    }
    if (r){
        tampilkan(*T);
    }
    return;
}

void tampilkan(TabInt T){
    printf("%d ", T.MaxEl);
    TulisIsiTab(T); printf("\n");
    return;
}

// Fungsi operasi pertama
boolean operasi1(TabInt *T, int X){
    if (IsFull(*T)){
        printf("array sudah penuh\n");
        return false;
    } else {
        AddAsLastEl(T, X);
        return true;
    }
}

// Fungsi operasi kedua
boolean operasi2(TabInt *T, int X){
    GrowTab(T, X);
    return true;
}

// Fungsi operasi ketiga
boolean operasi3(TabInt *T, int X){
    if (T->MaxEl < X){
        printf("array terlalu kecil\n");
        return false;
    } else {
        ShrinkTab(T, X);
        return true;
    }
}

// Fungsi operasi keempat
boolean operasi4(TabInt *T){
    CompactTab(T);
    return true;
}