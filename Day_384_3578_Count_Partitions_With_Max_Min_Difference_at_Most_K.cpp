#include <bits/stdc++.h>
using namespace std;

// Problem: Count Partitions With Max-Min Difference at Most K
// Approach: Sliding Window with Monotonic Queues and Dynamic Programming

// Steps:
// 1. Use two monotonic queues to maintain the maximum and minimum values in the current window.
// 2. Expand the right pointer of the window and update the queues accordingly.
// 3. If the difference between the maximum and minimum exceeds k, shrink the window from the left.
// 4. Use a dynamic programming array to count the number of valid partitions ending at each index.
// 5. Return the total count of valid partitions modulo 1e9+7.

// Time Complexity: O(n) where n is the size of the nums array
// Space Complexity: O(n) for the dynamic programming array

constexpr int N=5e4, mod=1e9+7;
int qMax[N], qMin[N];
int frontX, backX, frontN, backN;

class Solution {
public:
    static int countPartitions(vector<int>& nums, int k) {
        const int n=nums.size();

        //reset monotonic queue
        frontX=frontN=0;
        backX=backN=-1;

        long long cnt=0;
        int* sum=(int*)malloc((n+2)*sizeof(int));
        memset(sum, 0, sizeof(sum));
        sum[1]=1;

        for (int l=0, r=0; r<n; r++) {
            int x=nums[r];

            //maintain max queue
            while (backX>=frontX && nums[qMax[backX]]<=x) backX--;
            qMax[++backX]=r;

            //maintain min queue
            while (backN>=frontN && nums[qMin[backN]]>=x) backN--;
            qMin[++backN]=r;

            // shrink window
            while (nums[qMax[frontX]]-nums[qMin[frontN]]>k) {
                frontX+=(qMax[frontX]==l);
                frontN+=(qMin[frontN]==l);
                l++;
            }

            cnt=(mod+sum[r+1]-sum[l])%mod;
            sum[r+2]=(sum[r+1]+cnt)%mod;
        }
        return cnt;
    }
};