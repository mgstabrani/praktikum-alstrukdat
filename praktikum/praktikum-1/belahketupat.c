#include <stdio.h>
#include <stdbool.h>

bool IsValid(int x);
void GambarBelahKetupat(int x);

int main(){
    int n;
    
    scanf("%d", &n);
    if (IsValid(n) != true) {
        printf("Masukan tidak valid");
        return 0;
    }
    GambarBelahKetupat(n);
    return 0;
}

bool IsValid(int x){
    return ((x % 2 == 1) && (x > 0));
}

void GambarBelahKetupat(int x){
    if (x == 1){
        printf("*");
        return;
    }
    int i,j;

    for(i = 1; i <= x; i++) {
        if (i % 2 == 0) continue;
        for(j = 1; j <= (x-i)/2; j++)
            printf(" ");

        for(j = 1; j <= i; j++)
            printf("*");

        printf("\n");
    }
    for(i = 1; i <= x; i++) {
        if (i % 2 == 1) continue;
        for(j = 1; j <= i/2; j++)
            printf(" ");

        for(j = 1; j <= x-i; j++)
            printf("*");


        printf("\n");
    }
}