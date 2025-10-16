static constexpr int mod = 1e9 + 7;
static int C[31][31];
static int dp[51][31][31][31];
class Solution {
public:
    void init() {
        if (C[0][0] == 1) {
            return;
        }
        for (int i = 0; i < 31; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; j++) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
            }
        }
    }
    int magicalSum(int m, int k, vector<int>& nums) {
        int n = nums.size();
        init();
        memset(dp, 0, sizeof(dp));
        dp[0][0][0][0] = 1;
        vector<vector<int>> pw(n, vector<int>(m + 1, 1));
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= m; j++) {
                pw[i][j] = 1LL * pw[i][j - 1] * nums[i] % mod;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int bits = 0; bits <= k; bits++) {
                    for (int carry = 0; carry <= m; carry++) {
                        if (dp[i][j][bits][carry] == 0) {
                            continue;
                        }
                        for (int v = 0; v + j <= m; v++) {
                            int nbits = bits + ((carry + v) & 1);
                            int ncarry = (v + carry) >> 1;
                            if (i == n - 1) {
                                nbits += __builtin_popcount(ncarry);
                                ncarry = 0;
                                if (nbits > k) {
                                    continue;
                                }
                            }
                            dp[i + 1][v + j][nbits][ncarry] += 1LL * dp[i][j][bits][carry] * C[m - j][v] % mod * pw[i][v] % mod;
                            dp[i + 1][v + j][nbits][ncarry] %= mod;
                        }
                    }
                }
            }
        }
        return dp[n][m][k][0];
    }
};