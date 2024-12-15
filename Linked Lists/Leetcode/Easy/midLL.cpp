//Leetcode Easy 876: Find the middle node of a given linked list. Return the  second middle element if there are two of them (even no of elements)
//There is always the brute force method where you traverse through the array, count it's size, traverse again till you reach the size/2 and return that element. But obviously this is very inefficient and has vary bad space complexity.
//The concept of fast and slow pointers come to the rescue. Both fast and slow start at head, fast pointer moves two steps while the slow pointer moves one step, therefore, by the time the fast pointer reaches the end, the slow pointer will be at the middle of the list
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(!head){
            return NULL;
        }
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};

//Brute force
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         int count=1;
//         if(!head){
//             return NULL;
//         }
//         ListNode *cur=head;
//         while(cur){
//             cur=cur->next;
//             count++;
//         }
//         cur=head;
//         if(count%2==0){
//             for(int i=0;i<count/2-1;i++){
               
//                 cur=cur->next;
//             }
//             return cur;
//         }
//         for(int i=0;i<count/2-1;i++){
                
//                 cur=cur->next;
//         }
//         return cur->next;
//     }
// };
