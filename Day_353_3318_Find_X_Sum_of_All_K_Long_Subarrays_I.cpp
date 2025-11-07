class Solution {
public:
    int xsum( int count[], int x)
    {
        int sum = 0;
        while( x > 0)
        {
            int maxc = 0;
            int temp ;
            for( int i = 0; i < 51; i++)
            {
                if( maxc <= count[i])
                {
                    maxc = count[i];
                    temp = i;
                }
            }
            if( maxc == 0)
            {
                break;
            }
            else
            {
                while( count[temp] != 0)
                {
                    sum = sum + temp;
                    count[temp]--;
                }
            }
            x--;
        }
        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int end = 0; 
        int start = k - 1;
        vector <int> ans;
        while( start < n)
        {
            int count[51] = {0};
            for( int i = end; i <= start; i++)
            {
                count[nums[i]]++;
            }
            int sum = xsum(count , x);
            ans.push_back(sum);
            start ++;
            end ++;
        }
        return ans;
    }
};