class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());

            mp[key].push_back(s);
        }

        vector<vector<string>> ans;

        for (auto x : mp) {
            ans.push_back(x.second);
        }

        return ans;
    }
};

/*
Time Complexity: O(N * K) - Where N is the number of strings and K is the maximum length of a string.
Space Complexity: O(N * K) - For storing keys and grouped anagrams in the hash map.
*/
