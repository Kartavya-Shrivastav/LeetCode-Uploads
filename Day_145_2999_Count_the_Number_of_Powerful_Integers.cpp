#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    long long numberOfPowerfulInt(long long start, long long finish, int limit, std::string s) {
        string numStr = std::to_string(start - 1);
        long long memo[20];
        memset(memo, -1, sizeof(memo));

        function<long long(int, bool)> dfs = [&](int pos, bool isLimited) -> long long {
            if (numStr.size() < s.size()) {
                return 0;
            }
            if (!isLimited && memo[pos] != -1) {
                return memo[pos];
            }
            if (numStr.size() - pos == s.size()) {
                return isLimited ? s <= numStr.substr(pos) : 1;
            }
            long long count = 0;
            int upper = std::min(isLimited ? numStr[pos] - '0' : 9, limit);
            for (int i = 0; i <= upper; ++i) {
                count += dfs(pos + 1, isLimited && i == (numStr[pos] - '0'));
            }
            if (!isLimited) {
                memo[pos] = count;
            }
            return count;
        };

        long long countStart = dfs(0, true);

        numStr = std::to_string(finish);
        memset(memo, -1, sizeof(memo));

        long long countFinish = dfs(0, true);

        return countFinish - countStart;
    }
};