#include "jam.h"
#include <stdio.h>

int main(){
    JAM jam;
    printf("\nMasukkan Jam A: ");
    BacaJAM(&jam);
    TulisJAM(jam);
    printf("\nJam A to detik: %li\n", JAMToDetik(jam));

    JAM jam2;
    printf("\nMasukkan Jam B: ");
    BacaJAM(&jam2);
    TulisJAM(jam2);
    
    long waktu = 0;
    printf("\nMasukkan Jam C: ");
    scanf("%li", &waktu);
    TulisJAM(DetikToJAM(waktu));

    if (JEQ(jam, jam2)) printf("\n\n\nJam A == Jam B");
    if (JNEQ(jam, jam2)) printf("\nJam A != Jam B");
    if (JLT(jam, jam2)) printf("\nJam A < Jam B");
    if (JGT(jam, jam2)) printf("\nJam A > Jam B");

    printf("\nSatu detik kemudian untuk jam A:\n");
    jam = NextDetik(jam);
    TulisJAM(jam);


    printf("\nLima detik kemudian untuk jam B:\n");
    jam2 = NextNDetik(jam2, 5);
    TulisJAM(jam2);

    //Mengembalikan ke semula
    jam = PrevDetik(jam);
    jam2 = PrevNDetik(jam2, 5);

    printf("\nDurasi dari Jam A ke Jam B: %li\n", Durasi(jam, jam2));
    return 0;
}