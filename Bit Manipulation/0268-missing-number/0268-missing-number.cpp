class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xorVal = 0;

        for (int i = 0; i < n; i++) {
            xorVal = xorVal ^ (i + 1) ^ nums[i];
        }

        return xorVal;
    }
};