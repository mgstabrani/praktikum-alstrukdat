#include <stdio.h>

int main(){
    float c;
    char suhu;
    
    scanf("%f\n %c", &c, &suhu);

    if (suhu == 'R'){
        printf("%.2f", 0.8F*c);
    } else if (suhu == 'F') {
        printf("%.2f", 1.8F*c+32);
    } else if (suhu == 'K') {
        printf("%.2f", c+273.15F);
    }

}