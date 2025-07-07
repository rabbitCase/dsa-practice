//Leetcode Medium 19
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//One pass
class Solution1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head){
            return NULL;
        }
        ListNode *fast = head;
        ListNode *slow = head;
     
        while(n--){
            fast = fast->next;
        }
        if(!fast){
            return head->next;
        }
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
//Two pass
class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        if(!head){
            return NULL;
        }
        ListNode *cur = head;

        while(cur){
            cur = cur->next;
            length++;
        }
        cur = head;
        if(length == 1){
            return NULL;
        }
        if(n == 1){
            while(cur->next->next){
                cur = cur->next;
            }
            cur->next = NULL;
            return head;
        }
        if(n == length){
            return head->next;
        }
        for(int i = 0; i < length - n - 1; i++){
            cur = cur->next;
        }
        cur->next = cur->next->next;
        return head;
    }
};

