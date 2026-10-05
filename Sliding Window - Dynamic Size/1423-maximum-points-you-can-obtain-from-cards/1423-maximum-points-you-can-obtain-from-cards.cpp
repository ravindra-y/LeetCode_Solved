class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int windowSize = n - k;

        // Compute total sum of all cards
        int totalSum = 0;
        for (int point : cardPoints) {
            totalSum += point;
        }

        // Edge case: take all cards
        if (windowSize == 0)
            return totalSum;

        // Compute sum of the first window
        int windowSum = 0;
        for (int i = 0; i < windowSize; i++) {
            windowSum += cardPoints[i];
        }

        int minWindowSum = windowSum;

        // Slide the window across the array
        for (int i = windowSize; i < n; i++) {
            windowSum += cardPoints[i] - cardPoints[i - windowSize];
            minWindowSum = min(minWindowSum, windowSum);
        }

        return totalSum - minWindowSum;
    }
};