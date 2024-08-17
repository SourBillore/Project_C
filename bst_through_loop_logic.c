/* 
*  Binary search tree implementation through loop logic
*  Funt's : add, delete and print are implementated
*  Description : The tree can add upto 10 elements as 
*  kept loop value hardcoded and can delete the existing
*  key as per the user input.
* 
* Note : Print func will print only in pre-oder way and
*        not in all the format - in-order or post-order.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_KEY_ELEMENT 10

typedef struct _bst{
  unsigned int key;
  struct _bst *left,*right;
}bst;
bst *root = NULL;

/* Function to find the minimum value node in the BST iteratively */
bst* find_min(bst* node) {
    while (node && node->left != NULL) {
        node = node->left;
    }
    return node;
}
void delete_key_from_bst(unsigned int bst_key) {
    bst *curr = root, *pre = NULL;
    if(root == NULL){
        printf("The tree is empty\n");
        return;
    } else {
        while(curr != NULL && curr->key != bst_key){
            pre = curr;
            if(bst_key < curr->key) {
                curr = curr->left;
            } else if(bst_key > curr->key) {
                curr = curr->right;
            }
        }
        
        if((curr->left == NULL) && (curr->right == NULL)) {
            if(pre == NULL) {
                free(root);
                root = NULL;
            } else if(curr == pre->left) {
                pre->left = NULL;
            } else {
                pre->right = NULL;
            }
            free(curr);
        } else if((curr->left == NULL) || (curr->right == NULL)){
            bst *new_node = NULL;
            if(curr->left == NULL){
                new_node = curr->right;
            } else {
                new_node = curr->left;
            }
            
            if(pre == NULL){
                root = new_node;
            } else if(curr == pre->left) {
                pre->left = new_node;
            } else {
                pre->right = new_node;
            }
            free(curr);
        } else {
            bst* successor = find_min(curr->right);
            int val = successor->key;
            
            delete_key_from_bst(successor->key);

            curr->key = val;
        }
    }
}

bst* create_key_posi(unsigned int bst_key){
    bst *new_node = calloc(1, sizeof(bst));
    new_node->key = bst_key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
void add_key_to_bst(unsigned int bst_key) {
    bst *new_key = create_key_posi(bst_key);
    bst *curr = root, *pre = NULL;
    if(root == NULL){
        root = new_key;
        return;
    } else {
        while(curr != NULL){
            pre = curr;
            if(bst_key < curr->key) {
                curr = curr->left;
            } else if(bst_key > curr->key) {
                curr = curr->right;
            } else {
                printf("Can't add duplicate entry\n");
                return;
            }
        }
    }
    if(bst_key < pre->key){
        pre->left = new_key;
    } else {
        pre->right = new_key;
    }
    return;
}
void print_bst(){
    bst *curr = root;
    bst* stack[10];
    int top = -1;

    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }

        curr = stack[top--];
        printf("Key: %u ", curr->key);

        curr = curr->right;
    }
}

int main() {
    unsigned int key, i = 0;
    char ch;
    while( i < MAX_KEY_ELEMENT) {
        printf("Enter the %dth :  ",i);
        scanf("%d",&key);
        if(key < 0){
            printf("Please enter the positive key\n");
        } else {
            add_key_to_bst(key);
            i++;
        }
    }
    print_bst();
    printf("\n");
    printf("Do you want to delete any key?? Answer Y or N : ");
    getchar();
    scanf("%c",&ch);
    if(ch == 'Y' || ch == 'y') {
        printf("Please enter the existing key to be deleted : ");
        scanf("%d",&key);
        delete_key_from_bst(key);
    }
    print_bst();
    return 0;
};
