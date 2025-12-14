#include <bits/stdc++.h>
using namespace std;

// Problem: Count Mentions Per User
// Approach: Sort events by time and process each event to count mentions based on user status.

// Steps:
// 1. Sort events based on the timestamp and user ID.
// 2. Initialize a vector to keep track of mentions for each user.
// 3. Iterate through each event and update the mention counts based on the type of event and user status.
// 4. Return the final counts of mentions for each user.

// Complexity Analysis:
// - Time Complexity: O(E log E + E * U) where E is the number of events and U is the number of users.  
// - Space Complexity: O(U) for storing the mention counts and online status.

#include<ranges>
class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        
        ranges::sort(events, {}, [](auto& e) {
            return pair(stoi(e[1]), e[0][2]);
        });

        vector<int> ans(numberOfUsers);
        vector<int> online_t(numberOfUsers);
        for (auto& e : events) {
            int cur_t = stoi(e[1]);
            string& mention = e[2];
            if (e[0][0] == 'O') {
                online_t[stoi(mention)] = cur_t + 60;
            } else if (mention[0] == 'A') {
                for (int& v : ans) {
                    v++;
                }
            } else if (mention[0] == 'H') {
                for (int i = 0; i < numberOfUsers; i++) {
                    if (online_t[i] <= cur_t) { 
                        ans[i]++;
                    }
                }
            } else {
                for (const auto& part : mention | ranges::views::split(' ')) {
                    string s(part.begin() + 2, part.end());
                    ans[stoi(s)]++;
                }
            }
        }
        return ans;
    }
};