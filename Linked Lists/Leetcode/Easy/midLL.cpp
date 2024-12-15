//Leetcode Easy 876
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
        int count=1;
        if(!head){
            return NULL;
        }
        ListNode *cur=head;
        while(cur){
            cur=cur->next;
            count++;
        }
        cur=head;
        if(count%2==0){
            for(int i=0;i<count/2-1;i++){
               
                cur=cur->next;
            }
            return cur;
        }
        for(int i=0;i<count/2-1;i++){
                
                cur=cur->next;
        }
        return cur->next;
    }
};