#include <stdio.h>
#include <math.h>
#include "point.h"

POINT MakePOINT (float X, float Y){
    POINT pp;
    pp.X = X;
    pp.Y = Y;
    return pp;
}

void BacaPOINT (POINT * P) {
    float x,y;
    scanf("%f %f", &x, &y);
    *P = MakePOINT(x,y);
}

void TulisPOINT (POINT P){
    printf("(%.2f,%.2f)", P.X, P.Y);
}

boolean EQ (POINT p1, POINT p2){
    return ((p1.X == p2.X) && (p1.Y == p2.Y));
}

boolean NEQ (POINT p1, POINT p2){
    return (!EQ(p1,p2));
}

boolean IsOnSbX (POINT P){
    return (P.Y == 0);
}

boolean IsOnSbY (POINT P){
    return (P.X == 0);
}

boolean IsOrigin (POINT P){
    return IsOnSbX(P) && IsOnSbY(P);
}

int Kuadran (POINT p){
    int kuadran = -1;
    if (p.X > 0 && p.Y > 0) kuadran = 1;
    if (p.X < 0 && p.Y > 0) kuadran = 2;
    if (p.X < 0 && p.Y < 0) kuadran = 3;
    if (p.X > 0 && p.Y < 0) kuadran = 4;
    return kuadran;
}

POINT NextX (POINT P){
    POINT result;
    result.X = P.X + 1;
    result.Y = P.Y;
    return result;
}

POINT NextY (POINT P){
    POINT result;
    result.X = P.X;
    result.Y = P.Y + 1;
    return result;
}

POINT PlusDelta (POINT P, float deltaX, float deltaY){
    POINT result;
    result.X = P.X + deltaX;
    result.Y = P.Y + deltaY;
    return result;
}

POINT MirrorOf (POINT P, boolean SbX){
    POINT result;
    result.X = (SbX) ? P.X : -1*(P.X);
    result.Y = (SbX) ? -1*(P.Y) : P.Y;
    return result;
}

float Jarak0 (POINT P){
    return (sqrt(pow(P.X,2) + pow(P.Y,2)));
}

float Panjang (POINT P1, POINT P2){
    return Jarak0(PlusDelta(P2, -Absis(P1), -Ordinat(P1)));
}

void Geser (POINT *P, float deltaX, float deltaY){
    P->X += deltaX;
    P->Y += deltaY;
}

void GeserKeSbX (POINT *P){
    P->Y = 0;
}

void GeserKeSbY (POINT *P){
    P->X = 0;
}

void Mirror (POINT *P, boolean SbX){
    P->X = (SbX) ? P->X : -1*(P->X);
    P->Y = (SbX) ? -1*(P->Y) : P->Y;
}

void Putar (POINT *P, float s){
    float Sudut = -(s/180)*acos(-1);
    float x = P->X, y = P->Y;
    P->X = (cos(Sudut)*x)-(sin(Sudut)*y);
    P->Y = (sin(Sudut)*x)+(cos(Sudut)*y);
}