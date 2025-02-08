//Leetcode Medium 2095
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