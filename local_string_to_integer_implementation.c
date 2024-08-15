/* local atoi (string to integer) implementation */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int local_atoi(char str[]){
    bool invalid_flag = false;
    int num = 0,i = 0,sign;
    while(str[i] != '\0'){
     if(str[i] == '\n' || str[i] == ' '){
         i++;
     }
     sign = (str[i] == '-') ? -1 : 1;
     if(str[i] == '-' || str[i] == '+'){
         i++;
     }
     while(str[i] != '\0'){
         if(str[i] >= '0' && str[i] <= '9'){
             num =num*10 + (str[i++] - '0');
         } else {
             invalid_flag = true;
             break;
         }
     }
     if(invalid_flag){
         printf("Invalid numbers\n");
         break;
     }
    }
    return sign*num;
}

int main() {
    char str[50];
    printf("Enter the string : ");
    scanf("%s",&str);
    printf("local implementation of atoi : %d\n",local_atoi(str));
    return 0;
}
