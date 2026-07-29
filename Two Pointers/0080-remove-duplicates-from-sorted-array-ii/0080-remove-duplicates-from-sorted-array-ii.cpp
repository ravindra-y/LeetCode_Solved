class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();

        // First two elements are always valid
        int writePos = 2;

        for (int i = 2; i < nums.size(); i++) {
            // Compare with element two positions back in result
            if (nums[i] != nums[writePos - 2]) {
                nums[writePos] = nums[i];
                writePos++;
            }
        }

        return writePos;
    }
};