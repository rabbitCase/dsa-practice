//Basic structure of a Binary Search Tree
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node* right;
    struct node* left;
} node;

node* insert(node *root,int n){
    node *temp=(node*)malloc(sizeof(node));
    if(root==NULL){
        temp->data=n;
        temp->right=NULL;
        temp->left=NULL;
        return temp;
    }
    if(n < (root)->data){
        root->left=insert(root->left,n);
    }
    else{
        root->right=insert(root->right,n);
    }
    return root;
}

void traverse(node* root) { //inorder traversal
    if (root==NULL)
        return;
    traverse(root -> left);
    printf("%d ", root -> data);
    traverse(root -> right);
}

int main(){
    node *root=NULL;
    for(int i=0;i<10;i++){
        root=insert(root,i);
    }
    traverse(root);
    return 0;
}
