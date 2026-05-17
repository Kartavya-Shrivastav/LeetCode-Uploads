class Solution {
public:
    bool canReach(vector<int>& arr, int start) 
    {
        int n=arr.size();
        queue<int>q; 
        vector<int>vis(n,0);
        q.push(start);
        vis[start]=1;
        while(!q.empty())
        {
            auto tp=q.front();
            q.pop(); 
            int l=tp-arr[tp];
            int r=tp+arr[tp];
            if(!arr[tp])return 1;
            if(l>=0&&!vis[l]){
                vis[l]=1;
                q.push(l); 
            }
            if(r<n&&!vis[r])
            {
                vis[r]=1;
                q.push(r); 
            }
        } 
        return 0;
    }
};