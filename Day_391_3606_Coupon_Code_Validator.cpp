#include <bits/stdc++.h>
using namespace std;

// Problem: Coupon Code Validator
// Approach: Validate coupon codes based on activity status and business line, then sort and return valid codes.

// Steps:
// 1. Iterate through the list of coupon codes along with their business lines and activity status.
// 2. Check if each coupon code is active and belongs to one of the specified business lines.
// 3. Validate the format of each coupon code to ensure it contains only allowed characters (letters, digits, underscores).
// 4. Store valid coupon codes in a map categorized by business line.
// 5. Sort the valid coupon codes within each business line and compile the final list in the specified order.

// Complexity Analysis:
// - Time Complexity: O(N log N) where N is the number of coupon codes, due to sorting the valid codes.
// - Space Complexity: O(N) for storing valid coupon codes.

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<string> ans;
        vector<string> categ={"electronics", "grocery", "pharmacy", "restaurant"};
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<n;i++){
            if(!isActive[i])continue;
            if(businessLine[i]!=categ[0]&&businessLine[i]!=categ[1]&&businessLine[i]!=categ[2]&&businessLine[i]!=categ[3])continue;
            int f=1;
            if(code[i].size()==0)continue;
            for(int j=0;j<code[i].size();j++){
                if(!((code[i][j]=='_' ) || (code[i][j]-'a'<26&&code[i][j]-'a'>=0) || (code[i][j]-'A'<26&&code[i][j]-'A'>=0) || (code[i][j]-'0'<=9&&code[i][j]-'0'>=0))){
                    f=-1;
                    break;
                }
            }
            if(f==-1)continue;
            mp[businessLine[i]].push_back(code[i]);
        }
        for(int i=0;i<4;i++){
            auto it = mp.find(categ[i]);
            if(it == mp.end())continue;
            sort(it->second.begin(),it->second.end());
            for(int j=0;j<it->second.size();j++){
                ans.push_back(it->second[j]);
            }
        }
        return ans;
    }
};