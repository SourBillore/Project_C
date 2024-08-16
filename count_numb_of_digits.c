/* counting num of digit in a given number by recursion */
#include <stdio.h>

unsigned int count_digits(unsigned int numb){
    if (numb){
        return(1+count_digits(numb/10));
    } else {
        return 0;
    }
}

int main() {
    unsigned int num;
    printf("Enter the positive number : ");
    scanf("%d",&num);
    if(num < 0){
        printf("Please enter the positive num\n");
    } else {
        printf("No. of digits in %d is %d",num,count_digits(num));
    }
    return 0;
}
