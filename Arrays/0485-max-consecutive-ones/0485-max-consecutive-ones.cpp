class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCon = 0;
        int count = 0;

        for (int num : nums) {
            if (num == 1) {
                count++;
            } else {
                count = 0;
            }

            maxCon = max(count, maxCon);
        }

        return maxCon;
    }
};