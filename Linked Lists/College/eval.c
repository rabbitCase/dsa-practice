//A question from  Data Structures End semester exam
//Create a doubly Linked list
//Display it
//Create a second list containing even numbers first and then odd numbers from the original list in sorted order
#include <stdio.h>
#include <stdlib.h>

struct dnode{
    struct dnode *llink;//left link
    int data;
    struct dnode *rlink;//right link
}*head=NULL;

struct node{//second list
    int data;
    struct node *llink;
    struct node *rlink;
}*head3=NULL;

void display(struct node *head3){//display function for the second list
    if(!head3){
        printf("\nList is empty.");
        return;
    }
    struct node *cur=head3;
    printf("\nYour list: \n");
    while(cur!=NULL){
        printf("%d->",cur->data);
        cur=cur->rlink;
    }
    printf("NULL\n");
}

void insertElement(struct dnode **head,int element){//insert element function for the first list
    struct dnode *temp=(struct dnode*)malloc(sizeof(struct dnode));
    temp->data=element;
    temp->llink=NULL;
    temp->rlink=NULL;
    if(*head==NULL){
        *head=temp;
        return;
    }
    struct dnode *cur=*head;
    while(cur->rlink!=NULL){
        cur=cur->rlink;//get the last node
    }
    cur->rlink=temp;
    temp->llink=cur;
}

void create(struct node **head3,int element){//insert element function for the second list
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=element;
    temp->llink=NULL;
    temp->rlink=NULL;
    if(*head3==NULL){
        *head3=temp;
        return;
    }
    struct node *cur=*head3;
    while(cur->rlink!=NULL){
        cur=cur->rlink;
    }
    cur->rlink=temp;
    temp->llink=cur;
}

void sort(struct dnode **head, struct node **head3){
    int curmin[100],newmin[100];//array to store even and odd numbers
    int i=0,j=0,n1=0,n2=0;
    struct dnode *cur=*head;
    while(cur){
        if(cur->data % 2==0){
            curmin[i++]=cur->data;
            n1++;
        }
       
        cur=cur->rlink;
    }
    cur=*head;//reset cur
    while(cur){
        if(cur->data % 2!=0){
            newmin[j++]=cur->data;
            n2++;
        }
        cur=cur->rlink;
    }
    for(int i=0;i<n1-1;i++){//bubble sort even array 
        for(int j=1;j<n1-i;j++){
            if(curmin[j]<curmin[j-1]){
                int temp=curmin[j];
                curmin[j]=curmin[j-1];
                curmin[j-1]=temp;
            }
        }
    }
    for(int i=0;i<n2-1;i++){//bubble sort odd array
        for(int j=1;j<n2-i;j++){
            if(newmin[j]<newmin[j-1]){
                int temp=newmin[j];
                newmin[j]=newmin[j-1];
                newmin[j-1]=temp;
            }
        }
    }
    for(int i=0;i<n1;i++){//insert even numbers into the new list
            create(head3,curmin[i]);
    }
    for(int i=0;i<n2;i++){//insert odd numbers into the new list
            create(head3,newmin[i]);
    }
}

int main(){
    insertElement(&head,3);//insert elements in random order
    insertElement(&head,4);
    insertElement(&head,1);
    insertElement(&head,2);
    insertElement(&head,7);
    insertElement(&head,8);
    insertElement(&head,5);
    insertElement(&head,10);
    insertElement(&head,9);
    insertElement(&head,10);
    sort(&head,&head3);
    display(head3);
}
