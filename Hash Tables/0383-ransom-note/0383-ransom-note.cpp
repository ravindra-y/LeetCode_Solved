class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> charCounts;

        // Count every character in the magazine
        for (char c : magazine) {
            charCounts[c]++;
        }

        // Check if the ransomNote can be built
        for (char c : ransomNote) {
            // If character isn't found or count is 0
            if (charCounts[c] == 0) {
                return false;
            }
            charCounts[c]--;
        }

        return true;
    }
};