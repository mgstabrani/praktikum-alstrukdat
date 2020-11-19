#include "garis.h"
#include "point.h"
#include <stdio.h>
#include <math.h>
#include "boolean.h"

void MakeGARIS (POINT P1, POINT P2, GARIS * L){
    L->PAkh = P2; L->PAw = P1;
}

void BacaGARIS (GARIS * L){
    POINT P1; POINT P2;
    BacaPOINT(&P1);
    BacaPOINT(&P2);
    while(EQ(P1, P2)){
        printf("Garis tidak valid\n");
        BacaPOINT(&P1);
        BacaPOINT(&P2);
    }
    MakeGARIS(P1, P2, L);
}
void TulisGARIS (GARIS L) {
    printf("((%.2f,%.2f),(%.2f,%.2f))", L.PAw.X, L.PAw.Y, L.PAkh.X, L.PAkh.Y);
}

float PanjangGARIS (GARIS L){
    return (sqrt(pow((L.PAw.X-L.PAkh.X),2) + pow((L.PAw.Y-L.PAkh.Y),2)));
}

float Gradien (GARIS L){
    return ((L.PAkh.Y-L.PAw.Y)/(L.PAkh.X-L.PAw.X));
}

void GeserGARIS (GARIS * L, float deltaX, float deltaY){
    L->PAkh.X += deltaX;
    L->PAkh.Y += deltaY;
    L->PAw.X += deltaX;
    L->PAw.Y += deltaY;
}

boolean IsTegakLurus (GARIS L1, GARIS L2){
    return (Gradien(L1)*Gradien(L2) == -1);
}

boolean IsSejajar (GARIS L1, GARIS L2){
    return (Gradien(L1) == Gradien(L2));
}