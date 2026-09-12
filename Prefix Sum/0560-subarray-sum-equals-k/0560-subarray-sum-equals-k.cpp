class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_counts;
        prefix_counts[0] = 1;

        int current_sum = 0;
        int count = 0;

        for (int num : nums) {
            current_sum += num;
            int needed_sum = current_sum - k;

            if (prefix_counts.count(needed_sum)) {
                count += prefix_counts[needed_sum];
            }

            prefix_counts[current_sum]++;
        }

        return count;
    }
};