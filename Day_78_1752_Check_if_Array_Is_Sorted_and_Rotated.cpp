#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool check(vector<int>& arr) {
        int count = 0;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            if (arr[(i + 1) % n] < arr[i]) {
                count++;
            }
            
            if (count > 1) return false;
        }

        return true;
    }
};

