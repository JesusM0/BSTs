#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node Node;

struct Node{
    int data;
    Node * left;
    Node * right;
};

Node * createNode(int data){
    Node * newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

Node * insertBST(Node * root, Node * newNode){
    printf("Inside insert\n");
    if(!root){
        printf("Inserted as root\n");
        return newNode;
    }

    if(newNode->data < root->data){
        printf("going left\n");
        root->left = insertBST(root->left, newNode);
    }
    else if(newNode->data > root->data){
        printf("going right\n");
        root->right = insertBST(root->right, newNode);
    }
    else{
        printf("%d is already in the BST\n", newNode->data);
    }
    return root;
}

void preOrderPrint(Node * root){
    if(!root){
        return;
    }
    printf("%d ", root->data);
    preOrderPrint(root->left);
    preOrderPrint(root->right);

}

int main(){
    Node * root = NULL;

    
    while(true){
        printf("BST MENU\n");
        printf("1. Insert\n");
        printf("2. Print PreOrder\n");
        printf("3. EXIT\n");
        int option;
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter value for Node: \n");
            int data;
            scanf("%d", &data);
            Node * newNode = createNode(data);
            printf("New node created successfully\n");
            root = insertBST(root, newNode);
            break;

        case 2:
            printf("Root -> ");
            preOrderPrint(root);
            printf("\n");
            break;
        case 3:
            printf("Bye Bye\n");
            exit(0);
        default:
            break;
        }
    }
    
    printf("\n");
    return 0;
}