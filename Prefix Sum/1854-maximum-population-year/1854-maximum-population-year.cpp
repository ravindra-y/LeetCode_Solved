class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int delta[101] = {};

        for (auto& log : logs) {
            delta[log[0] - 1950]++;
            delta[log[1] - 1950]--;
        }

        int maxPop = 0, curr = 0, ans = 1950;

        for (int i = 0; i < 101; i++) {
            curr += delta[i];
            
            if (curr > maxPop) {
                maxPop = curr;
                ans = 1950 + i;
            }
        }

        return ans;
    }
};