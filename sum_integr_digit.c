/* Programm to do sum of given integer with goto keyword*/
#include <stdio.h>

void sum_of_interger_digit(unsigned int integr)
{
    unsigned int sum = 0,rm,digit = integr;
    ADD : if(integr > 0) {
        rm = integr%10;
        integr = integr/10;
        sum = sum + rm;
        goto ADD;
    }
    printf("The sum of given interger : %d is : %d\n",digit,sum);
    #if 0
    // Using loop
      unsigned int sum = 0,rm,digit = integr, loop_var = 0;
        while(loop_var < digit){
            rm = digit%10;
            digit = digit/10;
            sum += rm;
        }
    #endif
}

int main() {
    printf("main\n");
    unsigned int integr;
    printf("Enter the positive integer\n");
    scanf("%d",&integr);
    printf("Entered Integer is : %d\n",integr);
    sum_of_interger_digit(integr);
    return 0;
}
