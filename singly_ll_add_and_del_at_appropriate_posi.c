/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _sll{
    int data;
    struct _sll *next;
}sll;
sll *head = NULL;

void delete_sll(unsigned int data){
    sll *curr = head, *pre = NULL;
    if(head == NULL){
        printf("List is empty\n");
    } else{
        while(curr && (curr->data != data)){
             pre = curr;
             curr = curr->next;
        } 
        if(curr == NULL){
            printf("Given data not found\n");
            return;
        }
        if(curr == head){
            head = head->next;
        } else {
            pre->next = curr->next;
        }
        free(curr);
    }
}

void reverse_sll(){
    sll *pre = NULL, *curr = head, *next = NULL;
    while(curr){
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }
    head = pre;
}
sll* create_node(unsigned int data){
    sll *new_node = calloc(1,sizeof(sll));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
void add_node_to_sll(unsigned int data){
     sll *new_node = create_node(data), *curr = head;
     if(head == NULL) {
         head = new_node;
     } else if(new_node->data < curr->data) {
         new_node->next = head;
         head = new_node;
     } else {
         while(curr->next && (curr->next->data < new_node->data)){
             curr = curr->next;
         }
         new_node->next = curr->next;
         curr->next = new_node;
     }
#if 0
else {
     //add at the last node
     sll *curr = head,*pre;
     while(curr && curr->next){
         curr = curr->next;
     }
     curr->next = new_node;
}
#endif
}
void print_sll(){
    sll *curr = head;
    while(curr != NULL){
        printf("%d ",curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    printf("Hello World\n");
    add_node_to_sll(10);
    add_node_to_sll(670);
    add_node_to_sll(80);
    add_node_to_sll(40);
    add_node_to_sll(24);
    add_node_to_sll(500);
    add_node_to_sll(4);
    print_sll();
    reverse_sll();
    print_sll();
    delete_sll(500);
    print_sll();
    reverse_sll();
    print_sll();

    return 0;
}
