#include "mesinkar.h"
#include "mesinkata.h"
#include <stdio.h>

Kata titik;
Kata koma;

boolean IsKataSama(Kata K1, Kata K2){
    boolean result = (K1.Length == K2.Length);
    if (result){
        int i;
        for (i=0; i < K1.Length; i++){
            result = (result && (K1.TabKata[i] == K2.TabKata[i]));
        }
    }
    return result;
}

void initTitikKoma(){
    titik.TabKata[0] = 'T';
    titik.TabKata[1] = 'I';
    titik.TabKata[2] = 'T';
    titik.TabKata[3] = 'I';
    titik.TabKata[4] = 'K';
    titik.Length = 5;

    koma.TabKata[0] = 'K';
    koma.TabKata[1] = 'O';
    koma.TabKata[2] = 'M';
    koma.TabKata[3] = 'A';
    koma.Length = 4;
}

int main(){
    STARTKATA();
    initTitikKoma();

    int regular = 0, panjang = 0, tb = 0;
    boolean first = true;

    while (!EndKata) {
        IgnoreBlank();
        if (!IsKataSama(CKata, titik) && !IsKataSama(CKata, koma)) {
            if (!first && CKata.Length > 0){
                printf(" ");
            }
            first = false;
            regular += (CKata.Length < 10) ? 1 : 0;
            panjang += (CKata.Length >= 10) ? 1 : 0;
            for (int i=0;i<CKata.Length;i++) {
                printf("%c",CKata.TabKata[i]);
            }
        } else if (IsKataSama(CKata, titik)){
            printf(".");
            first = false;
            tb++;
        } else if (IsKataSama(CKata, koma)){
            printf(",");
            first = false;
            tb++;
        }
        IgnoreBlank();
        ADVKATA();
    }
    int price = ((regular*(((regular+panjang+tb) > 10) ? 900 : 1000))+(panjang*(((regular+panjang+tb) > 10) ? 1350 : 1500)));
    printf("\n%d\n%d\n%d\n", regular, panjang, price);
    return 0;
}