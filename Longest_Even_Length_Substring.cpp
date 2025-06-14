#include<bits/stdc++.h>
using namespace std;

// Function to find the longest even-length substring with equal sum of halves
// Returns the length of the longest even-length substring with equal sum of halves 

int main() {
    int t;
    cin>>t;
    while(t--)
    {
	    string str;
	    int left=0;
	    int c=0;
	    int right = 0;
	    int maxx=0;
	    cin>>str;
	    int n = str.length();
	    
	    if(n==1)
	    {
	         cout<<0<<endl;
	    }
	    
	    else{
	    for(int i=0;i<n;i++)
	    {
	        int j = i;
	        int k = i+1;
	        left=0;
	        right=0;
	        
	        while(j>=0 && k<n)
	        {
	            left += str[j]-'0';
	            right += str[k] - '0';
	            if(left==right)
	            {
	                maxx = max(maxx,k-j+1);
	            }
	            j--;
	            k++;
	        }
	    }
	    
	    cout<<maxx<<endl;
	    }
	    
    }
	return 0;
}