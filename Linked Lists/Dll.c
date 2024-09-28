//structure of a doubly linked list 
#include <stdio.h>
#include <stdlib.h>
struct dnode{
    struct dnode *llink;//left link
    int data;
    struct dnode *rlink;//right link
}*head=NULL;

void display(struct dnode *head){
    if(head==NULL){
        printf("\nList is empty.");
        return;
    }
    struct dnode *cur=head;
    printf("\nNew list: \n");
    while(cur!=NULL){
        printf("%d->",cur->data);
        cur=cur->rlink;
    }
    printf("NULL\n");
}

void insertElement(struct dnode **head){//insert element at the rear end of list
    int element;
    printf("\nEnter data to be inserted: ");
    scanf("%d",&element);
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
    cur->rlink=temp;//connect temp to the list
    temp->llink=cur;//doubly link the new node
}

int main() {
    insertElement(&head);insertElement(&head);insertElement(&head);
    display(head);
    return 0;
}


//Previous code (without double pointers)
/*
#include <stdio.h>
#include <stdlib.h>
struct dnode{
    struct dnode *llink;//represents left link
    int data;
    struct dnode *rlink;//represents right link
}*head=NULL;

void display(struct dnode *head){
    if(head==NULL){
        printf("\nList is empty.");
        return;
    }
    struct dnode *cur=head;
    printf("\nNew list: \n");
    while(cur!=NULL){
        printf("%d->",cur->data);
        cur=cur->rlink;
    }
    printf("NULL\n");
}

struct dnode* insertElement(struct dnode *head){
    int element;
    printf("\nEnter data to be inserted: ");
    scanf("%d",&element);
    struct dnode *temp=(struct dnode*)malloc(sizeof(struct dnode));
    temp->data=element;
    temp->llink=temp->rlink=NULL;
    if(head==NULL){
        head=temp;
        return head;
    }
    struct dnode *cur=head;
    while(cur->rlink!=NULL){
        cur=cur->rlink;//get the last node
    }
    cur->rlink=temp;//connect temp to the list
    temp->llink=cur;//doubly link the new node
    return head;
}

int main() {
    head = insertElement(head);//instead of updating head repreatedly in the main function, we can use double pointer(**head) in the insertElement function
    head = insertElement(head);//using double pointer will require us to pass the address of head (&head) instead of just head
    head = insertElement(head);
    display(head);//display function needn't use double pointers since no modification of head is being done
    return 0;
}
*/
