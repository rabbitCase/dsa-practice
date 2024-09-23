//Performing Various operations on a singly linked list
#include <stdio.h>
#include <stdlib.h>
struct node{
int data;
struct node *link;
}*head=NULL;

void disp(struct node *head){//view list
    struct node *temp=head;
    printf("Your list: \n");
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->link;
    }
    printf("NULL\n");
}

void createList(struct node **head){
    struct node *temp =(struct node*)malloc(sizeof(struct node));
    int x;
    printf("Enter data to insert: ");
    scanf("%d",&x);
    temp->data=x;
        temp->link=NULL;
    if(*head==NULL){
        *head=temp;
    }

    else{
        struct node *cur=*head;
    while(cur->link!=NULL){
        cur=cur->link;
    }
        cur->link=temp;
    }
}

void insertAfter(struct node **head){//insert an element after a specified node
    int x,data,flag=0;
    struct node *temp =(struct node*)malloc(sizeof(struct node));
    if(*head==NULL){
        temp->data=x;
        temp->link=NULL;
        *head=temp;
    }
    else{
        struct node *cur=*head;
        printf("Enter element after which data has to be added: ");
        scanf("%d",&data);
        printf("Enter data to add: ");
        scanf("%d",&x);
        while(cur!=NULL){
            if(cur->data==data){
                flag=1;
                temp->data=x;
                temp->link=cur->link;
                cur->link=temp;
                break;
            }
            cur=cur->link;
        }
    }
    if(flag==0){
        printf("\nNo Such element.");
        free(temp);
    } 
   
}

void insertBefore(struct node **head){//insert an element before a specified node
    struct node *temp =(struct node*)malloc(sizeof(struct node));
    int x, data,flag=0;//flag to ping the existence of inputted node
    printf("Enter element before which data will be entered: ");
    scanf("%d",&data);
    if(*head==NULL){
        printf("\nNo such data exists, list is empty.\n");
        free(temp);
        return;
    }
    printf("Enter data to add: ");
    scanf("%d",&x);
    if((*head)->data==data){
        temp->data=x;
        temp->link=NULL;
        *head=temp;
    }
    else{
        struct node *cur=*head;
        struct node *prev=NULL;
        while(cur!=NULL){
            if(cur->data==data){
                flag=1;
                temp->data=x;
                temp->link=cur;
                if(prev!=NULL)
                prev->link=temp;
                break;
            }
            prev=cur;
            cur=cur->link;
        }
    }
    if(flag==0){
    printf("\nNo such element.");  
    free(temp);
    }
}

void deleteElement(struct node **head){
    int data,flag=0;
    printf("\nEnter data to be deleted: ");
    scanf("%d",&data);
    struct node *temp=*head;
    struct node * prev=NULL;
    if((*head)->data==data){
        *head=temp->link;
        flag=1;
        return;
    }
  
    while(temp!=NULL && temp->data!=data){
    prev=temp;
    temp=temp->link;
    }
    if(temp!=NULL && temp->data==data){
        flag=1;
        prev->link=temp->link;
        free(temp);
        return;
    }
    if(flag==0){
    printf("\nNo such element.\n"); 
    }
}

void reverseList(struct node **head){
    struct node* prev=NULL;
    struct node *cur=*head;
    struct node *next=NULL;
    if((*head)->link==NULL){
        return;
    }
    else if(*head==NULL){
        printf("\nList is empty.");
        return;
    }
    else{
        while(cur!=NULL){
            next=cur->link;
            cur->link=prev;
            prev=cur;
            cur=next;
        }
    }
    *head=prev;
}
void sortList(struct node **head){
    struct node *cur=*head,*next=cur->link;
    int isSwapped;
    if(*head==NULL){
        printf("\nNothing to sort, list is empty");
    }
    do{
        isSwapped=0;
        cur=*head;
        while(cur->link!=NULL){
            next=cur->link;
            if(cur->data>next->data){
                int temp=cur->data;
                cur->data=next->data;
                next->data=temp;
                isSwapped=1;
            }
            cur=cur->link;
        }
    }while(isSwapped);
}

void deleteAlternate(struct node **head){//delete every alternate node
    if(*head==NULL || (*head)->link==NULL){
        printf("\nList is empty or not enough nodes.\n");
        return;
    }
    printf("\nDeleting alternate nodes: \n");
    struct node *temp=*head;
    while(temp!=NULL && temp->link!=NULL){
        temp->link=temp->link->link;
        temp=temp->link;
    } 
}
void insertAndMaintainOrder(struct node **head){
    printf("\nElement will be inserted such that ascending order is maintained.\n");
    createList(head);
    sortList(head);
}

int main()
{
    int x;
    printf("LINKED LIST OPERATIONS\n0: View your list\n1: Add nodes to your list\n2: Delete a node\n3: Insert an node after a specified node\n4: Insert an node before a specified node\n5: Reverse your list\n6: Sort your list\n7: Delete every alternate node of your list\n8: Insert a node while maintaining ascending order\n9: EXIT\n");
    do{
        printf("Enter your choice: ");
        scanf("%d",&x);
        switch(x){//switch case for making the program menu-driven
            case(0):
            disp(head); break;

            case(1):
            createList(&head); disp(head); break;

            case(2):
            deleteElement(&head); disp(head); break;

            case(3):
            insertAfter(&head); disp(head); break;

            case(4):
            insertBefore(&head); disp(head); break;

            case(5):
            reverseList(&head); disp(head); break;

            case(6):
            sortList(&head); disp(head); break;

            case(7):
            deleteAlternate(&head); disp(head); break;

            case(8):
            insertAndMaintainOrder(&head); disp(head); break;

        }

    }while(x!=9);
    printf("\nEXIT");
    return 0;
}
