#include <bits/stdc++.h>
using namespace std;

// Function to convert a string to an integer (atoi implementation)
// This function takes a character pointer as input and returns the converted integer

class Solution {
  public:
    int myAtoi(char *s) {
        int i=0;
        long ans=0;
        int sign=1;
        while(s[i]==' '){
                i++;
            }
            if(s[i]=='-' || s[i]=='+'){
                sign=(s[i]=='-')?-1:1;
                i++;
            }
            while(s[i]>='0' && s[i]<='9'){
                ans=ans*10+(s[i]-'0');
                if(sign*ans>=INT_MAX) return INT_MAX;
                if(sign*ans<=INT_MIN) return INT_MIN;
                i++;
            }
            return (int)sign*ans;
    }
};