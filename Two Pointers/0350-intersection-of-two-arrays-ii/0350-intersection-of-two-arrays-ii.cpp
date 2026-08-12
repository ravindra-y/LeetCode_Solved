class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // Optimization: Ensure nums1 is the smaller array to save space
        if (nums1.size() > nums2.size()) {
            return intersect(nums2, nums1);
        }

        unordered_map<int, int> counts;
        // Step 1: Count frequencies of each number in the smaller array
        for (int num : nums1) {
            counts[num]++;
        }

        vector<int> result;
        // Step 2: Iterate through the second array
        for (int num : nums2) {
            if (counts.count(num) && counts[num] > 0) {
                result.push_back(num);
                counts[num]--; // Decrement to handle duplicates
            }
        }

        return result;
    }
};