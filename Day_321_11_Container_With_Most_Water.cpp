class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxcap = 0;
        int st=0 , ed = height.size()-1;
        while(ed>st){
            int temp = (ed-st)*(min(height[st] , height[ed]));
            maxcap = max(maxcap , temp);
            if(height[st]<height[ed]) st++;
            else ed--;
        }
        return maxcap;
    }
};