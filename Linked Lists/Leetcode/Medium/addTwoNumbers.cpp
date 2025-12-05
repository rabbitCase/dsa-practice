//Leetcode medium 2
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        ListNode *head = new ListNode(0);
        ListNode *temp = head;
        while (l1 || l2 || carry > 0)
        {
            int d1 = !l1 ? 0 : l1->val;
            int d2 = !l2 ? 0 : l2->val;
            int sum = d1 + d2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode *cur = new ListNode(digit);
            temp->next = cur;
            temp = temp->next;

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        return head->next;
    }
};