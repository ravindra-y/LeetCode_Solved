class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int maxWater = 0;

        while (i < j) {
            int length = min(height[i], height[j]);
            int width = j - i;
            int currWater = length * width;

            maxWater = max(maxWater, currWater);

            if (height[i] > height[j]) {
                j--;
            } else {
                i++;
            }
        }

        return maxWater;
    }
};