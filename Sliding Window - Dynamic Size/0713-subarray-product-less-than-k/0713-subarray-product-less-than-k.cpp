class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // all elements >= 1, so product can never be < 1
        if (k <= 1) return 0;

        int count = 0, left = 0;
        long long prod = 1; // long long to avoid overflow

        for (int right = 0; right < nums.size(); right++) {
            prod *= nums[right]; // expand window: include right element

            while (prod >= k) {  // shrink window until product < k
                prod /= nums[left++];
            }

            count += right - left + 1; // add all valid subarrays ending at right
        }

        return count;
    }
};