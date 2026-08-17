class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> groups;

        for (const string& s : strings) {
            string key;
            for (char c : s) {
                key += char((c - s[0] + 26) % 26 + 'a');
            }
            groups[key].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto& [_, group] : groups) {
            ans.push_back(group);
        }

        return ans;
    }
};