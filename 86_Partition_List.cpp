#include <iostream>
using namespace std;

// Problem Statement: Given the head of a linked list and a value x, partition the linked list such that all nodes less than x come before nodes greater than or equal to x. The original relative order of the nodes in each partition should be preserved.
// Approach: We can create two separate linked lists: one for nodes with values less than x and another for nodes with values greater than or equal to x. We then concatenate these two lists to form the final partitioned list.

// Steps:
// 1. Initialize two dummy nodes to represent the start of the 'less than x' and 'greater than or equal to x' lists.
// 2. Traverse the original linked list and append each node to the appropriate list based on its value.
// 3. After traversing the original list, connect the 'less than x' list to the 'greater than or equal to x' list.
// 4. Ensure the last node of the 'greater than or equal to x' list points to nullptr.
// 5. Return the head of the new partitioned list, which is the next node of the dummy 'less than x' node.

// Time Complexity: O(n), where n is the number of nodes in the linked list, as we traverse the list once.
// Space Complexity: O(1), as we are using only a constant amount of extra space.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode before(0), after(0);
        ListNode* before_curr = &before;
        ListNode* after_curr = &after;
        
        while(head) {
            if(head->val < x) {
                before_curr->next = head;
                before_curr = head;
            } else {
                after_curr->next = head;
                after_curr = head;
            }
            head = head->next;
        }
        
        after_curr->next = nullptr;
        before_curr->next = after.next;
        
        return before.next;
    }
};