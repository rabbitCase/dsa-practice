//Leetcode Easy 206: Reverse a linked list
//Iterative approach: We have three pointers prev, cur and front. cur points to the current node in traversal, prev to the previous and front to the succeeding node. We change the link of cur to make it point towards prev. To update the cur so as to move to the next node, we make cur=front and repeat cur->next=prev till we reach the end of the list
#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//Method 1
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
//Method 2
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
