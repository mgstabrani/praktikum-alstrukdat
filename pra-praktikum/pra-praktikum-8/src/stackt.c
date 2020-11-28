#include "boolean.h"
#include <stdio.h>
#include "stackt.h"

void CreateEmpty (Stack *S){
    Stack Stemp;
    Top(Stemp) = Nil;
    int i;
    for(i=0;i<MaxEl;i++){
        Stemp.T[i] = 0;
    }
    *S = Stemp;
}

boolean IsEmpty (Stack S){
    return Top(S) == Nil;
}
boolean IsFull (Stack S){
    return Top(S) == MaxEl-1;
}

void Push (Stack * S, infotype X){
    (Top(*S))++;
    InfoTop(*S) = X;
}

void Pop (Stack * S, infotype* X){
    *X = InfoTop(*S);
    (Top(*S))--;
}