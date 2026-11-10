class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0, minSum = 0;
        int curMax = 0, curMin = 0;

        for (int x : nums) {
            curMax = max(0, curMax + x);
            curMin = min(0, curMin + x);
            maxSum = max(maxSum, curMax);
            minSum = min(minSum, curMin);
        }

        return max(maxSum, -minSum); // -minSum == abs(minSum)
    }
};