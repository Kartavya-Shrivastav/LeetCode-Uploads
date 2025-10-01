class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        sort(nums.begin(), nums.end(), std::greater<int>());

        for(int i=0;i<=n-3; i++){
            if(nums[i+1] + nums[i+2] > nums[i]){
                return nums[i+1] + nums[i+2] + nums[i];
            }           
        }
        return 0;
    }
};