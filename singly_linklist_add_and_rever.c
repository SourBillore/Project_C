// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
typedef struct st {
    int data;
    struct st *next;
}list;

list *head = NULL;
list * createnode(int data_){
    list *new = calloc (1, sizeof(struct st));
    new->data = data_;
    new->next = NULL;
    return new;
}
void addlinkedlist(int data)
{
    list *newNode = createnode(data);
    printf("addlinkedlist\n");
    if(head == NULL) {
        head = newNode;
    } else {
        list *curr = head;
        list *pre = NULL;
        while(curr != NULL){
            pre = curr;
            curr = curr->next;
        }
        pre->next = newNode;
    }
}
void printlist()
{
    list *curr = head;
    while(curr != NULL)
    {
        printf("printList :%d\n", curr->data);
        curr = curr->next;
    }
}
list* reverselist(list *head)
{
    list *pre = NULL, *curr = head, *nxt = NULL;
    while(curr != NULL)
    {
        nxt = curr->next;
        curr->next = pre;
        pre = curr;
        curr = nxt;
    }
    printf("reverse list\n");
    return pre;
}
int main() {
    // Write C code here
    printf("main\n");
    addlinkedlist(10);
    addlinkedlist(20);
    addlinkedlist(30);
    addlinkedlist(40);
    printlist();
    head = reverselist(head);
    printlist();

    return 0;
}
