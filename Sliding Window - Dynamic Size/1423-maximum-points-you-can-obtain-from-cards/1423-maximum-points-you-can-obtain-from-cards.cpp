class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int windowSize = n - k;

        int totalSum = 0;
        for (int x : cardPoints) totalSum += x;

        // Find minimum sum of a contiguous window of size (n - k)
        int windowSum = 0;
        for (int i = 0; i < windowSize; i++)
            windowSum += cardPoints[i];

        int minWindowSum = windowSum;
        for (int i = windowSize; i < n; i++) {
            windowSum += cardPoints[i] - cardPoints[i - windowSize];
            minWindowSum = min(minWindowSum, windowSum);
        }

        return totalSum - minWindowSum;
    }
};