#include<bits/stdc++.h>
using namespace std;

    class Solution
{
public:
    ListNode *mergeTwo(ListNode *a, ListNode *b)
    {
        if (!a)
            return b;
        if (!b)
            return a;

        if (a->val <= b->val)
        {
            a->next = mergeTwo(a->next, b);
            return a;
        }
        else
        {
            b->next = mergeTwo(a, b->next);
            return b;
        }
    }

    ListNode *mergeKLists(vector<ListNode *> &arr)
    {
        for (int gap = 1; gap < arr.size(); gap *= 2)
        {
            for (int i = 0; i + gap < arr.size(); i += gap * 2)
            {
                arr[i] = mergeTwo(arr[i], arr[i + gap]);
            }
        }
        return arr.size() > 0 ? arr[0] : nullptr;
    }
};