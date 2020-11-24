#include "queue.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

boolean IsEmpty (Queue Q){
    return (Head(Q) == Nil && Tail(Q) == Nil);
}

boolean IsFull (Queue Q){
    return ((Tail(Q)+1)%MaxEl(Q) == Head(Q));
}

int NBElmt (Queue Q){
    if (IsEmpty(Q)) return 0;
    return ((Tail(Q) - Head(Q) + MaxEl(Q))%MaxEl(Q))+1;
}

void MakeEmpty (Queue * Q, int Max){
    Queue QTemp;
    QTemp.T = (infotype *) malloc (Max * sizeof(infotype));
    if ((QTemp.T) != NULL){
        MaxEl(QTemp) = Max;
    } else {
        MaxEl(QTemp) = 0;
    }
    Head(QTemp) = Nil;
    Tail(QTemp) = Nil;
    *Q = QTemp;
}

void DeAlokasi(Queue * Q){
    MaxEl(*Q) = 0;
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
    free((*Q).T);
}

void Enqueue (Queue * Q, infotype X){
    if (IsEmpty(*Q)){
        Head(*Q) = 0;
    }
    Tail(*Q) = (Tail(*Q) + 1)%MaxEl(*Q);
    InfoTail(*Q) = X;
}

void Dequeue (Queue * Q, infotype * X){
    *X = InfoHead(*Q);
    if (Head(*Q) == Tail(*Q)){
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        Head(*Q) = (Head(*Q)+1)%MaxEl(*Q);
    }
}