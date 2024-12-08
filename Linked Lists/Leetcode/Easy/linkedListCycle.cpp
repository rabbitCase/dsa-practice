//Leetcode Easy 141: return true if the given linked list has a cycle
//Concept: create a hash map which pairs data of type ListNode (given linked list structure) to int. Traverse through the list, and increment every node's frequency by 1. If the list has a cycle, then it's frequency will be greater than 1. We can also use bool instead of int to mark the node as visited and flagging a cycle when a node set to 'visited' is visited again but this approach caused a TLE error. 
//Slow and fast pointer approach is pending
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map <ListNode*,int> mpp;
        ListNode *cur=head;
        while(cur!=NULL){
            if(mpp[cur->next]>1 ){
                return true;
            }
            mpp[cur->next]++;
            cur=cur->next;
        }
        return false;
    }
};
