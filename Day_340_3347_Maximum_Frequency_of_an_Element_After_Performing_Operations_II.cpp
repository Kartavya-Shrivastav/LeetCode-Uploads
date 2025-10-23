class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        
        sort(nums.begin(),nums.end());

        int size=nums.size();

        int left=0;
        int right=left;
        int sumCount=0;
        int result=0;
        int left2=0;
        int sumCount2=0;
        int count=0;
        int prev=-1;

        for(auto num : nums)
        {
            if(num==prev)
            {
                count++;
            }
            else
            {
                prev=num;
                count=1;
            }

            while(nums[left]<num-k)
            {
                sumCount--;
                left++;
            }

            while(right<size&&nums[right]<=num+k)
            {
                sumCount++;
                right++;
            }
            result=max(result,count+min(sumCount-count,numOperations));

            sumCount2++;
            while(nums[left2]<num-2*k)
            {
                sumCount2--;
                left2++;
            }
            result=max(result,min(sumCount2,numOperations));
        }

        return result;
    }
};