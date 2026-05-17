#include<bits/stdc++.h>
using namespace std;

/*
Problem: Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.
Approach: We can solve this problem by using a breadth-first search (BFS) algorithm. We will use a queue to keep track of the indices we can jump to and a vector to keep track of the visited indices to avoid cycles. We will start from the given index and explore all possible jumps until we either find an index with value 0 or exhaust all possibilities.

Steps:
1. Initialize a queue to keep track of the indices we can jump to and a vector to keep track of the visited indices.
2. Push the starting index into the queue and mark it as visited.
3. While the queue is not empty:
   a. Pop the front index from the queue and check if the value at that index is 0. If it is, return true.
   b. Calculate the left and right jump indices based on the current index and the value at that index.
   c. If the left jump index is within bounds and has not been visited, mark it as visited and push it into the queue.
   d. If the right jump index is within bounds and has not been visited, mark it as visited and push it into the queue.
4. If we exhaust all possibilities without finding an index with value 0, return false.
5. Return the result of the BFS search.

Time Complexity: O(n), where n is the length of the arr array. In the worst case, we may need to visit all indices in the array.
Space Complexity: O(n), since we are using a queue to keep track of the indices we can jump to and a vector to keep track of the visited indices, both of which can grow up to the size of the input array.
*/


class Solution {
public:
    bool canReach(vector<int>& arr, int start) 
    {
        int n=arr.size();
        queue<int>q; 
        vector<int>vis(n,0);
        q.push(start);
        vis[start]=1;
        while(!q.empty())
        {
            auto tp=q.front();
            q.pop(); 
            int l=tp-arr[tp];
            int r=tp+arr[tp];
            if(!arr[tp])return 1;
            if(l>=0&&!vis[l]){
                vis[l]=1;
                q.push(l); 
            }
            if(r<n&&!vis[r])
            {
                vis[r]=1;
                q.push(r); 
            }
        } 
        return 0;
    }
};