class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.length() < p.length()) return {};

        vector<int> pCount(26, 0), windowCount(26, 0);
        vector<int> result;

        // Target frequencies
        for (char c : p) {
            pCount[c - 'a']++;
        }

        int left = 0;
        for (int right = 0; right < s.length(); right++) {
            // 1. Expand window to the right (add incoming character)
            windowCount[s[right] - 'a']++;

            // 2. Shrink window from the left if it gets larger than p.length()
            if (right - left + 1 > p.length()) {
                windowCount[s[left] - 'a']--;
                left++;
            }

            // 3. When window size matches p, check if frequencies match
            if (right - left + 1 == p.length() && windowCount == pCount) {
                result.push_back(left);
            }
        }

        return result;
    }
};