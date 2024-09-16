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
    head = insertElement(head);
    head = insertElement(head);
    head = insertElement(head);
    display(head);
    return 0;
}
