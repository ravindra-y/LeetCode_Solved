class Solution {
public:
    int minDeletions(string s) {
        int freq[26] = {0};

        for (char c : s) {
            freq[c - 'a']++;
        }

        unordered_set<int> seenFreq;
        int deletions = 0;

        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0 && seenFreq.count(freq[i])) {
                freq[i]--;
                deletions++;
            }

            if (freq[i] > 0) {
                seenFreq.insert(freq[i]);
            }
        }

        return deletions;
    }
};