#include "prioqueuechar.h"
#include <stdio.h>

int main(){
    int N=0, i;
    scanf("%d", &N);

    PrioQueueChar Q;
    MakeEmpty(&Q, N);

    infotype e;
    int now = 1;
    for (i=0; i<N; i++){
        
        scanf("%d %c", &Prio(e), &Info(e));

        Enqueue(&Q, e);
        while(Prio(Elmt(Q, Head(Q))) == now){
            Dequeue(&Q, &e);
            printf("%d %c\n", (i+1), Info(e));
            now++;
        }
    }
    return 0;
}