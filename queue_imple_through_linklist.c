/******************************************************************************

Local imple of singly linklist to add the elements in queue method.
LIFO(Last IN, first OUT)
Here, dequeue operation gets performed based on the passing value

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _queue{
    unsigned int data;
    struct _queue *next;
}queue;
queue *front = NULL;

void dequeue(unsigned int data){
    queue *curr = front, *pre = NULL;
    if(front == NULL){
        printf("List is empty\n");
    } else {
        while(curr && (curr->data != data)){
             pre = curr;
             curr = curr->next;
        } 
        if(curr == NULL){
            printf("Given data not found\n");
            return;
        }
        if(curr == front){
            front = front->next;
        } else {
            pre->next = curr->next;
        }
        free(curr);
    }
}

queue* create_node(unsigned int data){
    queue *new_node = calloc(1,sizeof(queue));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
void enqueue(unsigned int data){
     queue *new_node = create_node(data), *curr = front;
     if(front == NULL) {
         front = new_node;
     } else {
         /* queue is not empty, add new_node
            at the rear end */
            while(curr->next != NULL){
                curr = curr->next;
            }
            curr->next = new_node;
     }
}
void print_queue_data(){
    queue *curr = front;
    while(curr != NULL){
        printf("%d ",curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    printf("Main funtion\n");
    enqueue(10);
    enqueue(670);
    enqueue(80);
    enqueue(40);
    enqueue(24);
    enqueue(500);
    enqueue(4);
    print_queue_data();
    
    dequeue(24);
    print_queue_data();

    return 0;
}
