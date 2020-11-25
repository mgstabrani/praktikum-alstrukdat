#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listrek.h"

List delNFromEnd(List L, int n){
    address list_pointer[1000];
    address now = L;
    
    int i = 0;
    while (now != Nil) {
        list_pointer[i] = now;
        now = Tail(now);
        i++;
    }

    list_pointer[i] = Nil;
    Dealokasi(list_pointer[i-n]);

    if (i == n) {
        return Tail(L);
    } else {
        SetNext(list_pointer[i-n-1], list_pointer[i-n+1]);
        return L;
    }
}