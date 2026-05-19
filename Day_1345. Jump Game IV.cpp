#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given an array of non-negative integers arr, you are initially positioned at the first index of the array. In one step you can jump from index i to index:
- i + 1 where: i + 1 < arr.length.
- i - 1 where: i - 1 >= 0.
- j where: arr[i] == arr[j] and i != j.

Approach: We can solve this problem using a breadth-first search (BFS) algorithm. We will use a queue to keep track of the indices we can jump to and a bitset to keep track of the visited indices to avoid cycles. We will also use an unordered map to group indices by their values, which allows us to efficiently jump to all indices with the same value.

Steps:
1. Initialize a queue to keep track of the indices we can jump to and a bitset to keep track of the visited indices.
2. Create an unordered map to group indices by their values in the array.
3. Push the starting index (0) into the queue and mark it as visited.
4. While the queue is not empty:
   a. Pop the front index from the queue and check if it is the last index of the array. If it is, return the number of steps taken.
   b. Calculate the left and right jump indices based on the current index.
   c. If the left jump index is within bounds and has not been visited, mark it as visited and push it into the queue.
   d. If the right jump index is within bounds and has not been visited, mark it as visited and push it into the queue.
   e. For all indices that have the same value as the current index, if they have not been visited, mark them as visited and push them into the queue.
   f. Clear the list of indices for the current value in the unordered map to avoid redundant jumps in future iterations.
5. If we exhaust all possibilities without reaching the last index, return -1.

Time Complexity: O(n), where n is the length of the arr array. In the worst case, we may need to visit all indices in the array.
Space Complexity: O(n), since we are using a queue to keep track of the indices we can jump to, a bitset to keep track of the visited indices, and an unordered map to group indices by their values, all of which can grow up to the size of the input array.
*/

constexpr int N=5e4+1;
bitset<N> vis;
int q[N], front=0, back=0;

class Solution {
public:
    static int minJumps(vector<int>& arr) {
        const int n=arr.size();
        vis.reset();
        unordered_map<int, vector<int>> dict;
        dict.reserve(n);
        for(int i=0; i<n; i++) 
            dict[arr[i]].push_back(i);

        front=back=0;
        q[back++]=0;
        int step=0;
        while(front<back)
        {
            int s=back-front;
            while(s--)
            {
                int cur=q[front++];
                if (cur==n-1) return step;
                if(cur-1>=0 && !vis[cur-1]){
                    q[back++]=cur-1;
                    vis[cur-1]=1;
                }
                if(cur<=n && !vis[cur+1]){
                    q[back++]=cur+1;
                    vis[cur+1]=1;
                }
                for(int idx: dict[arr[cur]]){
                    if (!vis[idx]){
                        q[back++]=idx;
                        vis[idx]=1;
                    }
                }
                dict[arr[cur]].clear();
            }
            step++;
        }
        return -1;
    }
};