class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorAll = 0;

        for (int &num : nums) {
            xorAll ^= num;
        }

        // mask -> right most set bit search
        long long mask = xorAll & (-xorAll);

        int groupA = 0;
        int groupB = 0;

        for (int &num: nums) {
            if (num & mask) {
                groupA ^= num;
            } else {
                groupB ^= num;
            }
        }

        return {groupA, groupB};
    }
};