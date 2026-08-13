class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> counts;
        int n = s.length();
        int maxCount = 0;
        char maxChar = 0;

        // Count frequencies using the hash table
        // Also keep track of the most frequent character
        for (char c : s) {
            counts[c]++;
            if (counts[c] > maxCount) {
                maxCount = counts[c];
                maxChar = c;
            }
        }

        // If the most frequent character exceeds the limit, return empty string
        if (maxCount > (n + 1) / 2) {
            return "";
        }

        string res = s;
        int index = 0;

        // Place the most frequent character at even indices first
        while (counts[maxChar] > 0) {
            res[index] = maxChar;
            index += 2;
            counts[maxChar]--;
        }

        // Remove the most frequent character from the hash table
        // so we don't process it again
        counts.erase(maxChar);

        // Iterate through the rest of the hash table
        for (auto& pair : counts) {
            char c = pair.first;
            int count = pair.second;

            while (count > 0) {
                // If we reach the end of the string, start over at index 1 (odd
                // indices)
                if (index >= n) {
                    index = 1;
                }
                res[index] = c;
                index += 2;
                count--;
            }
        }

        return res;
    }
};