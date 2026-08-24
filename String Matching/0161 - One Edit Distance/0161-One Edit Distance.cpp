class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        // Ensure 's' is always the shorter string
        if (m > n) {
            return isOneEditDistance(t, s);
        }
        
        // If the length difference is greater than 1, return false
        if (n - m > 1) {
            return false;
        }
        
        // Find the first character that doesn't match
        for (int i = 0; i < m; ++i) {
            if (s[i] != t[i]) {
                // If same length -> must be a REPLACE (rest of the strings must match)
                if (m == n) {
                    return s.substr(i + 1) == t.substr(i + 1);
                } 
                // If different length -> must be an INSERT (rest of s matches rest of t)
                else {
                    return s.substr(i) == t.substr(i + 1);
                }
            }
        }
        
        // If no mismatch was found, t must have exactly 1 extra character at the end
        return m + 1 == n;
    }
};
