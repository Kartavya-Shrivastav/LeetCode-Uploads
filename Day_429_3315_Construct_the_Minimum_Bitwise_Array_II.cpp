class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> answer(nums.size());
        for (int i = 0; i < answer.size(); i++) {
            int k = nums[i], n = 1, ans = -1; 

            while ((k & n) != 0) {
                ans = k - n;
                n <<= 1;
            }

            answer[i] = ans;
        }

        return answer;
    }
};
