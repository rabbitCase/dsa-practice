//Basic Structure of a BST: updated with double pointers and a search method
#include <stdio.h>
#include <stdlib.h>

typedef struct node {

    int data;

    struct node* right;

    struct node* left;
} node;

void insert(node **root,int n){
    node *temp=(node*)malloc(sizeof(node));
    if(*root==NULL){
        temp->data=n;
        temp->right=NULL;
        temp->left=NULL;
        *root=temp;
        return ;
    }
    if(n < (*root)->data){
       insert(&(*root)->left,n);
    }
    else{
        insert(&(*root)->right,n);
    }
    return;
}
node* searchBST(node *root,int n){
    if(root==NULL){
        printf("\nElement not found\n");
        return NULL;
    }
    if(root->data==n){
        printf("\nElement found\n");
        return root;
    }
    if(n<root->data){
        return searchBST(root->left,n);

    }
    else{
        return searchBST(root->right,n);
    }

}
int count=0;
int traverse(node* root) {
    if (root==NULL)
        return 0;
    traverse(root -> left);
    if(root->left==NULL && root->right==NULL)
        count++;
    traverse(root -> right);
    if(root->left==NULL && root->right==NULL)
        count++;
    return count;
}
int main(){
    node *root=NULL;
    for(int i=0;i<10;i++){
        insert(&root,i);
    }
    searchBST(root,5);
    printf("Leaf nodes: %d",traverse(root));
    return 0;
}
// //Basic structure of a Binary Search Tree
// #include <stdio.h>
// #include <stdlib.h>
// typedef struct node {
//     int data;
//     struct node* right;
//     struct node* left;
// } node;

// node* insert(node *root,int n){
//     node *temp=(node*)malloc(sizeof(node));
//     if(root==NULL){
//         temp->data=n;
//         temp->right=NULL;
//         temp->left=NULL;
//         return temp;
//     }
//     if(n < (root)->data){
//         root->left=insert(root->left,n);
//     }
//     else{
//         root->right=insert(root->right,n);
//     }
//     return root;
// }

// void traverse(node* root) { //inorder traversal
//     if (root==NULL)
//         return;
//     traverse(root -> left);
//     printf("%d ", root -> data);
//     traverse(root -> right);
// }

// int main(){
//     node *root=NULL;
//     for(int i=0;i<10;i++){
//         root=insert(root,i);
//     }
//     traverse(root);
//     return 0;
// }
