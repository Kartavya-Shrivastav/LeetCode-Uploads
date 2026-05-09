#include <bits/stdc++.h>
using namespace std;

/*
Problem: You are given a 0-indexed integer array nums of length n. The value of the i-th element of nums is the maximum jump length from that position (i.e., you can jump at most nums[i] steps forward from that position). You are initially positioned at index 0. Return the minimum number of jumps to reach the last index (index n - 1) if you can only jump to indices with prime numbers as values. If it is not possible to reach the last index, return -1. 
Approach: We can solve this problem using a breadth-first search (BFS) approach. We will use a queue to keep track of the indices we can jump to and an array to keep track of the minimum number of jumps required to reach each index. We will also use an array to keep track of the prime numbers and their corresponding indices in the nums array.    

Steps:
1. First, we will create an array to store the indices of the prime numbers in the nums array. We will iterate through the nums array and for each value, we will check if it is a prime number. If it is, we will store its index in the corresponding position in the head array and also keep track of the next indices for each prime number in the next array.
2. We will initialize a dp array to store the minimum number of jumps required to reach each index. We will set the value at index 0 to 0, since we are already at the starting position, and the rest of the values will be initialized to -1, indicating that they are not reachable yet.
3. We will use a queue to perform the BFS. We will start by pushing the index 0 into the queue.
4. We will continue the BFS until the queue is empty. For each index we pop from the queue, we will check if it is the last index. If it is, we will return the value in the dp array for that index, which represents the minimum number of jumps required to reach it.
5. If the current index is not the last index, we will check the indices we can jump to from the current index. We will check the right and left jumps (i.e., index + 1 and index - 1) and if they are within bounds and not visited yet (i.e., dp value is -1), we will update their dp values to be one more than the current index's dp value and push them into the queue.
6. If the value at the current index is a prime number, we will also check all the indices that have the same prime number as their value. We will iterate through these indices and if they are not visited yet, we will update their dp values and push them into the queue. We will also mark the prime number as visited to avoid processing it again in future iterations. 

Time Complexity: O(n * sqrt(m)), where n is the length of the nums array and m is the maximum value in the nums array, since we need to check for prime numbers up to the maximum value and also perform BFS on the indices.
Space Complexity: O(n + m), since we are using arrays to store the indices of prime numbers and the dp values, as well as a queue for BFS.
*/

class Solution {
    static const int n = 1000005;
    static inline int prime[n];
    static inline int version = 0;
    static inline bool init = []() {
        prime[0] = -1;
        prime[1] = -1;
        for (int i = 2; i <= 1000; i++)
            if (prime[i] == 0)
                for (int j = i * i; j < n; j += i)
                    prime[j] = -1;
        return true;
    }();

public:
    int minJumps(vector<int>& nums) {
        int len = nums.size();
        int max = *max_element(nums.begin(), nums.end());

        vector<int> head(max + 1, -1);
        vector<int> next(len);

        for (int i = 0; i < len; i++) {
            next[i] = head[nums[i]];
            head[nums[i]] = i;
        }

        vector<int> dp(len, -1);
        dp[0] = 0;

        queue<int> queue;
        queue.push(0);

        version++;

        while (!queue.empty()) {
            int dq = queue.front();
            queue.pop();

            if (dq == len - 1)
                return dp[dq];

            int right = dq + 1;
            if (right < len && dp[right] == -1) {
                dp[right] = dp[dq] + 1;
                queue.push(right);
            }

            int left = dq - 1;
            if (left >= 0 && dp[left] == -1) {
                dp[left] = dp[dq] + 1;
                queue.push(left);
            }

            int val = nums[dq];
            if (prime[val] != -1 && prime[val] != version) {
                prime[val] = version;
                for (int i = val; i <= max; i += val) {
                    for (int j = head[i]; j != -1; j = next[j]) {
                        if (dp[j] == -1) {
                            dp[j] = dp[dq] + 1;
                            queue.push(j);
                        }
                    }
                    head[i] = -1;
                }
            }
        }

        return -1;
    }
};