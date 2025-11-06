#include <bits/stdc++.h>
using namespace std;

// Problem: Delete Nodes From Linked List Present in Array
// Approach: Use a hash set to store values from the array for O(1) lookup

// Steps:
// 1. Store all values from the array in an unordered_set for quick access
// 2. Traverse the linked list and remove nodes whose values are in the set
// 3. Return the modified linked list

// Time Complexity: O(n + m) where n is the number of nodes in the linked list and m is the size of the array
// Space Complexity: O(m) for storing the values in the set
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> mpp(nums.begin(), nums.end());

        while (head && mpp.count(head->val))
            head = head->next;

        ListNode* curr = head;
        while (curr && curr->next) {
            while (curr->next && mpp.count(curr->next->val)) {
                curr->next = curr->next->next;
            }
            curr = curr->next;
        }
        return head;
    }
};