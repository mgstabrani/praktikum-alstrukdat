#include <stdio.h>
#include "bintree.h"

void InvertBtree(BinTree *P){
    if(!IsTreeEmpty(*P)){
        InvertBtree(&Left(*P));
        InvertBtree(&Right(*P));
        *P = Tree(Akar(*P),Right(*P),Left(*P));
    }
}