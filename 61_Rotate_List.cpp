#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution class to rotate the linked list to the right by k places
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        // If the list is empty, has only one node, or no rotation is needed
        if(!head || !head->next || k==0)
        {
            return head;
        }   
        // Step 1: Count the length of the list 
        int c = 1;
        ListNode* tail = head;
        while (tail->next) 
        {
            tail = tail->next;
            c++;
        }
        // Step 2: Make the list circular by connecting the tail to the head
        tail->next = head;

        // Step 3: Find the new tail (length - k % length - 1) and new head
        k = k % c; // In case k is greater than the length
        int stepsToNewTail = c - k;
        ListNode* newTail = tail;
        while (stepsToNewTail--) 
        {
            newTail = newTail->next;
        }
        // Step 4: Break the circle to form the rotated list
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};