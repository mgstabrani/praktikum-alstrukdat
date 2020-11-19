#include "jam.h"
#include <stdio.h>

boolean IsJAMValid (int H, int M, int S){
    return ((H >= 0) && (H <= 23) && (M >= 0) && (M <= 59) && (S >= 0) && (S <= 59));
}

JAM MakeJAM (int HH, int MM, int SS){
    JAM j;
    j.HH = HH;
    j.MM = MM;
    j.SS = SS;
    return j;
}

void BacaJAM (JAM * J){
    int H, M, S;
    scanf("%d %d %d", &H, &M, &S);
    while(!IsJAMValid(H, M, S)){
        printf("Jam tidak valid\n");
        scanf("%d %d %d", &H, &M, &S);
    }
    *J = MakeJAM(H, M, S);
}

void TulisJAM (JAM J){
    printf("%d:%d:%d", Hour(J), Minute(J), Second(J));
}

long JAMToDetik (JAM J){
    return (3600L*J.HH + 60L*J.MM + 1L*J.SS);
}

JAM DetikToJAM (long N){
    return MakeJAM(((N % 86400) / 3600), (((N % 86400) % 3600) / 60), (((N % 86400) % 3600) % 60));
}

boolean JEQ (JAM J1, JAM J2){
    return(JAMToDetik(J1) == JAMToDetik(J2));
}

boolean JNEQ (JAM J1, JAM J2){
    return(JAMToDetik(J1) != JAMToDetik(J2));
}

boolean JLT (JAM J1, JAM J2){
    return(JAMToDetik(J1) < JAMToDetik(J2));
}

boolean JGT (JAM J1, JAM J2){
    return(JAMToDetik(J1) > JAMToDetik(J2));
}

JAM NextNDetik (JAM J, int N){
    return DetikToJAM(JAMToDetik(J) + (1L*N));
}

JAM NextDetik (JAM J){
    return NextNDetik(J, 1);
}

JAM PrevNDetik (JAM J, int N){
    return DetikToJAM(JAMToDetik(J) - (1L*N) + 86400L);
}

JAM PrevDetik (JAM J){
    return PrevNDetik(J, 1);
}

long Durasi (JAM JAw, JAM JAkh){
    return((JAMToDetik(JAkh)-JAMToDetik(JAw)+86400)%86400);
}