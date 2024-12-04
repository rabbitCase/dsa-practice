//Leetcode Easy 21
//weird solution
#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *cur=list1;
        int n1=1;
        bool isSwapped;
        while(cur->next!=NULL){
            n1++;
            cur=cur->next;
        }
        ListNode *newcur=list2;
        cur->next=newcur;
        while(newcur->next!=NULL){
            n1++;
            newcur=newcur->next;
        }
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

    void display(ListNode *list1){
        ListNode *cur=list1;
        while(cur!=NULL){
            std::cout<< cur->val<<"-> ";
            cur=cur->next;
        }
        std::cout<<"NULL";
    }
};
int main(){
    Solution sol;
    ListNode* list1 = new ListNode(1); list1->next = new ListNode(3); ListNode* list2 = new ListNode(4); list2->next = new ListNode(2);
    sol.display(sol.mergeTwoLists(list1,list2));
}