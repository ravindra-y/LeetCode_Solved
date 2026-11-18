class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        // inc: max length of turbulent subarray ending at current index where arr[i] > arr[i-1]
        // dec: max length of turbulent subarray ending at current index where arr[i] < arr[i-1]
        int inc = 1;
        int dec = 1;
        int maxLen = 1;

        for (int i = 1; i < n; ++i) {
            if (arr[i] > arr[i - 1]) {
                // To keep alternating, an UP (> ) step must follow a DOWN (<) step
                inc = dec + 1;
                dec = 1;
            } else if (arr[i] < arr[i - 1]) {
                // To keep alternating, a DOWN (<) step must follow an UP (>) step
                dec = inc + 1;
                inc = 1;
            } else {
                // If elements are equal, reset both streaks to 1
                inc = 1;
                dec = 1;
            }
            maxLen = max(maxLen, max(inc, dec));
        }

        return maxLen;
    }
};