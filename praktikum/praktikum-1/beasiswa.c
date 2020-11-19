#include <stdio.h>
#include <stdbool.h>

int main(){
    float ip, potongan;
    
    scanf("%f\n%f", &ip, &potongan);

    if (ip >= 3.5F){
        printf("%d", 4);
    } else if (ip < 3.5F && potongan < 1.0F){
        printf("%d", 1);
    } else if (potongan >= 1.0F && potongan < 5.0F && ip < 3.5){
        if (ip < 2.0F){
            printf("%d", 2);
        } else {
            printf("%d", 3);
        }
    } else {
        printf("%d", 0);
    }
    return 0;
}