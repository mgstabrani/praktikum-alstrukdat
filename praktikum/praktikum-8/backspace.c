#include <stdio.h>
#include "stackt.h"
#include "boolean.h"

int main(){
    int N,M,i;
    scanf("%d %d", &N, &M);
    Stack SN, SM;

    CreateEmpty(&SN);
    CreateEmpty(&SM);
    for (i=0;i<(N+M);i++){
        int X;
        scanf("%d", &X);
        if (i < N){
            if (X == 0){
                if (Top(SN) != Nil){
                    Pop(&SN, &X);
                    continue;
                }
            } else {
                Push(&SN, X);
            }
        } else {
            if (X == 0){
                if (Top(SM) != Nil){
                    Pop(&SM, &X);
                    continue;
                }
            } else {
                Push(&SM, X);
            }
        }
    }
    int min = (Top(SN) <= Top(SM) ? Top(SN) : Top(SM));
    if (min != -1){
        for (i=0;i<=min;i++){
            int X;
            if (IsEmpty(SN) || IsEmpty(SM)) break;

            if (InfoTop(SN) == InfoTop(SM)){
                Pop(&SN, &X);
                Pop(&SM, &X);
            }
        }
    }
    printf((IsEmpty(SN) && IsEmpty(SM)) ? ("Sama\n") : ("Tidak sama\n"));
    return 0;
}