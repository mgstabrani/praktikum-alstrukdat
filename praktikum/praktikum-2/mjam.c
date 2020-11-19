#include "jam.h"
#include <stdio.h>

int main(){
    int N = 0, i = 0;
    long waktuMin = 86400, waktuMaks = -1;

    /* Membaca Jumlah Kasus */
    scanf("%d", &N);

    for(i=0; i < N; i++){
        printf("[%d]\n", i+1);
        JAM j1,j2;
        BacaJAM(&j1);
        BacaJAM(&j2);

        /* Mengubah nilai waktu maks / waktu min */
        if (JAMToDetik(j1) > waktuMaks) waktuMaks = JAMToDetik(j1);
        if (JAMToDetik(j2) > waktuMaks) waktuMaks = JAMToDetik(j2);
        if (JAMToDetik(j1) < waktuMin) waktuMin = JAMToDetik(j1);
        if (JAMToDetik(j2) < waktuMin) waktuMin = JAMToDetik(j2);

        printf("%li\n", (JLT(j1, j2)) ? Durasi(j1, j2) : Durasi(j2, j1));
    }
    /* Menulis jam mulai paling awal dan akhir */
    TulisJAM(DetikToJAM(waktuMin)); printf("\n");
    TulisJAM(DetikToJAM(waktuMaks)); printf("\n");
    return 0;
}