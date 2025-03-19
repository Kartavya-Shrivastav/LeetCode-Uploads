#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
            ListNode *dummyHead = new ListNode();
            int carry = 0;
            ListNode *current = dummyHead;
            while (l1 || l2 || carry)
            {
                int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
                carry = sum / 10;
                current->next = new ListNode(sum % 10);
                current = current->next;
                l1 = l1 ? l1->next : nullptr;
                l2 = l2 ? l2->next : nullptr;
            }
            return dummyHead->next;
        }
};