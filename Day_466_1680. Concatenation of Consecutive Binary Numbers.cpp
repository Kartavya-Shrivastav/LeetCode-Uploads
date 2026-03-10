class Solution {
public:
    const long long MOD = 1e9 + 7;

    int concatenatedBinary(int n) {

        long long result=0;
        int len=0;

        for(int i=1;i<=n;i++){
            if(!(i&(i-1))){
                len++;
            }
            result=(result<<len);
            result=(result | i )%MOD;


        }
        return result %MOD;
        
    }
};