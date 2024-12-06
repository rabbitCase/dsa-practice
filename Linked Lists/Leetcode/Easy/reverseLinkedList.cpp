//Leetcode Easy 206
#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        ListNode *cur=head;
        ListNode *prev=NULL;
        ListNode *front=cur->next;
        while (cur){
            front=cur->next;
            cur->next=prev;
            prev=cur;
            cur=front;
        }
        head=prev;
        return head;
    }
};

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(head==NULL){
//             return NULL;
//         }
//         ListNode *cur=head;
//         ListNode *prev=NULL;
//         ListNode *front=cur->next;
//         while (front){
//             cur->next=prev;
//             prev=cur;
//             cur=front;
//             front=front->next;
//         }
//         cur->next=prev;
//         head=cur;
//         return head;
//     }
// };