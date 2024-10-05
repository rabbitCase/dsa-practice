//Various operations on a doubly linked list
//uses double pointers and is menu-driven to perform like a doubly linked list editor
#include <stdio.h>
#include <stdlib.h>
struct dnode{
    struct dnode *llink;//left link
    int data;
    struct dnode *rlink;//right link
}*head=NULL;

int checkEmpty(struct dnode *head){
    return head==NULL;
}
void checkLinks(struct dnode *head){//useful function to check if the left and right links of nodes are correct
    int ele;
    printf("\nEnter the element: ");
    scanf("%d",&ele);
    struct dnode *cur=head;
    while(cur!=NULL && cur->data!=ele){
        cur=cur->rlink;
    }
    if(cur==NULL){
        printf("\nElement non existant");
        return;
    }
    else if(cur->rlink==NULL){
        printf("\nRight link of %d points to: NULL",ele);
        printf("\nleft link of %d points to: %d",ele,cur->llink->data);
    }
    else if(cur->llink==NULL){
        printf("\nleft link of %d points to: NULL",ele);
        printf("\nRight link of %d points to: %d",ele,cur->rlink->data);
    }
    else{
        printf("\nRight link of %d points to: %d",ele,cur->rlink->data);
        printf("\nleft link of %d points to: %d",ele,cur->llink->data);
    }
}
void display(struct dnode *head){
    if(checkEmpty(head)){
        printf("\nList is empty.");
        return;
    }
    struct dnode *cur=head;
    printf("\nYour list: \n");
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
void deleteRearElement(struct dnode **head){
    if(checkEmpty(*head)){
        return;
    }
    if((*head)->rlink==NULL){
        *head=NULL;
        return;
    }
    struct dnode *temp=*head;
    while(temp!=NULL && temp->rlink!=NULL){
        temp=temp->rlink;
    }
    temp=temp->llink;
    temp->rlink=NULL;
}
void insertAtPos(struct dnode **head){
    struct dnode *temp=(struct dnode*)malloc(sizeof(struct dnode));
    struct dnode *cur=*head;
    int pos,data;
    if(checkEmpty(*head)){
        printf("\nList is empty");
        printf("\nCreating new list...");
        insertElement(head);
        return;
    }
    printf("\nEnter position: ");
    scanf("%d",&pos);
    if(pos==1){
        printf("Enter data to add: ");
        scanf("%d",&data);
        temp->data=data;
        temp->rlink=*head;
        temp->rlink->llink=temp;
        temp->llink=NULL;
        *head=temp;
        return;
    }
    for(int i=1;i<pos-1 && cur!=NULL && cur->rlink!=NULL;i++){
        cur=cur->rlink;
    }
    if(cur->rlink==NULL){
        printf("\nPosition out of bounds.");
        free(temp);
        return;
    }
    printf("Enter data to add: ");
    scanf("%d",&data);
    temp->data=data;
    temp->rlink=cur->rlink;
    temp->llink=cur;
    cur->rlink->llink=temp;
    cur->rlink=temp;
}
void deleteFromPos(struct dnode **head){
    if(checkEmpty(*head)){
        return;
    }
    int pos;
    printf("\nEnter position to delete element from: ");
    scanf("%d",&pos);
    struct dnode *temp1=NULL;
    if(pos==1 && (*head)->rlink==NULL){
        *head=NULL;
        return;
    }
    if(pos==1){
        temp1=*head;
        *head=(*head)->rlink;
        (*head)->llink=NULL;
        free(temp1);
        return;
    }
    struct dnode *cur=*head,*temp=cur;
    for(int i=0;i<pos-1 && cur!=NULL;i++){
        cur=cur->rlink;
        temp=cur;
    }
    if(cur==NULL){
        printf("\nPosition out of bounds.");
        return;
    }
    if(cur->rlink!=NULL){
    cur->llink->rlink=cur->rlink;
    cur->rlink->llink=cur->llink;
    }
    else{
        cur=cur->llink;
        cur->rlink=NULL;
    }
    free(temp);
}
void insertAfter(struct dnode **head){
    if(checkEmpty(*head)){
        printf("\nList is empty.");
        printf("\nCreating new list...");
        insertElement(head);
        return;
    }
    int data,ele;
    printf("\nEnter element after which data will be inserted: ");
    scanf("%d",&ele);
    struct dnode *temp=(struct dnode*)malloc(sizeof(struct dnode));
    struct dnode *cur=*head;
    while(cur!=NULL && cur->data!=ele){
        cur=cur->rlink;
    }
    if(cur==NULL){
        printf("\nThis element does not exist.");
        return;
    }
    printf("\nEnter data: ");
    scanf("%d",&data);
    temp->data=data;
    temp->rlink=cur->rlink;
    temp->llink=cur;
    if(cur->rlink!=NULL){
    cur->rlink->llink=temp;
    }
    cur->rlink=temp;
}
void insertBefore(struct dnode **head){
    if(checkEmpty(*head)){
        printf("\nList is empty");
        printf("\nCreating new list...");
        insertElement(head);
        return;
    }
    int data,ele;
    printf("\nEnter element before which data will be inserted: ");
    scanf("%d",&ele);
    struct dnode *temp=(struct dnode*)malloc(sizeof(struct dnode));
    struct dnode *cur=*head;
    while(cur!=NULL && cur->data!=ele){
        cur=cur->rlink;
    }
    if(cur==NULL){
        printf("\nThis element does not exist.");
        return;
    }
    printf("\nEnter data: ");
    scanf("%d",&data);
    if((*head)->data==ele){
        temp->data=data;
        temp->rlink=cur;
        temp->llink=NULL;
        *head=temp;
        return;
    }
    temp->data=data;
    temp->rlink=cur;
    temp->llink=cur->llink;
    cur->llink->rlink=temp;
    cur->llink=temp;
}
void reverseList(struct dnode **head){//reverse the list by switching left and right links and also updating the head pointer
    struct dnode *cur=*head,*temp=NULL;
    int count=0;
    if(checkEmpty(*head)){
        printf("\nList is empty.");
        return;
    }
    if((*head)->rlink==NULL){
        printf("\nOnly one element in the list.");
        return;
    }
    while(cur!=NULL){
    temp=cur->llink;
    cur->llink=cur->rlink;//llink becomes rlink
    cur->rlink=temp;
    cur=cur->llink;//cur moves to llink because llink is now actually rlink
    }
    (*head)=temp->llink;//temp=cur->llink before cur->llink was updated to cur->rlink, hence temp->llink->llink=temp->llink->(updated (previous node->rlink))=*head
}
int main()
{
    int x;
    printf("DOUBLY LINKED LIST OPERATIONS\n0: View your list\n1: Add nodes to your list\n2: Delete a node from the rear\n3: Insert an node at a specified position\n4: Delete a node from a specified position\n5: Insert a node after a specified node\n6: Insert a node before a specified node\n7: Reverse your list\n8: Check left and right links of a specified node\n9: EXIT\n");
    do{
        printf("\nEnter your choice: ");
        scanf("%d",&x);
        switch(x){
            case(0):
            display(head); break;

            case(1):
            insertElement(&head); display(head); break;

            case(2):
            deleteRearElement(&head); display(head); break;

            case(3):
            insertAtPos(&head); display(head); break;

            case(4):
            deleteFromPos(&head); display(head); break;

            case(5):
            insertAfter(&head); display(head); break;

            case(6):
            insertBefore(&head); display(head); break;

            case(7):
            reverseList(&head); display(head); break;

            case(8):
            checkLinks(head); break;

        }

    }while(x!=9);
    printf("\nEXIT");
    return 0;
}
