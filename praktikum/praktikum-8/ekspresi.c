#include "mesintoken.h"
#include "mesinkar.h"
#include "stackt.h"
#include <stdio.h>

int main(){
    STARTTOKEN();
    IgnoreBlank();

    Stack setek, setek2;
    CreateEmpty(&setek);
    CreateEmpty(&setek2);

    int result = 0, finalresult = 0;
    boolean empty = true;

    while (!EndToken){
        result = 0;
        if (empty){
            empty = false;
        }
        if (CToken.tkn == 'b'){
            Push(&setek, CToken.val);
            printf("%d\n", CToken.val);
        } else {
            int A, B;
            if (Top(setek) >= 1){
                Pop(&setek, &B);
                Pop(&setek, &A);
            }
            if (CToken.tkn == '+'){
                result = A+B;
                printf("%d + %d\n%d\n", A, B, result);
            } else if (CToken.tkn == '-'){
                result = A-B;
                printf("%d - %d\n%d\n", A, B, result);
            } else if (CToken.tkn == '*'){
                result = A*B;
                printf("%d * %d\n%d\n", A, B, result);
            } else if (CToken.tkn == '/'){
                result = A/B;
                printf("%d / %d\n%d\n", A, B, result);
            } else if (CToken.tkn == '^'){
                int i;
                int base = 1;
                for (i=0;i<B;i++){
                    base *= A;
                }
                result = base;
                printf("%d ^ %d\n%d\n", A, B, result);
            }
            Push(&setek, result);
            finalresult = result;
        }

        IgnoreBlank();
        ADVTOKEN();
    }

    if (!IsEmpty(setek)){
        Pop(&setek, &result);
    }

    if (empty){
        printf("Ekspresi kosong\n");
    } else {
        printf("Hasil=%d\n", result);
    }
}