//Leetcode Medium 237: Delete a given linked list node
//Condition: We do not have access to the head of the list. The function takes the node to be deleted as a parameter.
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
