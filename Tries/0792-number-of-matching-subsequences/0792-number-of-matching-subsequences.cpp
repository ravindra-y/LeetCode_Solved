class Solution {
public:
    bool check(string& s, string word) {
        int i = 0, j = 0, n = s.size(), m = word.size();
        while (i < n && j < m) {
            if (s[i] == word[j]) {
                j++;
            }
            i++;
        }

        return (j == m);
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        int cnt = 0;
        map<string, int> mp;
        for (auto& word : words) {
            mp[word]++;
        }

        for (auto& p : mp) {
            if (check(s, p.first)) {
                cnt += (p.second);
            }
        }

        return cnt;
    }
};