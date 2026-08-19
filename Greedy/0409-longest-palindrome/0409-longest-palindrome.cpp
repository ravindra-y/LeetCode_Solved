class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;

        for (auto c : s) {
            mp[c]++;
        }

        int maxLen = 0;
        bool isLeft = false;

        for (auto x : mp) {
            int count = x.second;

            maxLen += (count / 2) * 2;

            if (count % 2 != 0) {
                isLeft = true;
            }
        }

        if (isLeft) {
            maxLen++;
        }

        return maxLen;
    }
};