
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
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
        // Step 2: Make the list circular
        tail->next = head;

        // Step 3: Find the new tail (length - k % length - 1) and new head
        k = k % c;
        int stepsToNewTail = c - k;
        ListNode* newTail = tail;
        while (stepsToNewTail--) 
        {
            newTail = newTail->next;
        }
        // Step 4: Break the circle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};