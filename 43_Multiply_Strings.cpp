#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0"; // Edge case
        
        int m = num1.size(), n = num2.size();
        vector<int> result(m + n, 0);
        
        // Reverse loop for multiplication
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];
                
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }
        
        // Convert result array to string
        string ans = "";
        for (int num : result) {
            if (!(ans.empty() && num == 0)) ans += (num + '0'); // Avoid leading zeros
        }
        
        return ans.empty() ? "0" : ans;
    }
};
