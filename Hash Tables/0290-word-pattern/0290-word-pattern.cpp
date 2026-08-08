class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;

        stringstream ss(s);
        string token;

        while (ss >> token) {
            words.push_back(token);
        }

        int n = pattern.length();

        if (n != words.size()) {
            return false;
        }

        unordered_map<string, char> mp;
        set<char> used;

        for (int i = 0; i < n; i++) {
            string word = words[i];
            char ch = pattern[i];

            if (mp.find(word) == mp.end()) {
                // This character is already assigned to another word
                if (used.find(ch) != used.end()) {
                    return false;
                }

                mp[word] = ch;
                used.insert(ch);
            }
            else {
                // Existing word must map to the same character
                if (mp[word] != ch) {
                    return false;
                }
            }
        }

        return true;
    }
};