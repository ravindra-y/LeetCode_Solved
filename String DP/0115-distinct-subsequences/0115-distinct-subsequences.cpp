class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        if (m < n) return 0;

        vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1;  // empty t matches any prefix of s

        for (int i = 1; i <= m; i++) {
            // Traverse backwards to use values from the previous row
            for (int j = n; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
                // else: dp[j] stays the same (equivalent to dp[i-1][j])
            }
        }

        return (int)dp[n];
    }
};