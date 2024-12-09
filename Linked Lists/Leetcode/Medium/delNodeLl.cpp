//Leetcode Medium 237: Delete a node in a given linked list
//Condition: We do not have access to the head of the list. The function takes the node to be deleted as a parameter.
//The question specifies to not actually delete the node from the memory but instead remove it's link such that a node with that value is no longer part of the original list.
//Concept: As we don't have access to the head, we access the node to be deleted, change it's value to that of the succeeding node and then delete that succeeding the node. The question guarantees that the node to be deleted will not be the tail in any testcase so the above method works for all given testcases.
//Example: if the list is 1->2->3->4 and the node to be deleted is 2, we access 3 (through 2->next) and change 2 to 3. New list: 1->3->3->4. Now we simply remove the original 3 (not the copy). New list: 1->3->4.
#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
    }
};
