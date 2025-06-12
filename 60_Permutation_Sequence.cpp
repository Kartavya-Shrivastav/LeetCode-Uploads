class Solution {
public:
    int fact( int n){
        if( n ==0 || n==1)return 1;
        int ans =1;
        while(n>0){
            ans = ans*n;
            n--;
        }
        return ans;
    }
    string getPermutation(int n, int k) {
        //total would be n factorial 
        // for first ele there would be (n-1)! choices 
        // similarly for the second ele there would be (n-2)! choices 
        string ans ="";
        vector<int>nums;
        for( int i=0;i<n;i++){
            nums.push_back(i+1);
        }
        int a=n;
        k--;
        for( int i=0;i<a;i++){
            // i denotes the position
            // for this pos we have (n-i-1 choices)
            int choices = fact(n-i-1);
            int q= (k/choices);
            ans+=to_string(nums[q]);
            nums.erase(nums.begin()+(q));
            k=k%choices;
        }
        return ans;
    }
};