class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // Step 1: Insert all numbers into a hash set
        unordered_set<int> seen;
        for (int num : nums) {
            seen.insert(num);
        }

        vector<int> result;
        int n = nums.size();

        // Step 2: Check which numbers from 1 to n are missing
        for (int i = 1; i <= n; ++i) {
            if (seen.find(i) == seen.end()) {
                result.push_back(i);
            }
        }

        return result;
    }
};