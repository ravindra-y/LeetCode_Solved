class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;

        while (i < j) {
            int sum = nums[i] + nums[j];

            if (sum < target) {
                i++;
            } else if (sum > target) {
                j--;
            } else {
                return {i+1, j+1};
            }
        }

        return {};
    }
};