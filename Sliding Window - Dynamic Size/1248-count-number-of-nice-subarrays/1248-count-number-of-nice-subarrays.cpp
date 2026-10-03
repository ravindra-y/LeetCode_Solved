class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int oddCount = 0;
        int count = 0;
        int result = 0;

        int i = 0, j = 0;

        while (j < n) {

            // Add nums[j] to the window
            if (nums[j] % 2 != 0) {
                oddCount++;
                count = 0;
            }

            // Remove elements until we have fewer than k odds
            while (oddCount == k) {
                count++;

                if (nums[i] % 2 != 0) {
                    oddCount--;
                }

                i++;
            }

            // count = number of valid subarrays ending at j
            result += count;

            j++;
        }

        return result;
    }
};