#include "stdio.h"
#include "malloc.h"

struct node{
    struct node* left;
    struct node* right;
    int value;
}; typedef struct node* NODE;

NODE insert(NODE root, int value){
    NODE newNode = (NODE)malloc(sizeof(struct node));
    newNode->right = NULL;
    newNode->left = NULL;
    newNode->value = value;
    if(root==NULL){
        return newNode;
    }

    NODE temp = root;
    NODE prevNode = temp;

    while(temp!=NULL){
        if(value==temp->value){
            printf("cannot insert duplicate node \n");
            return root;
        }
        prevNode = temp;

        if(value>temp->value){
            temp=temp->right;
        }
        else{
            temp=temp->left;
        }
    }
    if(value>prevNode->value){
        prevNode->right = newNode;
    }
    else{
        prevNode->left = newNode;
    }
    return root;
}

void preorder(NODE root){
    if(root==NULL){
        return;
    }
    printf("%d ", root->value);
    preorder(root->left);
    preorder(root->right);
}

void inorder(NODE root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}

void postoder(NODE root){
    if(root==NULL){
        return;
    }
    postoder(root->left);
    postoder(root->right);
    printf("%d ", root->value);
}

void search(NODE root, int key){
    NODE temp = root;
    if(root == NULL){
        printf("Tree is empty\n");
    }
    while(temp!=NULL){
        if(key == temp->value){
            printf("Key found\n");
            return;
        }
        if(key > temp->value ){
            temp = temp->right;
        }
        else{
            temp = temp->left;
        }
    }
    printf("Key not found\n");
}

int main()
{
    int n, value, key;
    NODE root = NULL;
    
    printf("Enter number of values to insert : ");
    scanf("%d", &n);

    printf("Enter %d values : \n", n);
    for(int i=0;i<n;i++){
        scanf("%d", &value);
        root = insert(root, value);
    }
    
    printf("preorder traversal : \n");
    preorder(root);
    printf("\n\n");
    printf("inorder traversal : \n");
    inorder(root);
    printf("\n\n");
    printf("postorder traversal : \n"); 
    postoder(root);   
    printf("\n\n");

    printf("Enter key to serach : ");
    scanf("%d", &key);
    search(root, key);
}
