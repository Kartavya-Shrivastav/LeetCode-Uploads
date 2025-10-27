#include <bits/stdc++.h>
using namespace std;

// Problem: 2125. Number of Laser Beams in a Bank   
// Approach: Iterate through each row, count the number of security devices ('1's), and calculate the laser beams between consecutive rows with devices.

// Steps:
// 1. Initialize counters for the current row's devices and the previous row's devices.
// 2. Loop through each row of the bank.
// 3. For each row, count the number of '1's (security devices).
// 4. If the current row has devices, calculate the laser beams formed with the previous row and update the previous row's count.
// 5. Return the total number of laser beams.

// Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the bank.
// Space Complexity: O(1), as we are using a constant amount of extra space.

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int cnt = 0;
        int prev = 0;
        int ans = 0;
        for (int i = 0; i < bank.size(); i++){
            cnt = 0;

            for (char c : bank[i]){
                if (c == '1'){
                    cnt++;
                }
            }

            if (cnt > 0){
                ans += cnt * prev;
                prev = cnt;
            }
        }
        return ans;
    }
};