class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int n=arr.size();
        int count=0;
        int t=0,p=0;
        while(t<n && p<n)
        { 
            while(t<n && arr[t]!='T') ++t;
            while(p<n && arr[p]!='P') ++p;
            if(t<n && p<n && abs(t-p)<=k)
            {
                ++count;++p;++t;
            }
            else if(t<p) ++t;
            else ++p;
        }
        return count;
    }
};