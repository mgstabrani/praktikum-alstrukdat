#include <stdio.h>
#include "boolean.h"
#include "listrek.h"

List delNFromEnd(List L, int n){
    if(NbElmtList(L) == n){
        Dealokasi(L);
        return Tail(L);
    } else{
        return delNFromEnd(Tail(L),n);
    }
}
