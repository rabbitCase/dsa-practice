//Leetcode Medium 2095: Delete the middle node of the linked list

//Method 1: We take a pretty straightforward approach, first, we traverse the entire list, and implement a counter to count till we reach the end to get the size of the list. We then reset the pointer to point to the head and traverse again till one node behind the middle node ((count/2 - 1)th node). We then change the link of this node to the link of the node in front of it (current->next = current->next->next), effectively, deleting the node in front of it

//Method 2: We use the concept of fast and slow pointers we learned before when finding the middle of the linked list. The fast pointer moves twice as fast as the slow pointer, this way when the fast pointer reaches the end of the list, the slow pointer would reach the middle of the list. We keep track of the previous node as we update the slow pointer an then once the slow pointer reaches the middle, it can be deleted by changing the link of it's previous node. 

//Modification: We don't we even need another pointer to keep track of the previous node if the fast pointer starts with head->next instead of head. This way, the slow pointer points to the node just before the middle node (the fast pointer null constraints must be modified to ensure this).

//The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

//Method 1
#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next){
            return NULL;
        }
       
        ListNode* cur=head;
        int count=1;
        while(cur->next){
            cur=cur->next;
            count++;
        }
        cur=head;
        int check=1;
        while(check<count/2 && cur->next!=NULL){
            cur=cur->next;
            check++;
        }
        cur->next=cur->next->next;
        return head;
    }
};

//Method 2

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next){
            return NULL;
        }
       
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev=NULL;
        while(fast && fast->next){
            fast=fast->next->next;
            prev=slow;//keep track of the previously pointed location of slow before updating it
            slow=slow->next;
        }
        prev->next=prev->next->next;// or prev->next=slow->next
        return head;
    }
};
//Modification without using prev
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next){
            return NULL;
        }
       
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast->next && fast->next->next){//if fast->next->next is not checked for NULL, the slow pointer will update to point towards the middle node in that iteration of the loop and the node after the middle node will be deleted. Take [1,3,4,7,1,2,6] for example, fast points to 3 then 7 then 2 at that time, slow points to 4, which is where it should be so that the middle node (7) could be deleted. Now, if fast->next->next is not cheked for null values, the loop will continue one more time where fast = fast->next->next becomes null. Now slow will point to 7, yielding wrong results.
            fast=fast->next->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};
