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
int traverse(node* root) {//traverse inorder and count the no of leaf nodes
    if (root==NULL)
        return 0;
    traverse(root->left);
    if(root->left==NULL && root->right==NULL)
        count++;
    traverse(root->right);
    return count;
}
int main(){
    node *root=NULL;
    for(int i=0;i<10;i++){//elements are being added in ascending order so the tree is basically a linked list i.e no of leaf nodes=1
        insert(&root,i);
    }
    searchBST(root,5);
    printf("Leaf nodes: %d",traverse(root));
    return 0;
}
//Previous code
// #include <stdio.h>
// #include <stdlib.h>
// struct node{
//     int data;
//     struct node *left;
//     struct node *right;
// } *root=((void*)0);

// void inorder(struct node *root){
//     if(root==NULL){
//         return;
//     }
//     inorder(root->left);
//     printf("%d ",root->data);
//     inorder(root->right);
// }


// struct node* insert(struct node *root,int ele){
//     struct node* temp=(struct node*)malloc(sizeof(struct node));
//     if(root==NULL){
//         temp->data=ele;
//         temp->left=temp->right=NULL;
//         return temp;
//     }
//     if(ele<root->data){
//         root->left=insert(root->left,ele);
//     }
//     else{
//         root->right=insert(root->right,ele);
//     }
//     return root;
// }
// int main(){
//     for(int i=1;i<10;i++){
//         root=insert(root,i);
//     }
//     inorder(root);
// }
