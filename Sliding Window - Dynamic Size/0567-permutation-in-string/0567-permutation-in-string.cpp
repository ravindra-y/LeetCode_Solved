class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1Len = s1.length();
        int s2Len = s2.length();

        if (s1Len > s2Len) return false;

        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);

        for (int i = 0; i < s1Len; i++) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        if (s1Count == s2Count) return true;

        for (int i = s1Len; i < s2Len; i++) {
            s2Count[s2[i] - 'a']++;         // new char enters window
            s2Count[s2[i - s1Len] - 'a']--; // old char leaves window

            if (s1Count == s2Count) return true;
        }

        return false;
    }
};