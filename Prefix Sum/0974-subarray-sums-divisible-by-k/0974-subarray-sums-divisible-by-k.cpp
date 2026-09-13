class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> count(k, 0);
        count[0] = 1;

        int result = 0, sum = 0;

        for (int n : nums) {
            sum += n;
            int rem = (sum % k + k) % k;
            result += count[rem]++;
        }

        return result;
    }
};