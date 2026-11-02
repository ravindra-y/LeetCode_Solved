class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0, minSum = 0;
        int curMax = 0, curMin = 0;

        for (int x : nums) {
            curMax = max(x, curMax + x);   // Kadane for max
            maxSum = max(maxSum, curMax);

            curMin = min(x, curMin + x);   // Kadane for min
            minSum = min(minSum, curMin);
        }

        return max(maxSum, -minSum);
    }
};