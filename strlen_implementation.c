/* Programm to print string length */
#include <stdio.h>
int astrlen(char str[]){
    unsigned int count = 0;
    while(str[count] != '\0'){
        count++;
    }
    return count;
}

int main() {
    char str[50];
    printf("Enter the string : ");
    scanf("%s",&str);
    printf("Length of given string :%d\n",astrlen(str));
    return 0;
}
