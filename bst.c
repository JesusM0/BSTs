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

int isLeafNode(Node * root){
    if(!root->left && !root->right){
        return 1;
    }
    else{
        return 0;
    }
}

int onlyLeftChild(Node * root){
    if(root->left != NULL && !root->right){
        return 1;
    }
    else{
        return 0;
    }
}
int onlyRightChild(Node * root){
    if(!root->left && root->right != NULL){
        return 1;
    }
    else{
        return 0;
    }
}

Node * maxValue(Node * root){
    if(root->right == NULL){
        return root;
    }
    else{
        return maxValue(root->right);
    }
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

Node * deleteNode(Node * root, int data){
    if(!root){
        return NULL;
    }

    if(root->data == data){
        if(isLeafNode(root)){
            free(root);
            return NULL;
        }
        else if(onlyLeftChild(root)){
            Node * tmp = root->left;
            free(root);
            return tmp;
        }
        else if(onlyRightChild(root)){
            Node * tmp = root->right;
            free(root);
            return tmp;
        }
        else{
            Node * tmp = maxValue(root->left);
            int maxPredecessor = tmp->data;
            root->left = deleteNode(root->left, maxPredecessor);
            root->data = maxPredecessor;
            return root;
        }
    }
    else{
        if(data < root->data){
            root->left = deleteNode(root->left, data);
        }
        else if(data > root->data){
            root->right = deleteNode(root->right, data);
        }
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
        printf("2. Delete\n");
        printf("3. Print PreOrder\n");
        printf("4. EXIT\n");
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
            printf("Enter value for Deletion: \n");
            int delValue;
            scanf("%d", &delValue);
            printf("Now Deleting %d....\n", delValue);
            root = deleteNode(root, delValue);
            break;

        case 3:
            printf("Root -> ");
            preOrderPrint(root);
            printf("\n");
            break;
        case 4:
            printf("Bye Bye\n");
            exit(0);
        default:
            break;
        }
    }
    
    printf("\n");
    return 0;
}