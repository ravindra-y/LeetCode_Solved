class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> result;

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Fix the 1st element
        for (int i = 0; i < n; i++) {
            // Skip duplicates for i
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Step 3: Fix the 2nd element
            for (int j = i + 1; j < n; j++) {
                // Skip duplicates for j
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // Step 4: Two pointers for the remaining two
                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;

                        // Skip duplicates for left
                        while (left < right && nums[left] == nums[left - 1]) left++;
                        // Skip duplicates for right
                        while (left < right && nums[right] == nums[right + 1]) right--;

                    } else if (sum < target) {
                        left++; // need a bigger sum
                    } else {
                        right--; // need a smaller sum
                    }
                }
            }
        }

        return result;
    }
};