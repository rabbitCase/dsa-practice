//Leetcode Easy 234
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

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *cur = head;
        vector<int> vec;
        while(cur){
            vec.push_back(cur->val);
            cur = cur->next;
        }
        int size = vec.size();
        int mid = size/2;
        int left = 0;
        int right = size - 1;
        while(left < right){
            if(vec[left] != vec[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    
};