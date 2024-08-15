/* Programm to print armstrong numbers between given range */
#include <stdio.h>
void print_armstrong_numbrs(unsigned int min, unsigned int max) {
    unsigned int loop_var, sum = 0,cube = 0, num = 0, mod = 0;
    for(loop_var = min; loop_var <= max; loop_var++) {
        sum = 0;
        num = loop_var;
        while(num > 0) {
            mod =num%10;
            cube = mod*mod*mod;
            sum = sum + cube;
            num /= 10;
        }
        if(loop_var == sum) {
            printf("%d ",loop_var);
        }
    }
}
int main() {
    unsigned int min, max;
    printf("Main : Enter the starting range\n");
    scanf("%d",&min);
    printf("Main : Enter the end range\n");
    scanf("%d",&max);
    if(min < 0 || max < 0) {
        printf("Please enter the valid range to perform the operation\n");
        return 0;
    } else {
        print_armstrong_numbrs(min,max);
    }
    return 0;
}
