//Leetcode Medium 237: Delete a given linked list node
//Condition: We do not have access to the head of the list. The function takes the node to be deleted as a parameter.
//The question specifies to not actually delete the node from the memory but instead remove it's link such that a node with that value is no longer part of the original list.
//Concept: As we don't have access to the head, we access the node to be deleted, change it's value to that of the succeeding node and then delete that succeeding the node.
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
