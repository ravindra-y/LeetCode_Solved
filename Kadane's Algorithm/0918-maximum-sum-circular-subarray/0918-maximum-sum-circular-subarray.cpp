class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int maxSum = INT_MIN, curMax = 0;   // track max subarray
        int minSum = INT_MAX, curMin = 0;   // track min subarray
        
        for (int num : nums) {
            totalSum += num;                // sum of all elements
            
            curMax = max(curMax + num, num); // Kadane's for max
            maxSum = max(maxSum, curMax);
            
            curMin = min(curMin + num, num); // Kadane's for min
            minSum = min(minSum, curMin);
        }
        
        if (maxSum < 0) return maxSum;      // all negative case
        
        return max(maxSum, totalSum - minSum); // normal vs circular wrap
    }
};