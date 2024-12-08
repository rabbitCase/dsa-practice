//Leetcode Easy 141
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