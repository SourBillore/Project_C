/* BST Menu based through the recursion 
*  Program have the functions to
*  add/delete/print/search of elements
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct _bst{
    int val;
    struct _bst *left, *right;
}bst;
bst *findmin(bst *node){
    if(node == NULL){
        return NULL;
    } 
    if(node->left) {
        return findmin(node->left);
    } else {
        return node;
    }
}

bst *deleteIntree(bst *node, unsigned int value){
    bst *temp = NULL;
    if(node == NULL){
        printf("Element not found\n");
    } else if(value < node->val){
        node->left = deleteIntree(node->left, value);
    } else if(value > node->val){
        node->right = deleteIntree(node->right, value);
    } else {
        if(node->right && node->left){
            temp = findmin(node->right);
            node->val = temp->val;
            node->right = deleteIntree(node->right, temp->val);
        } else {
            temp = node;
            if(node->left == NULL){
                node = node->right;
            } else if(node->right == NULL){
                node  = node->left;
            }
            free(temp);
        }
    }
    return node;
}

bst *searchIntree(bst *node, unsigned int value) {
    if(node == NULL){
        return NULL;
    } else if(value < node->val){
        searchIntree(node->left,value);
    } else if(value > node->val){
        searchIntree(node->right,value);
    } else {
        return node;
    }
}

void printInorder(bst *head) {
    if(head){
        printInorder(head->left);
        printf("%d ",head->val);
        printInorder(head->right);
    }
}

void addInTree(bst **node, unsigned int value){
    bst *new = NULL;
    if(*node == NULL){
        new = calloc(1, sizeof(bst));
        new->val = value;
        new->left = NULL;
        new->right = NULL;
        *node = new;
    } else if(value < (*node)->val) {
        addInTree(&((*node)->left),value);
    } else if(value > (*node)->val) {
        addInTree(&((*node)->right),value);
    } else {
        printf("cann't have duplicates\n");
    }
    return;
}

int main() {
    printf("Binary search tree through recursion\n");
    printf("Please follow the menu options to add/delete/search/print from tree\n\n");
    bst *root = NULL, *temp = NULL;
    unsigned int ch, value;
    while(1){
        printf("\nEnter your choice:\n");
        printf(" 1 addInTree\n 2 printInorderTree\n 3 searchIntree\n 4 deleteFromTree\n 5 exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1 : printf("Enter the value : \n");
                     scanf("%d",&value);
                     addInTree(&root, value);
                     break;
            case 2 : printInorder(root);
                     break;
            case 3 : printf("Enter value to search : \n");
                     scanf("%d", &value);
                     temp = searchIntree(root,value);
                     if(temp == NULL){
                         printf("Given data not found\n");
                     } else {
                         printf("Details of node : %d\n", temp->val);
                     }
                     break;
            case 4 : printf("Enter value to be deleted : \n");
                     scanf("%d",&value);
                     deleteIntree(root,value);
                     break;
            case 5 : break;
            default : printf("Invalid choice\n"); break;
        }
    }
    return 0;
}
