class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0;
        int index=0;
        int n=colors.size();
        int temp=0;
        int maxi=0;
        while(index<n)
        {
            maxi=0;
            temp=0;
            bool found=false;
            while(index<n-1 && colors[index]==colors[index+1])
            {
                found=true;
                temp=temp+neededTime[index];
                maxi=max(maxi,neededTime[index]);
                index++;
            }
            temp=temp+neededTime[index];
            maxi=max(maxi,neededTime[index]);
            
            if(found)
            {
                ans=ans+temp-maxi;
            }
            index++;
        }
        return ans;
    }
};