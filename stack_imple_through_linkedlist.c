/******************************************************************************
  local stack implementation through singly linked list.
  Push and pop operations will get performed with passing a data.
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _sll{
    unsigned int data;
    struct _sll *link;
}sll;
sll *head = NULL;

void pop_stack_data(unsigned int data){
    sll *curr = head, *pre = NULL;
    if(head == NULL){
        printf("List is empty\n");
    } else {
        while(curr && (curr->data != data)){
             pre = curr;
             curr = curr->link;
        } 
        if(curr == NULL){
            printf("Given data not found\n");
            return;
        }
        if(curr == head){
            head = head->link;
        } else {
            pre->link = curr->link;
        }
        free(curr);
    }
}

sll* create_node(unsigned int data){
    sll *new_node = calloc(1,sizeof(sll));
    new_node->data = data;
    new_node->link = NULL;
    return new_node;
}
void push_stack_data(unsigned int data){
     sll *new_node = create_node(data), *curr = head;
     if(head == NULL) {
         head = new_node;
     } else {
         /* stack is not empty, add new_node
            at the head and link it */
            new_node->link = head;
            head = new_node;
     }
}
void print_stack_data(){
    sll *curr = head;
    while(curr != NULL){
        printf("%d ",curr->data);
        curr = curr->link;
    }
    printf("\n");
}

int main()
{
    printf("Main funtion\n");
    push_stack_data(10);
    push_stack_data(670);
    push_stack_data(80);
    push_stack_data(40);
    push_stack_data(24);
    push_stack_data(500);
    push_stack_data(4);
    print_stack_data();
    
    pop_stack_data(500);
    print_stack_data();
    return 0;
}
