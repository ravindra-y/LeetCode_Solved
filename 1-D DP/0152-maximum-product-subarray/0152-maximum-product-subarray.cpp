class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int curMax = nums[0];
        int curMin = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            // A negative number flips max and min
            if (nums[i] < 0) {
                swap(curMax, curMin);
            }

            // Either extend the subarray or start fresh
            curMax = max(nums[i], curMax * nums[i]);
            curMin = min(nums[i], curMin * nums[i]);

            result = max(result, curMax);
        }

        return result;
    }
};