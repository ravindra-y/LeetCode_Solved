class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;

        stringstream ss(s);
        string token;

        int count = 0;
        while (getline(ss, token, ' ')) {
            words.push_back(token);
            count++;
        }

        int n = pattern.size();

        if (count != n) return false;

        unordered_map<string, char> mp;
        set<char> used;

        for (int i = 0; i < n; i++) {
            if (mp.find(words[i]) == mp.end() && used.find(pattern[i]) == used.end()) {
                used.insert(pattern[i]);
                mp[words[i]] = pattern[i];
            } else if (mp[words[i]] != pattern[i]) {
                return false;
            }
        }
        return true;
    }
};