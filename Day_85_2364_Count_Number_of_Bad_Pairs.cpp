#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        std::unordered_map<int, int> count_map;
        long long bad_pairs_count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int diff = i - nums[i];
            bad_pairs_count += i - count_map[diff];
            ++count_map[diff];
        }
        return bad_pairs_count;
    }
};