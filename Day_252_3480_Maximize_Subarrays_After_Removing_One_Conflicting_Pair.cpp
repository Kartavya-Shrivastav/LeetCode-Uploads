class Solution {
public:
    long long maxSubarrays(const int n, vector<vector<int>>& cp) {
        vector<int> s(n + 1), s2(n + 1);
        for (auto& p : cp) {
            if (p[0] > p[1]) swap(p[0], p[1]);
            if (s[p[1]] < p[0]) {
                s2[p[1]] = s[p[1]];
                s[p[1]] = p[0];
            } else if (s2[p[1]] < p[0]) {
                s2[p[1]] = p[0];
            }
        }
        int m1 = 0, m2 = 0;
        int64_t ans = 0, delta = 0, md = 0;
        for (int i = 1; i <= n; ++i) {
            if (s[i] > 0) {
                if (s[i] > m1) {
                    m2 = max(m1, s2[i]);
                    m1 = s[i];
                    md = max(md, delta);
                    delta = 0;
                } else if (s[i] > m2) {
                    m2 = s[i];
                }
            }
            ans += i - m1;
            delta += m1 - m2;
        }
        return ans + max(md, delta);
    }
};