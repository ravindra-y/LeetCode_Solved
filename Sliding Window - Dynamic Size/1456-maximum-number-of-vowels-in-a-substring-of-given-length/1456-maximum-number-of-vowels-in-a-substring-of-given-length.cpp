class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    int maxVowels(string s, int k) {
        int curr = 0;

        // First window
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) curr++;
        }

        int maxVowel = curr;

        // Sliding window
        for (int i = k; i < s.length(); i++) {
            if (isVowel(s[i])) curr++;  // add new char

            if (isVowel(s[i - k])) curr--;  // remove old char

            maxVowel = max(maxVowel, curr);
        }

        return maxVowel;
    }
};