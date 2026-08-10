class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int num : nums) {
            mp[num]++;
        }

        int result = 0;

        for (auto n : mp) {
            result += (n.second * (n.second - 1)) / 2;
        }

        return result;
    }
};