class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int maxLen = 0;
        int i = 0; // left pointer

        for (int j = 0; j < s.length(); j++) { // right pointer
            // Shrink window until the duplicate character s[j] is removed
            while (seen.count(s[j])) {
                seen.erase(s[i]);
                i++;
            }
            
            // Add current character to set
            seen.insert(s[j]);
            
            // Update max length with the current window size
            maxLen = max(maxLen, j - i + 1);
        }

        return maxLen;
    }
};