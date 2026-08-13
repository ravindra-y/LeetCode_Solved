class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (const string& s : strs) {
            int freq[26] = {};

            // Count frequency of each character
            for (char c : s) {
                freq[c - 'a']++;
            }
                
            // Build key using characters and their counts (e.g., "a1e1t1")
            string key;
            for (int i = 0; i < 26; ++i) {
                if (freq[i] > 0) {
                    key += char('a' + i) + to_string(freq[i]);
                }
            }

            groups[key].push_back(s);
        }

        // Collect all grouped anagrams into result
        vector<vector<string>> result;
        for (auto& [key, group] : groups) {
            result.push_back(move(group));
        }    

        return result;
    }
};

/*
Time Complexity: O(N * K) - Where N is the number of strings and K is the maximum length of a string.
Space Complexity: O(N * K) - For storing keys and grouped anagrams in the hash map.
*/