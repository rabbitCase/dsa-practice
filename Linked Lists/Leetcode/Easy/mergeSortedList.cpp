//Leetcode Easy 21: Merge Sorted List
//Given two sorted lists, return a sorted list merging the two.
//Example: list1: 1->2->3->NULL, list2: 2->3->4->NULL, merged list: 1->2->2->3->3->4->NULL
//Inefficient Solution: connect the tail of list1 to head of list2 and then bubble sort the new joined list
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2)
        return NULL;
        else if(!list1 && list2)
        return list2;
        else if(!list2 && list1)
        return list1;
        ListNode *cur=list1;
        int n1=1;
        bool isSwapped;
        while(cur->next!=NULL){
            n1++;
            cur=cur->next;
        }
        ListNode *newcur=list2;
        cur->next=newcur;
        cur=list1; ListNode *newnext=cur->next;
        do{
            isSwapped=0;
            cur=list1;
            while(cur->next!=NULL){
                    newnext=cur->next;
                    if(cur->val > newnext->val){
                        int temp=cur->val;
                        cur->val=newnext->val;
                        newnext->val=temp;
                        isSwapped=1;
                    }
                    cur=cur->next;
            }
        }while(isSwapped);
        return list1;
    }
};
//Test main
int main(){
    Solution sol;
    ListNode* list1 = new ListNode(1); list1->next = new ListNode(3); ListNode* list2 = new ListNode(4); list2->next = new ListNode(2);
    sol.display(sol.mergeTwoLists(list1,list2));
}
