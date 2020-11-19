#include "point.h"
#include "vector.h"
#include <stdio.h>
#include <math.h>
#include "boolean.h"

VECTOR MakeVector(float x, float y){
    VECTOR v;
    v.X = x;
    v.Y = y;
    return v;
}

void TulisVector(VECTOR v){
    printf("<%.2f,%.2f>", v.X, v.Y);
}

float Magnitude(VECTOR v){
    return (sqrt(pow(v.X,2) + pow(v.Y,2)));
}
VECTOR Add(VECTOR a, VECTOR b){
    VECTOR rs;
    rs.X = a.X + b.X;
    rs.Y = a.Y + b.Y;
    return rs;
}

VECTOR Substract(VECTOR a, VECTOR b){
    VECTOR rs;
    rs.X = a.X - b.X;
    rs.Y = a.Y - b.Y;
    return rs;
}

float Dot(VECTOR a, VECTOR b){
    return a.X * b.X + a.Y * b.Y;
}

VECTOR Multiply(VECTOR v, float s){
    VECTOR rs;
    rs.X = v.X * s;
    rs.Y = v.Y * s;
    return rs;
}