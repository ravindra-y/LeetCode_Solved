class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int minVal = INT_MAX;
        bool hasOdd = false;

        for (int x : nums) {
            minVal = min(minVal, x);
            if (x & 1) hasOdd = true;
        }

        // Case 1: every element is already even  → uniform even
        // Case 2: global min is odd              → every even can subtract it → uniform odd
        return !hasOdd || (minVal & 1);
    }
};