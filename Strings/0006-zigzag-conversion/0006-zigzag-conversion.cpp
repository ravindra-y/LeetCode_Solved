class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        vector<string> rows(numRows);
        int row = 0, dir = -1;
        
        for (char c : s) {
            if (row == 0 || row == numRows - 1) dir *= -1;
            rows[row] += c;
            row += dir;
        }
        
        string res;
        for (string& r : rows) res += r;
        return res;
    }
};