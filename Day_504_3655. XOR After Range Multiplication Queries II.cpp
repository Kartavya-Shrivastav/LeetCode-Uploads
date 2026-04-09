#include <bits/stdc++.h>
using namespace std;

/*
Problem: We are given an array of integers and a list of queries. Each query consists of four integers (l, r, k, v) where l and r define a range in the array, k is a step size, and v is a value to multiply. For each query, we need to multiply every k-th element in the range [l, r] by v and then compute the XOR of all elements in the array after processing all queries.
Approach: We can optimize the processing of queries by categorizing them based on the step size k. For large k, we can directly apply the multiplication to the relevant elements. For small k, we can use a difference array to efficiently apply the multiplications and their inverses, which allows us to handle multiple queries with the same k in a single pass.

Steps:
1. Iterate through each query and categorize them based on the step size k.
2. For queries with large k, directly apply the multiplication to the relevant elements in the array.
3. For queries with small k, use a difference array to apply the multiplications and their inverses efficiently.
4. After processing all queries, compute the XOR of all elements in the array to get the final result.

Time Complexity: O(n * sqrt(n) + q) where n is the size of the array and q is the number of queries. The large k queries are processed in O(q * (r - l) / k) which is efficient for large k, while small k queries are processed in O(n * sqrt(n)).
Space Complexity: O(n) for the difference array used in processing small k queries, and O(1) for other variables.
*/

class Solution {
public:
    const int mod = 1e9 + 7;
    long long power(long long base, long long exp){
        long long res = 1;
        while(exp > 0){
            if(exp & 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }

    long long modInv(long long n){
        return power(n, mod - 2);
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int limit = sqrt(n);
        
        // group queries with small k for later processing
        unordered_map<int, vector<vector<int>>> lightK;

        for(auto& q : queries){
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if(k >= limit){ // large k: apply brute force
                for(int i = l; i <= r; i += k)
                    nums[i] = (1LL * nums[i] * v) % mod;
            } else { // small k: process later
                lightK[k].push_back(q);
            } 
        }

        for(auto& [k, query] : lightK){
            // process small queries grouped by step size k
            vector<long long> diff(n, 1);
            for(auto& q : query){
                int l = q[0], r = q[1], v = q[3];
                // multiply starting position
                diff[l] = (diff[l] * v) % mod;
                // cancel the multiplication using modular inverse
                int steps = (r - l) / k;
                int next = l + (steps + 1) * k;
                if(next < n){
                    diff[next] = (diff[next] * modInv(v)) % mod;
                }
            }
            
            // propagate the multipliers with a step size of k
            for(int i = 0; i < n; i++){
                if(i >= k) diff[i] = (diff[i] * diff[i-k]) % mod;
                nums[i] = (1LL * nums[i] * diff[i]) % mod;
            }
        }

        int ans = 0;
        for(auto& num : nums) ans ^= num;

        return ans;    
    }
};