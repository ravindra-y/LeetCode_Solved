class Solution {
public:
    int numSplits(string s) {
        unordered_map<char, int> left, right;
        
        for (char c : s) {
            right[c]++;
        }
        
        int goodSplits = 0;
        
        for (int i = 0; i < (int)s.size() - 1; i++) {
            char c = s[i];
            
            left[c]++;
            right[c]--;
            
            if (right[c] == 0) {
                right.erase(c);
            }
            
            if (left.size() == right.size()) {
                goodSplits++;
            }
        }
        
        return goodSplits;
    }
};