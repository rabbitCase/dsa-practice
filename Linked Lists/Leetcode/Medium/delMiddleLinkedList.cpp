//Leetcode Medium 2095: Delete the middle node of the linked list
//Concept: We take a pretty straightforward approach, first, we traverse the entire list, and implement a counter to count till we reach the end to get the size of the list. We then reset the pointer to point to the head and traverse again till one node behind the middle node ((count/2 - 1)th node). We then change the link of this node to the link of the node in front of it (current->next = current->next->next), effectively, deleting the node in front of it
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
