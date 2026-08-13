class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            // Ensure mid is even to check the pair (mid, mid + 1)
            if (mid % 2 == 1) mid--;
            
            // If pair is intact, single element is on the right
            if (nums[mid] == nums[mid + 1]) left = mid + 2;
            // Otherwise, it's on the left
            else right = mid;
        }
        return nums[left];
    }
};