class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);

        int prefix = 1, suffix = 1;

        for (int i = 0; i < n; i++) {
            result[i] *= prefix;
            prefix *= nums[i];

            result[n - 1 - i] *= suffix;
            suffix *= nums[n - 1 - i];
        }

        return result;
    }
};
