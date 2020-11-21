#include <stdio.h>
#include "matriks.h"
#include "boolean.h"

void TulisNilaiX (MATRIKS M, indeks j, ElType X);
/*
{ Menuliskan nomor urut mahasiswa yang mendapatkan nilai X pada mata kuliah dengan nomor urut j. }
{ Pada dasarnya: Menuliskan semua indeks baris pada kolom j dengan nilai elemen = X. }
{ Nomor urut mahasiswa dituliskan dalam 1 baris, masing-masing dipisahkan koma, diawali [, diakhiri ], tanpa tambahan karakter apa pun (termasuk spasi dan enter) di awal maupun akhir }
{ I.S. M terdefinisi, j adalah indeks kolom efektif M, X terdefinisi }
{ F.S. Menuliskan semua indeks baris pada kolom j dengan nilai = X.
Jika tidak ada elemen dengan nilai = X, menuliskan [] 
{ Contoh: Jika M adalah matriks 3x3 dan isinya adalah:
1 3 3
2 5 6
7 3 9
maka jika j = 1 dan X = 3, akan tercetak: [0,2]
}*/
void TulisStatistikMhs (MATRIKS M, indeks i);
/*{ Menuliskan statistik untuk mahasiswa dengan nomor urut i. }
{ Statistik yang dituliskan adalah: nilai rata-rata, nilai mata kuliah tertinggi, nilai mata kuliah terendah. }
{ Pada dasarnya: menuliskan statistik untuk data pada baris ke-i }
{ I.S. M terdefinisi, i adalah indeks baris efektif M }
{ F.S. Statistik data M pada baris i tercetak di layar dengan format sbb:4
[i] <rata-rata> <nilai max> <nilai min> }
{ Contoh: Jika M adalah matriks 3x3 dan isinya adalah:
100 83 83
72 55 60
77 93 90
maka jika i = 1 akan tercetak:
[1] 62.33 72 55
}*/
void TulisStatistikMK (MATRIKS M, indeks j);
/*
{ Menuliskan statistik untuk mata kuliah dengan nomor urut j. }
{ Statistik yang dituliskan adalah: nilai rata-rata, nilai tertinggi (berikut berapa banyak yang memperoleh nilai tersebut dan siapa saja yang memperolehnya), nilai mata kuliah terendah (berikut berapa banyak yang memperoleh nilai tersebut dan siapa saja yang memperolehnya). }
{ Pada dasarnya: menuliskan statistik untuk data pada kolom ke-j }
{ I.S. M terdefinisi, j adalah indeks kolom efektif M }
{ F.S. Statistik data M pada baris i tercetak di layar dengan format sbb:4
[j] <rata-rata> [max <nilai max> <#max> [<daftar max>]] [min <nilai min> <#min> [<daftar min>]] }
{ Contoh: Jika M adalah matriks 3x3 dan isinya adalah:
100 83 83
72 55 60
77 93 90
maka jika j = 1 akan tercetak:
[1] 77.00 [93 1 [2]] [55 1 [1]]
}*/

int main(){
    int mhs, matkul;
    scanf("%d", &mhs);
    scanf("%d", &matkul);

    MATRIKS M;
    BacaMATRIKS(&M, mhs, matkul);
    printf("STATISTIK PER MAHASISWA\n");
    int i;

    for(i=GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
        TulisStatistikMhs(M,i);
        printf("\n");
    }

    printf("STATISTIK PER MATA KULIAH\n");
    for(i=GetFirstIdxKol(M); i <= GetLastIdxKol(M); i++){
        TulisStatistikMK(M,i);
        printf("\n");
    }
    return 0;
}

void TulisNilaiX (MATRIKS M, indeks j, ElType X){
    boolean isFirst = true;
    boolean pasangKoma = false;
    int i;

    printf("[");
    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
        if (Elmt(M,i,j) == X){
            printf(((isFirst) ? "%d" : ",%d"), i);
            if (isFirst){
                isFirst = (!isFirst);
            }
        }
    }
    printf("]");
}

void TulisStatistikMhs (MATRIKS M, indeks i){
    int max,min;

    MaxMinBrs(M, i, &max, &min);
    float avg = RataBrs(M, i);

    printf("[%d] %.2f %d %d", i, avg, max, min);
}

void TulisStatistikMK (MATRIKS M, indeks j){
    float avg = RataKol(M, j);
    int max,min;
    MaxMinKol(M,j,&max,&min);
    int cmax = CountXKol(M,j,max);
    int cmin = CountXKol(M,j,min);

    printf("[%d] %.2f [%d %d ", j, avg, max, cmax);
    TulisNilaiX(M,j,max);
    printf("] [%d %d ", min, cmin);
    TulisNilaiX(M,j,min);
    printf("]");
}