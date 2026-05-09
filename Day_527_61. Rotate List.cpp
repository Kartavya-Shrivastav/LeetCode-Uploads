#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given the head of a linked list, rotate the list to the right by k places. 
Approach: We can solve this problem by first finding the length of the linked list and then making it circular. After that, we can find the new tail and new head of the rotated linked list and break the circular linked list to get the final result.

Steps:
1. First, we need to find the length of the linked list and also keep track of the tail node. We can do this by traversing the linked list until we reach the end.
2. Once we have the length of the linked list, we can calculate the effective number of rotations needed by taking k modulo the length of the linked list. This is because rotating the linked list by its length results in the same linked list.
3. If the effective number of rotations is 0, we can return the head of the linked list as it is, since rotating it by its length or any multiple of its length does not change the linked list.
4. If the effective number of rotations is not 0, we can make the linked list circular by connecting the tail node to the head node.
5. Next, we need to find the new tail node, which will be the (length - k)th node from the beginning of the linked list. We can do this by traversing the linked list again until we reach the (length - k)th node.
6. The new head of the linked list will be the node next to the new tail node. We can set the next pointer of the new tail node to NULL to break the circular linked list and return the new head of the linked list.   

Time Complexity: O(n), where n is the number of nodes in the linked list, since we need to traverse the linked list to find its length and also to find the new tail node.
Space Complexity: O(1), since we are using only a constant amount of extra space to store temporary variables for the rotation and we are modifying the linked list in-place.
*/

class Solution{
public:
    ListNode* rotateRight(ListNode* head,int k){
        if(!head||!head->next||k==0) return head; 

        int len=1;
        ListNode* tail=head;
        while(tail->next){ tail=tail->next; len++; } 

        k%=len;
        if(k==0) return head; 

        tail->next=head; // circular

        int steps=len-k;
        ListNode* newtail=head;
        for(int i=1;i<steps;i++) newtail=newtail->next; 

        ListNode* newhead=newtail->next; 
        newtail->next=NULL; // break

        return newhead;
    }
};