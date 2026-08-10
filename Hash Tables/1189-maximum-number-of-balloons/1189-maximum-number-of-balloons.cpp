class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;

        for (char ch : text) {
            mp[ch]++;
        }

        int result = INT_MAX;

        string check = "balloon";

        for (char ch : check) {
            int required = 1;

            if (ch == 'l' || ch == 'o') {
                required = 2;
            }

            result = min(result, mp[ch] / required);
        }

        return result;
    }
};