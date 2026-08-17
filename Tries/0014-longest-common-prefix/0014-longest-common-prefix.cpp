class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string last = strs.back();
        string res = "";
        
        for(int i = 0; i < min(first.size(), last.size()); i++) {
            if(first[i] != last[i]) return res;
            res += first[i];
        }
        return res;
    }
};