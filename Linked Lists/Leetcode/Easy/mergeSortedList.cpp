//Leetcode Easy 21: Merge Sorted List
//Given two sorted lists, return a sorted list merging the two.
//Example: list1: 1->2->3->NULL, list2: 2->3->4->NULL, merged list: 1->2->2->3->3->4->NULL
//Concept: we have temp node which points has a  random value. We use two pointers to traverse list1 and list2 and make temp->next point to whatever the least val of the two linked list is. cur1 and cur2 are used for traversal while curtemp is used to update the temp node and make it point to the correct node. No new nodes are created, we are just pointing to different nodes in the correct sequence. After cur1 or cur2 becomes null, we point the list to the remaining part of the list which is not yet null.
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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *cur1=list1;
        ListNode *cur2=list2;
        ListNode *temp = new ListNode(-1);
        ListNode *curtemp=temp;
        while( cur1 && cur2){
            if(cur1->val < cur2->val){
                curtemp->next=cur1;
                curtemp=cur1;//update curtemp
                cur1=cur1->next;
            }
            else{
                curtemp->next=cur2;
                curtemp=cur2;//update curtemp
                cur2=cur2->next;
            }

        }
        curtemp->next=(!cur1)?cur2:cur1;
        return temp->next;//we dont need the temp data so we return the node just after it which contains list1 or list2 data.
    }
};
//Inefficient solution: connect the tail of list1 to head of list2 and then bubble sort the new joined list
// #include <iostream>
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if(!list1 && !list2)
//         return NULL;
//         else if(!list1 && list2)
//         return list2;
//         else if(!list2 && list1)
//         return list1;
//         ListNode *cur=list1;
//         int n1=1;
//         bool isSwapped;
//         while(cur->next!=NULL){
//             n1++;
//             cur=cur->next;
//         }
//         ListNode *newcur=list2;
//         cur->next=newcur;
//         cur=list1; ListNode *newnext=cur->next;
//         do{
//             isSwapped=0;
//             cur=list1;
//             while(cur->next!=NULL){
//                     newnext=cur->next;
//                     if(cur->val > newnext->val){
//                         int temp=cur->val;
//                         cur->val=newnext->val;
//                         newnext->val=temp;
//                         isSwapped=1;
//                     }
//                     cur=cur->next;
//             }
//         }while(isSwapped);
//         return list1;
//     }
// };
//test main
int main(){
    Solution sol;
    ListNode* list1 = new ListNode(1); list1->next = new ListNode(3); ListNode* list2 = new ListNode(4); list2->next = new ListNode(2);
    sol.display(sol.mergeTwoLists(list1,list2));
}
