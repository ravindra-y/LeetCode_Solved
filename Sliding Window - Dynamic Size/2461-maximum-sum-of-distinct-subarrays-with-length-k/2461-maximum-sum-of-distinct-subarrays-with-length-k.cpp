class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        long long sum = 0, maxSum = 0;

        for (int i = 0; i < n; i++) {
            // Add the current element to the window
            freq[nums[i]]++;
            sum += nums[i];

            // Shrink window if it exceeds size k
            if (i >= k) {
                freq[nums[i - k]]--;
                if (freq[nums[i - k]] == 0) {
                    freq.erase(nums[i - k]);
                }

                sum -= nums[i - k];
            }

            // Window is exactly size k and all elements are distinct
            if (i >= k - 1 && (int)freq.size() == k) {
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};