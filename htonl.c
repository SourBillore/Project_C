/* Programm to check the host byte order, if its little endian,
   than change it into network byte ordering */
#include <stdio.h>
void htonl(unsigned long int data) {
    unsigned long int var = 1;
    char temp, *ptr = (char *)&var;
    if(*ptr == 1) { //Its little endian
        ptr = (char *)&data;
        temp = *ptr;
        *ptr = *(ptr+3);
        *(ptr+3) = temp;
        temp = *(ptr+1);
        *(ptr+1) = *(ptr+2);
        *(ptr+2) = temp;
    }
    printf("Network byte ordering : %x",data);
    return;
}
int main() {
    unsigned long int data;
    printf("Main : Enter the integer:");
    scanf("%x",&data);
    printf("Entered int number : %x\n",data);
    if(data < 0) {
        printf("Please enter the positive number\n");
        return 0;
    } else {
      //host to network byte order
        htonl(data);
    }
    return 0;
}
