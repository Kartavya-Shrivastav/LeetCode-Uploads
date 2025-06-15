class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        int carry=0;
        string ans="";
        int i=s1.size()-1;
        int j=s2.size()-1;
        while(i>=0 ||j>=0){
            int sum=0;
            if(i>=0 && s1[i]=='1')
            sum++;
            if(j>=0 && s2[j]=='1')
            sum++;
            if(sum +carry ==0){
                ans+='0';
                carry=0;
            }
            else if(sum +carry ==1){
                 ans+='1';
                carry=0;
            }
            else if(sum +carry ==2){
                 ans+='0';
                carry=1;
            }
            else if(sum +carry ==3){
                 ans+='1';
                carry=1;
            }
            i--;
            j--;
        }
        if(carry==1)
        ans+=to_string(carry);
        reverse(ans.begin(),ans.end());
        i=0;
        while(ans[i]=='0'){
            ans.erase(0,1);
        }
        return ans;
    }
};
