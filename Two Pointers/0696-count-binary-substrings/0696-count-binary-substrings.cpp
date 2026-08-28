class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0, prev = 0, cur = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                cur++;
            } else {
                ans += min(prev, cur);
                prev = cur;
                cur = 1;
            }
        }
        ans += min(prev, cur);
        return ans;
    }
};