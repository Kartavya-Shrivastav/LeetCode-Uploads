#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);

        auto hammingDist = [](const string& s1, const string& s2) {
            if (s1.length() != s2.length()) return -1;
            int dist = 0;
            for (size_t i = 0; i < s1.length(); ++i) {
                if (s1[i] != s2[i]) ++dist;
            }
            return dist;
        };

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] &&
                    words[i].length() == words[j].length() &&
                    hammingDist(words[i], words[j]) == 1 &&
                    dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }

        int max_len = 0, last_idx = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] > max_len) {
                max_len = dp[i];
                last_idx = i;
            }
        }

        vector<string> result;
        while (last_idx != -1) {
            result.push_back(words[last_idx]);
            last_idx = prev[last_idx];
        }
        reverse(result.begin(), result.end());
        return result;
    }
};