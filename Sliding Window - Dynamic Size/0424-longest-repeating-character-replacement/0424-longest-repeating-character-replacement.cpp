class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0); // Frequency map for uppercase letters
        int left = 0;
        int max_freq = 0;
        int max_len = 0;

        for (int right = 0; right < s.length(); ++right) {
            // 1. Expand: Add s[right] into the window state
            count[s[right] - 'A']++;
            max_freq = max(max_freq, count[s[right] - 'A']);

            // 2. Shrink: While condition is INVALID
            // (Replacements needed > k)
            while ((right - left + 1) - max_freq > k) {
                count[s[left] - 'A']--;
                left++;
            }

            // 3. Update Result: Window is guaranteed to be valid here
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};