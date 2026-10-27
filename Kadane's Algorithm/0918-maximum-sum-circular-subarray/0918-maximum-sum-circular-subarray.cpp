class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int maxSum = INT_MIN, curMax = 0;
        int minSum = INT_MAX, curMin = 0;
        
        for (int num : nums) {
            totalSum += num;
            
            curMax = max(curMax + num, num);
            maxSum = max(maxSum, curMax);
            
            curMin = min(curMin + num, num);
            minSum = min(minSum, curMin);
        }
        
        if (maxSum < 0) return maxSum;
        
        return max(maxSum, totalSum - minSum);
    }
};