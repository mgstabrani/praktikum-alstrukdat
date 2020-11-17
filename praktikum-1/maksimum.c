#include <stdio.h>

int maks(int a, int b);

int main(){
    int bil1, bil2, bil3, bilmaks;
    scanf("%d\n%d\n%d", &bil1, &bil2, &bil3);
    bilmaks = maks(maks(bil1, bil2), bil3);
    printf("%d", bilmaks);

}

int maks(int a, int b){
    return ((a > b) ? a : b);
}