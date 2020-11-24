#include "mesintoken.h"
#include "boolean.h"
#include "mesinkar.h"
#include <stdio.h>

boolean EndToken;
Token CToken;

void IgnoreBlank(){
    while (CC == BLANK){
        ADV();
    }
}

void STARTTOKEN(){
    START();
    IgnoreBlank();
    if (CC == MARK){
        EndToken = true;
    } else {
        EndToken = false;
        ADVTOKEN();
    }
}

void ADVTOKEN(){
    IgnoreBlank();
    if(CC == MARK){
        EndToken = true;
    }else{
        SalinToken();
        IgnoreBlank();
    }
}

void SalinToken(){
    int val;
    int i=0;
    int n=0;
    IgnoreBlank();
    if(CC==MARK){
        EndToken = true;
    }else if(CC=='+'||CC=='-'||CC=='*'||CC=='/'||CC=='^'){
        CToken.tkn = CC;
        CToken.val = -1;
        ADV();
    }else{
        CToken.tkn = 'b';
        while(CC != BLANK && CC != MARK && i<NMax){
            switch (CC){
                case '0':
                    val = 0;
                    break;
                case '1':
                    val = 1;
                    break;
                case '2':
                    val = 2;
                    break;
                case '3':
                    val = 3;
                    break;
                case '4':
                    val = 4;
                    break;
                case '5':
                    val = 5;
                    break;
                case '6':
                    val = 6;
                    break;
                case '7':
                    val = 7;
                    break;
                case '8':
                    val = 8;
                    break;
                case '9':
                    val = 9;
                    break;
                default:
                    break;
            }
            n = n*10 + val;
            i++;
            ADV();
        }
        CToken.val = n;
    }
}